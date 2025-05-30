## キャラクターパターンテーブル

カートリッジ内のキャラクタデータ

- キャラクタサイズは 8x8
- 1ピクセル 2bit(4色 ただし、ゼロは透明固定)
- つまり、1キャラクタ16Byte
- 最初の8byteは、各ピクセルの下位ビット(1の位)
- 次の8Byteは、各ピクセルの上位ビット(2の位)
- 1ページ=4096Byteで、256のキャラクタパターンが格納されている
- キャラクターパターンテーブルは、２ページ=4096 x 2 Byte

### キャラクタパターンの例

|バイト|ビット|
|-:|:-:|
||7654-3210|
|0|0001-1000|
|1|0001-1000|
|2|1010-0101|
|3|0111-1110|
|4|0011-1100|
|5|0101-1010|
|6|0101-1010|
|7|0101-1010|
|||
|8|0101-1010|
|9|0101-1010|
|10|0001-1000|
|11|0001-1000|
|12|1010-0101|
|13|0111-1110|
|14|0011-1100|
|15|0101-1010|

### アドレッシング

```
FEDCBA98 76543210
000PNNNN NNNNpYYY
   |        ||  +-- Y(y)      : パターンのY座標
   |        |+----- p(place)  : ピクセル値の位(0=1の位, 1=2の位)
   |        +------ N(number) : パターン番号
   +--------------- P(page)   : ページ番号(0=$0000-$0FFF, 1=$1000-$1FFF)

  page = 1
  number = 30
  place = 0
  y = 3      のとき

  address = y | place << 3 | number << 4 | page << 12
```

####
 $2000 のレジスタがページを制御する。ビット4が背景,ビット3がスプライト
