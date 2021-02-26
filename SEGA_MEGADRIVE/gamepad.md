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

## GAMEPAD INSIDE
```
           +-------------------------+
           |    R ARRAY( 47Kohm )    |+-------------------------o 1 : VCC(5V)
           +-------------------------+   +---------+
     ___    | | | |           | | | |    |         |                                --+
 +---o o----+----------------------------+ 1A   1Y |---^^^------o 2 : UP & TR1        |
 | TRIGGER 1  | | |    ___    | | | |    |         |  330ohm                          |
 +---------------------o o----+----------+ 1B   2Y |---^^^------o 3 : RIGHT & TR2     |
 |   ___      | | |    UP       | | |    |         |  330ohm                          | Button Data
 +---o o------+--------------------------+ 2A   3Y |---^^^------o 4 : DOWN & SELECT   |
 | TRIGGER 2    | |    ___      | | |    |         |  330ohm                          |
 +---------------------o o------+--------+ 2B   4Y |---^^^------o 5 : LEFT & RUN      |
 |   ___        | |   RIGHT       | |    |     _   |  330ohm                        --+
 +---o o--------+------------------------+ 3A  A/B |------------o 6 : A/B SELECT
 |  SELECT        |    ___        | |    |         |
 +---------------------o o--------+------+ 3B      |
 |   ___          |    DOWN         |    |       _ |
 +---o o----------+----------------------+ 4A    G +------------o 7 : STROBE
 |   RUN               ___          |    |         |
 +---------------------o o----------+----+ 4B      |      +-----o 8 : GND
 |                     LEFT              |         |      |
 |                                       +---------+      |
 |                                                        |
 +                                                        +
GND                                                      GND
```

## FORMAT

|a0| d5 | d4|     d3|   d2|    d1|  d0|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0|START| A | low  | low | DOWN | UP |
| 1| C   | B | RIGHT| LEFT| DOWN | UP |

a0 = address(Input)
 
d0-d5 = data(Output)
 
(Button is pushed => Low level)

## Reference
[メガドラパッドの回路図](https://nicotakuya.hatenablog.com/entry/20081029/1225295517)

[セガ メガドライブ　６ボタンパッドの読み取り方](https://applause.elfmimi.jp/md6bpad.html)

[セガサターンのコントロールパッドの解析](http://kaele.com/~kashima/games/saturn.html)
