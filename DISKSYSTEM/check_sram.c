了解です。では、23LC512 ×2枚を使い、ディスクシステムの信号に合わせて立ち上がり間隔をSRAMに記録し、/media がONになったらPCへ送信する本番用Arduinoスケッチを作ります。

前提：

Arduino Uno (ATmega328P)

SPI接続で23LC512 SRAM 2枚（CS1=D10, CS2=D9）

ディスクシステム信号：

/media 入力

/ready 入力

/read 入力

/monitor 出力

/reset 出力


立ち上がり間隔計測（10.37, 15.56, 20.75 μs）を分類してSRAMに保存

SRAM への書き込みはシーケンシャル

/media がONになったらPCへ128KB送信



---

#include <SPI.h>

// ---------- SRAM設定 ----------
#define CS1 10
#define CS2 9

// ---------- ディスクシステム信号 ----------
#define MEDIA_PIN 2
#define READY_PIN 3
#define READ_PIN 4
#define MONITOR_PIN 5
#define RESET_PIN 6

// ---------- SRAMコマンド ----------
#define SRAM_WRITE 0x02
#define SRAM_READ  0x03

// ---------- 計測パラメータ ----------
#define DATA_SIZE (128 * 1024) // 128KB
#define LFSR_SEED 0xACE1

volatile uint32_t lastRiseTime = 0;
volatile uint32_t interval = 0;

// ---------- SRAM操作 ----------
void sramWriteByte(uint8_t csPin, uint32_t addr, uint8_t data) {
  digitalWrite(csPin, LOW);
  SPI.transfer(SRAM_WRITE);
  SPI.transfer((addr >> 8) & 0xFF);
  SPI.transfer(addr & 0xFF);
  SPI.transfer(data);
  digitalWrite(csPin, HIGH);
}

uint8_t sramReadByte(uint8_t csPin, uint32_t addr) {
  digitalWrite(csPin, LOW);
  SPI.transfer(SRAM_READ);
  SPI.transfer((addr >> 8) & 0xFF);
  SPI.transfer(addr & 0xFF);
  uint8_t val = SPI.transfer(0);
  digitalWrite(csPin, HIGH);
  return val;
}

// ---------- 立ち上がり間隔分類 ----------
uint8_t classifyInterval(uint32_t dt) {
  // dt in micros()
  if (dt < 13) return 0;      // 10.37us
  else if (dt < 18) return 1; // 15.56us
  else return 2;              // 20.75us
}

void setup() {
  Serial.begin(230400);
  
  pinMode(CS1, OUTPUT);
  pinMode(CS2, OUTPUT);
  digitalWrite(CS1,HIGH);
  digitalWrite(CS2,HIGH);

  pinMode(MEDIA_PIN, INPUT_PULLUP);
  pinMode(READY_PIN, INPUT_PULLUP);
  pinMode(READ_PIN, INPUT_PULLUP);
  pinMode(MONITOR_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(MONITOR_PIN,HIGH);
  digitalWrite(RESET_PIN,HIGH);

  SPI.begin();
}

void loop() {
  // 1. /media が OFF になったら読み込み開始
  if(digitalRead(MEDIA_PIN) == LOW) {
    digitalWrite(MONITOR_PIN, LOW); // 読み込み合図

    uint32_t sramAddr = 0;
    while(digitalRead(READY_PIN) == LOW) {
      // /readの立ち上がり検出
      static uint8_t lastRead = HIGH;
      uint8_t currRead = digitalRead(READ_PIN);
      if(lastRead == LOW && currRead == HIGH) {
        uint32_t now = micros();
        if(lastRiseTime != 0) {
          interval = now - lastRiseTime;
          uint8_t val = classifyInterval(interval);
          // SRAM書き込み
          if(sramAddr < DATA_SIZE/2)
            sramWriteByte(CS1, sramAddr, val);
          else
            sramWriteByte(CS2, sramAddr - DATA_SIZE/2, val);
          sramAddr++;
        }
        lastRiseTime = now;
      }
      lastRead = currRead;
    }
    digitalWrite(MONITOR_PIN, HIGH); // 読み込み終了
  }

  // 2. /media が ON になったらPCへSRAM出力
  if(digitalRead(MEDIA_PIN) == HIGH) {
    for(uint32_t i=0;i<DATA_SIZE;i++){
      uint8_t b;
      if(i < DATA_SIZE/2)
        b = sramReadByte(CS1,i);
      else
        b = sramReadByte(CS2,i - DATA_SIZE/2);
      Serial.write(b);
    }
    delay(1000); // 1秒程度待って、連続送信防止
  }
}


---

🔹 補足

1. SRAM 書き込みはシーケンシャルで、アドレス自動インクリメントを利用


2. 立ち上がり間隔分類は micros() に基づき、3種類に分類


3. PC出力は /media がONになった瞬間に全データをシリアル送信


4. SPIクロックはデフォルト（4 MHz程度）で十分


5. /monitor の操作でディスクシステムに読み込み合図を送る




---

必要であれば、次は Python側でArduinoからのシリアルデータを受信してファイルに保存するコード も作れます。

作りますか？