# ディスクフォーマット

## ブロック

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
続きはあとで
## 参考文献

[FDS disk format](https://www.nesdev.org/wiki/FDS_disk_format)

