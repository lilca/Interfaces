Editing now.

# Signal(信号)
## Ram Adapter <-> Disk Drive
### Connector

# その他
* Clock = 96.4 kHz (T = 10.37=10.373...[us])
* Modulation = MFM  // MFM変調
* Sending data to order LSB to MSB

# MFM変調
* クロックビット、データビットの順番で送信する
* クロックビットは通常０
* ただし、前のデータビットと今のデータビットがゼロの場合、クロックビットは１

Example(例)
0xa5 = 1010 0101 b
Data bit  = 1 0 1 0 0 1 0 1
Clock bit =X 0 0 0 1 0 0 0
Send data =X100010010010001
(X は未確定)

## References(参考文献)
[ディスクシステムローダー（セーバー）の準備:レトロゲーム漫遊記](http://kitahei88.blog.fc2.com/blog-entry-102.html)
[jfdsloadr.txt:エミュレートステーション](http://www.emusta.net/jfdsloadr.txt)
