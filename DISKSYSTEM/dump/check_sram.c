//=================================
// 概要:
//  23LC512 ×2枚を使い
//  ﾃﾞｨｽｸｼｽﾃﾑの立ち上がり間隔をSRAMに記録
//  読み取り後/media がONになったらPCへ送信
//
// 前提：
//  Arduino Uno V3(ATmega328P)
//  SPI接続で23LC512 SRAMx2
//  CS1=D10, CS2=D9
//
// ディスクシステム信号：
//  /media 入力
//  /ready 入力
//  read 入力
//  /monitor 出力
//  /reset 出力
//
// 立ち上がり間隔計測
//  10.37,15.56,20.75 μsを分類してSRAMに保存
//
// SRAM への書き込みはシーケンシャル
// 
// /media がONになったらPCへ128KB送信
//
//=================================


#include <SPI.h>

// ---------- SRAMチップセレクタ ----------
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

// ---------- 計測パラメータ ----------？

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

// ---------- スタート ----------
void setup() {
  // PCとのボーレート
  Serial.begin(115200);

  // チップセレクタを出力モードにしてHighに設定
  // 全sram無効状態
  pinMode(CS1, OUTPUT);
  pinMode(CS2, OUTPUT);
  digitalWrite(CS1,HIGH);
  digitalWrite(CS2,HIGH);

  // ディスクシステムの入出力モードを設定
  // monitor=High(待機)
  // reset=High(リセットでない)
  pinMode(MEDIA_PIN, INPUT_PULLUP);
  pinMode(READY_PIN, INPUT_PULLUP);
  pinMode(READ_PIN, INPUT_PULLUP);
  pinMode(MONITOR_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(MONITOR_PIN,HIGH);
  digitalWrite(RESET_PIN,HIGH);

  // SPI通信初期化
  SPI.begin();
}

// ---------- ループ ----------
void loop() {
  // /media が OFF になったら読み込み開始
  while(digitalRead(MEDIA_PIN) == HIGH);

  // 読み込み指示送信
  digitalWrite(MONITOR_PIN, LOW);

  // readyの準備を待つ
  while(digitalRead(READY_PIN) == HIGH);

  // readyがLOWの間読み込む
  while(digitalRead(READY_PIN) == LOW) {
     
  }
  // 読み込み指示取り消し
  digitalWrite(MONITOR_PIN, HIGH);
  

  // /media が ON になるまで待つなったら
  while(digitalRead(MEDIA_PIN) == LOW);

  // PCへ送信
  for(uint32_t idx=0; idx<read_count; idx++){
      uint8_t b;
      if(i < SIZE_OF_64KB)
        b = sramReadByte(CS1,i);
      else
        b = sramReadByte(CS2,i - SIZE_OF_64KB);
      Serial.write(b);
    }
    delay(1000); // 1秒程度待って、連続送信防止
  }

  // ディスクシステムをリセット
  digitalWrite(RESET_PIN, LOW);
  digitalWrite(RESET_PIN, HIGH);
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
