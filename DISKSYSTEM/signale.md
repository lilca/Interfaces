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

## References(参考文献)
[ディスクシステムローダー（セーバー）の準備:レトロゲーム漫遊記](http://kitahei88.blog.fc2.com/blog-entry-102.html)
[jfdsloadr.txt:エミュレートステーション](http://www.emusta.net/jfdsloadr.txt)
