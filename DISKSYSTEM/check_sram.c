了解です 👍
では、Arduino から 23LC512 × 2 に対して、LFSR（線形帰還シフトレジスタ）で再現性のある擬似乱数を生成し、
各 SRAM にシーケンシャルモードで合計 128 KB（各 64 KB）書き込む完全スケッチを示します。


---

✅ 構成

SRAM: 23LC512 × 2
各チップ容量: 64 K × 8 bit（= 64 KB）

接続:

SPI共通線：MOSI, MISO, SCK

CS: CS1 = 10, CS2 = 9（例）


書き込み方式: Sequential Mode (シーケンシャルライト)

データ生成: LFSR（再現性のある乱数）

目的: 書き込みテスト



---

🧠 23LC512 シーケンシャル書き込み

モード設定コマンド：0x01（WRMR）

0x40：Sequential mode


書き込みコマンド：0x02

先頭アドレスを送信したあと、データを連続して送ると自動でアドレスが進む




---

💡 コード全体（完全版）

#include <SPI.h>

#define CS1 10
#define CS2 9

// LFSR用：再現性あり（16bit）
uint16_t lfsr = 0xACE1; // シード値（任意だが固定）
uint8_t lfsrNextByte() {
  uint8_t val = 0;
  for (uint8_t i = 0; i < 8; i++) {
    uint16_t bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
    lfsr = (lfsr >> 1) | (bit << 15);
    val = (val << 1) | (lfsr & 1);
  }
  return val;
}

void setSequentialMode(uint8_t csPin) {
  digitalWrite(csPin, LOW);
  SPI.transfer(0x01);     // WRMR
  SPI.transfer(0x40);     // Sequential mode
  digitalWrite(csPin, HIGH);
}

void sramSequentialWrite(uint8_t csPin, uint32_t length) {
  digitalWrite(csPin, LOW);
  SPI.transfer(0x02); // WRITEコマンド
  SPI.transfer(0x00); // アドレス上位
  SPI.transfer(0x00);
  SPI.transfer(0x00);

  for (uint32_t i = 0; i < length; i++) {
    SPI.transfer(lfsrNextByte());
  }
  digitalWrite(csPin, HIGH);
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));

  pinMode(CS1, OUTPUT);
  pinMode(CS2, OUTPUT);
  digitalWrite(CS1, HIGH);
  digitalWrite(CS2, HIGH);

  Serial.println("Setting sequential mode...");
  setSequentialMode(CS1);
  setSequentialMode(CS2);

  Serial.println("Writing to SRAM1...");
  sramSequentialWrite(CS1, 65536UL);

  Serial.println("Writing to SRAM2...");
  sramSequentialWrite(CS2, 65536UL);

  Serial.println("Done.");
}

void loop() {
}


---

🔍 解説

setSequentialMode()
→ 23LC512をシーケンシャルモードに変更。

sramSequentialWrite()
→ WRITEコマンドと先頭アドレス送信後、length バイト連続送信。
SRAM内部で自動インクリメントされるため、ループで SPI.transfer() を繰り返すだけでシーケンシャルライト。

lfsrNextByte()
→ LFSRで再現性ある8ビット乱数を生成（シード固定で毎回同じパターン）。



---

⏱️ 補足

もし書き込み速度が速すぎて安定しない場合は、
sramSequentialWrite()内で32バイトごとに短いウェイトを入れてもOKです：

if ((i & 31) == 31) delayMicroseconds(100);


---

このコードを実行すると、Arduinoが

SRAM1（64 KB）→ SRAM2（64 KB）へ

シーケンシャルモードで連続書き込みし、

再現性のあるランダムデータが書き込まれます。



---

必要なら次は**同じLFSRで読み込み検証（比較）**コードも出せます。
続けてそれも作りますか？