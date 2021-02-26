# SEGA MEGA DRIVE PAD

## CONNECTOR
(Pad side. Shorter side is the upside. Numbering from right.)

```
 /---------\
| 5 4 3 2 1 |
 \ 9 8 7 6 /
  \-------/
+-------------------+
```

## PIN ASIGN

|No|I/O| Color | Detail   |
|:-:|:-:|:-|:-|
| 1| O | -     | data0    |
| 2| O | -     | data1    |
| 3| O | -     | data2    |
| 4| O | -     | data3    |
| 5| I | -     | VCC(5V)  |
| 6| O | -     | data4    |
| 7| I | -     | address(selector)    |
| 8| - | -     | GND      |
| 9| O | -     | data5    |

 I = Input to PAD
 
 O = Output from PAD

## FORMAT

|a1|a0|   d3|  d2|  d1|d0|
|:-:|:-:|:-:|:-:|:-:|:-:|
| 0| 0|   RB|   X|   Y| Z|
| 0| 1|Right|Left|Down|Up|
| 1| 0|Start|   A|   C| B|
| 1| 1|   LB|   1|   0| 0|

a0,a1 = address(Input)
 
d0-d3 = data(Output)
 
(Button is pushed => Low level)

## Reference
[メガドラパッドの回路図](https://nicotakuya.hatenablog.com/entry/20081029/1225295517)

[セガ メガドライブ　６ボタンパッドの読み取り方](https://applause.elfmimi.jp/md6bpad.html)

[セガサターンのコントロールパッドの解析](http://kaele.com/~kashima/games/saturn.html)
