Editing now.
[ここの情報を整理しようと思う](http://kitahei88.blog.fc2.com/blog-category-4-2.html)
# 書き込みプロテクト
## 見分け方
- 付属のRAMアダプターがツルツルがプロテクトなし、ザラザラはプロテクト有り
- ドライブ基板の番号が01~03はプロテクトなし、04と05はプロテクト有り

## 参考文献
[FDS Stickでディスクシステムのゲームを書き込んでみる](https://ameblo.jp/koudaken7777/entry-12648274550.html)

# Signal(信号)
## Ram Adapter <-> Disk Drive
### Connector

```
 ドライブ側のメス端子を正面に見て

 /-----------------\
/  2  4  6  8 10 12 \
|                   |
|  1  3  5  7  9 11 |
+-------------------+

```

|No|色|名前|読み書き|
|:-:|:-:|:-:|:-|
|1|茶|/Write Gate||
|2||Vcc 5V||
|3|橙|/Motor|0=メディアをスキャン|
|4|黄|GND||
|5|緑|/Write Data||
|6|青|Battery Sence||
|7|紫|/Write Protect||
|8|灰|Vcc Out||
|9|白|Read Data||
|10|黒|/Media Set||
|11|桃|/Ready||
|12|水|/Reset|0=モーターを止める|

# その他
* Clock = 96.4 kHz (T = 10.37=10.373...[us])
* Modulation = MFM  // MFM変調
* Sending data to order LSB to MSB
* I/O Level = 5V

# MFM変調
* クロックビット、データビットの順番で送信する
* クロックビットは通常０
* ただし、前のデータビットと今のデータビットがゼロの場合、クロックビットは１

Example(例)

```
0xa5 = 1010 0101 b
Data bit  = 1 0 1 0 0 1 0 1
Clock bit =X 0 0 0 1 0 0 0
Send data =X100010010010001
(X は未確定)
```

## クロックアップ周期(Term of clock-up)

|-|-|-|-|-|Term|
|:-|:-:|:-:|:-:|:-:|-:|
|000|X0|10|10||1T|
|001|X0|10|01||1.5T|
|0100|X0|01|00|10|1.5T|
|0101|X0|01|00|01|2T|
|011|X0|01|01||1T|
|100|X1|00|10||1.5T|
|101|X1|00|01||2T|
|110|X1|01|||1T|
|111|X1|01|||1T|



## References(参考文献)
[ディスクシステムローダー（セーバー）の準備:レトロゲーム漫遊記](http://kitahei88.blog.fc2.com/blog-entry-102.html)
[ディスクシステムローダー（セーバー）の準備　その2:レトロゲーム漫遊記](http://kitahei88.blog.fc2.com/blog-entry-103.html#more)
[jfdsloadr.txt:エミュレートステーション](http://www.emusta.net/jfdsloadr.txt)
