#include <SPI.h>

#define SRAM1_CS 10
#define SRAM2_CS 9

#define SRAM_WRITE 0x02  // Write command
#define SRAM_READ  0x03  // Read command
#define MODE_BYTE  0x01  // Write Mode Register command
#define MODE_SEQUENTIAL 0x40  // Sequential mode bit

// ==================== 初期化 ====================
void setup() {
  Serial.begin(115200);
  SPI.begin();
  
  pinMode(SRAM1_CS, OUTPUT);
  pinMode(SRAM2_CS, OUTPUT);
  digitalWrite(SRAM1_CS, HIGH);
  digitalWrite(SRAM2_CS, HIGH);
  
  // 各SRAMをシーケンシャルモードに設定
  setSequentialMode(SRAM1_CS);
  setSequentialMode(SRAM2_CS);

  Serial.println("Ready to receive 128KB data...");
}

// ==================== メインループ ====================
void loop() {
  static uint32_t address = 0;
  static bool receiving = false;

  if (Serial.available() > 0 && !receiving) {
    receiving = true;
    Serial.println("Receiving started...");
    writeToSRAM();
    Serial.println("Done!");
    receiving = false;
  }
}

// ==================== シーケンシャルモード設定 ====================
void setSequentialMode(uint8_t csPin) {
  digitalWrite(csPin, LOW);
  SPI.transfer(MODE_BYTE);
  SPI.transfer(MODE_SEQUENTIAL);
  digitalWrite(csPin, HIGH);
}

// ==================== シリアル→SRAM書き込み ====================
void writeToSRAM() {
  const uint32_t totalSize = 128UL * 1024UL;  // 128KB
  uint32_t bytesWritten = 0;
  uint8_t buf[64]; // まとめて送るバッファ

  while (bytesWritten < totalSize) {
    int chunkSize = 0;

    // シリアルから受信
    while (chunkSize < sizeof(buf) && Serial.available() > 0) {
      buf[chunkSize++] = Serial.read();
    }

    // チップとアドレス決定
    if (chunkSize > 0) {
      uint8_t csPin;
      uint16_t addr;
      uint32_t addrInChip;

      for (int i = 0; i < chunkSize; i++) {
        uint32_t currentAddr = bytesWritten + i;

        if (currentAddr < 65536UL) {
          csPin = SRAM1_CS;
          addrInChip = currentAddr;
        } else {
          csPin = SRAM2_CS;
          addrInChip = currentAddr - 65536UL;
        }

        writeByteToSRAM(csPin, (uint16_t)addrInChip, buf[i]);
      }

      bytesWritten += chunkSize;

      // 進捗出力（1KBごと）
      if (bytesWritten % 1024 == 0) {
        Serial.print("Written: ");
        Serial.print(bytesWritten);
        Serial.println(" bytes");
      }
    }
  }
}

// ==================== SRAMへの1バイト書き込み ====================
void writeByteToSRAM(uint8_t csPin, uint16_t address, uint8_t data) {
  digitalWrite(csPin, LOW);
  SPI.transfer(SRAM_WRITE);
  SPI.transfer((address >> 8) & 0xFF);
  SPI.transfer(address & 0xFF);
  SPI.transfer(data);
  digitalWrite(csPin, HIGH);
}
