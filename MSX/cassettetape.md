# MSX CASSETE TYPE INTERFACE
## CONNECTOR (Cable side)
```
    -----
   /     \
  / 6   7 \
 | 1  8  3 |
  \ 4   5 /
   \  2  /
    -----
```
## PIN ASSIGN

|No|I/O|Name|
|:-:|:-:|:--|
|1|-|GND|
|2|-|GND
|3|-|GND|
|4||SAVE|
|5||LOAD|
|6||REMOTE|
|7||?|
|8|GND|

## BAUD RATE
|Baudrate[bps]|Detail|
|:-:|:--|
|1200|Low speed - High trust|
|2400|High speed - Low trust|

## 1 BIT
|Baudrate[bps]|Bit|Wave|Detail|
|:-:|:-:|:-|:-:|
|1200|0|\_\_\_\_----|1200Hz x 1wave|
||1|\_\_--\_\_--|2400Hz x 2wave|
|2400|0|\_\_--|2400Hz x 1wave|
||1|\_-\_-|4800Hz x 2wave|

## 1 BYTE
```
        LSB                             MSB
...| 0 | X | X | X | X | X | X | X | X | X | 1 | 1 |...
   \__/\__________________________________/\______/
Startbit           1Byte Data              Stop bit
```

## HEADER
|Baudrate[bps]|Header-Type|Detail|Time|
|:-:|:-:|:-:|:-:|
|1200|LONG|2400Hz x 16000wave|around 6.7s|
||SHORT|2400Hz x 4000wave|around 1.7s|
|2400|LONG|4800Hz x 32000wave|around 6.7s|
||SHORT|4800Hz x 8000wave|around 1.7s|

## FILE FORMAT
### BASIC TEXT FILE
A BASIC program file as binary data save and load with CSAVE and CLOAD.

|Name|Length|Detail|
|:-|:-:|:-|
|Long Header|6.7s||
|0xD3h * 10|10byte||
|File Name|6byte|When less 6byte, allocate Space(0x20h?) for the shortage|
||-|Silent(Blank Area)|
|Short Header|1.7s||
|BASIC Program|N|N = Program length|
|0x00h * 7|7byte||

### ASCII TEXT FILE
A BASIC program file as ascii data save and load with SAVE and LOAD.

|Name||Length|Detail|
|:-|:-:|:-:|:-|
|Long header|6.7s||
|0xEAh * 10||10byte||
|File Name||6byte|When less 6byte, allocate Space(0x20h?) for the shortage|
||?|Silent(Blank Area)|
|ブロック１|ショートヘッダ|1.7秒||
||データ１|256byte||
|ブロック２|ショートヘッダ|1.7秒||
||データ２|256byte||
|ブロック３|ショートヘッダ|1.7秒||
||データ３|256byte||
||：|||
|最終ブロック|ショートヘッダ|1.7秒||
||データＮ|？byte|0x1Ah(Ctrl+Z = EOF)検出時に終了？|

```
0x1Ahを含むデータファイルは作れない
```

### MACHINE LANGUAGE FILE
A machine language file save and load with BSAVE and BLOAD.

|Name|Length|Detail|
|:-|:-:|:-|
|Long Header|6.7s||
|0xD0h * 10|10byte||
|File Name|6byte|When less 6byte, allocate Space(0x20h?) for the shortage|
||-|Silent(Blank Area)|
|Short Header|1.7s||
|Beginning Address|2byte|Start address of program area|
|Last Address|2byte|Last address of program area|
|Start Address|2byte|Start execution at address (Valid only when R option was used in BLOAD)|
|Program Data|Last Address - Beginning Address + 1 byte||

## References

[２章カセット・インターフェースーテクハンwiki](http://ngs.no.coocan.jp/doc/wiki.cgi/TechHan?page=2%BE%CF+%A5%AB%A5%BB%A5%C3%A5%C8%8E%A5%A5%A4%A5%F3%A5%BF%A1%BC%A5%D5%A5%A7%A5%A4%A5%B9)

[piroyan's Lablog:カセットインターフェースの製作](http://lablog.piroyan.com/index.php?e=24)
