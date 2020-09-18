## VGAタイミング(640x480/60Hz)

### クロック

|周波数[MHz]|周期[us]|
|:-|:-|
|20|0.05|
|16|0.0625|
|14.31818|0.069841279|

### 業界標準タイミング

|パラメータ|ピクセル数|時間[us]|
|:-|:-:|:-|
|FPS|60 [Hz]||
|垂直|31.46875 [kHz]|31.77755710|
|１ピクセル|25.175 [MHz]|0.039722|

### 水平タイミング

|パラメータ|ピクセル数|時間[us]|20 MHz[clk]|16 MHz[clk]|14.31818 MHz[clk]|
|:-|:-:|:-|:-|:-|:-|
|フロントポーチ|16|0.635551142|12.711|10.169|9.100|
|同期パルス|96|3.813306852|76.226|61.013|54.600|
|バックポーチ|48|1.906653426|38.133|30.506|27.300|
|映像エリア|640|25.42204568|508.441|406.753|363.997|
|ライン合計|800|31.7775571|635.551|508.441|454.997|

### 垂直タイミング

|パラメータ|ライン数|時間[us]|20 MHz[clk]|16 MHz[clk]|14.31818 MHz[clk]|
|:-|:-:|:-|:-|:-|:-|
|フロントポーチ|10|317.775571|||
|同期パルス|2|63.5551142|||
|バックポーチ|33|1048.659384|||
|映像エリア|480|15253.22741|||
|ライン合計|525|NTSC|||

### インターレース

なし

## 電圧レベル

|端子|レベル(電圧)|
|:-|:-|
|Red|0.7Vp-p|
|Green|0.7Vp-p|
|Blue|0.7Vp-p|
|H-Sync|TTL|
|V-Sync|TTL|

``` (TTL=5V) ```

# 参考文献

[Arduinoを用いたVGA映像信号の出力](http://www.net.c.dendai.ac.jp/~anada/)

[RGB Video の同期信号](http://www.avis.ne.jp/~meteor/html/video-sync.html)

[VGA Signal Timing](http://tinyvga.com/vga-timing)