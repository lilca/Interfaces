# ディスクフォーマット

## 構成

|||
|:-|:-:|
|ギャップ|0ビットで埋まる|
|ディスク情報ブロック|Disk info block|
|ギャップ|0ビットで埋まる|
|ファイル数ブロック||
|ギャップ|0ビットで埋まる|
|ファイルヘッダーブロック||
|ギャップ|0ビットで埋まる|
|ファイルデータブロック||
|ギャップ|0ビットで埋まる|
|:|:|
|ギャップ|0ビットで埋まる|
|ファイルヘッダーブロック||
|ギャップ|0ビットで埋まる|
|ファイルデータブロック||
|ギャップ|0ビットで埋まる|


## ブロック

### ディスク情報ブロック(Disk info block, Block 1)
|フィールド名|オフセット|長さ|説明|
|:-:|:-:|:-:|:-|
|0|1|Block code|$01 固定|
|1|14|Disk varification|ASCII文字で "*NINTENDO-HVC*"<br>これを見てBIOSが正しいディスクか判断する|
|15|1|Licensee code|メーカーコードみたいなもん|
|16|3|Game name|ASCII文字で(例えばゼルダは"ZEL")|
|19|1|Game type|$20 = ' ' : 通常ディスク<br>$45 = 'E' : イベントディスク<br>$4A = 'J' : 不明<br>$52 = 'R' : 値下げ版??<br>|
|20|1|Game version|最初は $00|
|21|1|Side number|$00=A面, $01=B面(片面の場合は$00)|
|22|1|Disk number|$00=1枚目(デフォ), $01=2枚目, .....|
|23|1|Disk Type(FMC)|$01=ブルーディスク,$00=それ以外のディスク|
|24|1|Unknown|$00 固定|
|25|1|Boot read file code|起動時に読み込むファイル番号|
|26|5|Unknown|$FF,$FF,$FF,$FF,$FF 固定|
|31|3|manifacturing Date|製造年月日(BCD)<br>1989/01/01=$89,$01,$01(西暦パターン)<br>1988/01/01=$63,$01,$01(昭和パターン)<br>1989/01/01=$01,$01,$01(平成パターン)<br>|
|||||

### ファイル数ブロック(File amount block, Block 2)
|フィールド名|オフセット|長さ|説明|
|:-:|:-:|:-:|:-|
|0|1|Block code|$02 固定|
|1|1|File amount|uint8_tと思っていいかな？|
|2|2|CRC|*1<br>FDSフォーマットでは省略|

### ファイルヘッダーブロック(File header block, Block 3)
|フィールド名|オフセット|長さ|説明|
|:-:|:-:|:-:|:-|
|0|1|Block code|$03 固定|
|1|1|File number||
|2|1|File ID|disk-read関数で指定されるID|
|3|8|File name|ASCII文字,大文字|
|11|2|File address|ロードされるアドレス(リトルエンディアン)|
|13|2|File size|(リトルエンディアン)|
|15|1|File type|0=プログラム(PRAM)<br>1=キャラクター(CRAM)<br>2=ネームテーブル(VRAM)|
|16|2|CRC|*1<br>FDSフォーマットでは省略|
*1 CRC

### ファイルデータブロック(File data block, Block 4)
|フィールド名|オフセット|長さ|説明|
|:-:|:-:|:-:|:-|
|0|1|Block code|$04 固定|
|1|-|Disk data||
|-|2|CRC|*1<br>FDSフォーマットでは省略|

## *1 CRC

```
//
// CRC16/Kermitアルゴリズム
//  uint16_t reflect(uint16_t val, int size)は、ビットの順序を反転する関数
//
uint16_t encodeCRCValue(uint8_*dataStream, size_t size) {
  uint16_t poly      = 0x1021;  // 生成多項式
  uint16_t initCrc   = 0x0000;  // CRC初期値
  bool iReflect      = true;    // 入力のビット反転(順序)
  bool oReflect      = true;    // 出力のビット反転(順序)
  uint16_t xorValue  = 0x0000;  // 最終XOR値

  uint16_t crcValue = initCrc;                 // 初期値設定
  for (int idx=0; idx<size; idx++) {
    uint8_t val = *dataStream++;               // データの読み込みとポインタのインクリメント
    val = iReflect ? reflect(val, 8) : val;    // 入力をリフレクション(ビット順序反転)
    crcValue = crcValue ^ ((uint16_t)val << 8);// 上位8ビットに配置してXOR
    for (int jdx=0; jdx<8; jdx++) {
      if ((crcValue & 0x8000) == 0) {
        crcValue = crcValue << 1;              // 単純な左シフト
      } else {
        crcValue = (crcValue << 1 ) ^ poly;    // 多項式で割る
      }
    }
  }
  crcValue = oReflect ? reflect(crcValue, 16) : crcValue;
                                               // 出力をリフレクション(ビット順序反転)
  crcValue = crcValue ^ xorValue;              // 最終XOR処理
  return crcValue;
}

```

|パラメータ|変数名|値|
|:-:|:-:|:-:|
|多公式|poly|$1021|
|初期値|iValue|$0000|
|入力反転|iReflect|ture|
|出力反転|oReflect|ture|
|XOR値|xorValue|$0000|

## 参考文献

[FDS disk format](https://www.nesdev.org/wiki/FDS_disk_format)

