# FAMICOM GAMEPAD
## PIN ASIGN

### Controller I
|No|I/O|Color| Name   | Detail   |
|:-:|:-:|:-:|:-|:-|
| 1| - |BROWN | GND | Ground |
| 2| O |RED   | DAT1| 結果 |
| 3| I |ORANGE| P/S | Act like counter reset when $4016.D0 was write. 1->0|
| 4| I |YELLOW| CLK | Shift register in controllerI when $4016 was read. D0  返す|
| 5| I |WHITE | VCC | 5V |

### Controller II
|No|I/O|Color| Name   | Detail   |
|:-:|:-:|:-:|:-|:-|
| 1| O |BROWN | MIC OUT| Output from mic on controller|
| 2| - |RED   | GND    | Ground |
| 3| O |ORANGE| DAT1   | ? |
| 4| I |YELLOW| P/S    | ? |
| 5| I |WHITE | CLK    | ? |
| 6| I |BLUE  | VCC    | 5V |

 I = Input to PAD
 
 O = Output from PAD
 
## CONNECTOR(Editing...)

```
?
```
## GAMEPAD INSIDE
 
### Controller I
```

     ___
 +---o o------------------------------------+
 |  SELECT ___                              |
 +---------o o---------------------------+  |
 |   ___  START                          |  |
 +---o o------------------------------+  |  |
 |    B                               |  |  |
 |                +----------------------------------+
 |                |                   |  |  |        |
 |                |    +---------+    |  |  |        |
 |                |    |         |    |  |  |        |
 |                |    |hef4021bp|    |  |  |        |
 |         ___    |    |         |    |  |  |        |
 +---------o o---------|P7    VCC|----------------------+
 |          A     |    |         |    |  |  |        |  |
 |                |    |Q5     P6|----+  |  |        |  +----o VCC (WHITE)
 |                |    |         |       |  |        |
 |                +----|Q7     P5|-------+  |  +-------------o CLK (YELLOW)
 |   ___          DAT  |         |          |  |     |
 +---o o---------------|P3     P4|----------+  |  +----------o P/S (ORANGE)                                                                                                                                     
 |    UP   ___         |         |             |  |  |
 +---------o o---------|P2     Q6|             |  |  +-------o DATA1 (RED)
 |   ___   DOWN        |         |             |  |
 +---o o---------------|P1     SD|----------------------+----o GND (BROWN)
 |   LEFT  ___         |         |             |  |     |
 +---------o o---------|P0    CLK|-------------+  |     |
 |        RIGHT        |         |                |     |
 +---------------------|GND   P/S|----------------+     |
 |                     |         |                     ---
 |                     +---------+                     ///
---
///

```

### Controller II
```


 
     ___
 +---o o------------------------------+
 |    B                               |
 |                +----------------------------------+
 |                |                   |              |
 |                |    +---------+    |              |
 |                |    |         |    |              |
 |                |    |hef4021bp|    |              |
 |         ___    |    |         |    |              |
 +---------o o---------|P7    VCC|----------------------+
 |          A     |    |         |    |              |  |
 |                |    |Q5     P6|----+  +--------------+----o VCC (BLUE)
 |                |    |         |       |           |
 |                +----|Q7     P5|-------+     +-------------o CLK (WHITE)
 |   ___          DAT  |         |       |     |     |
 +---o o---------------|P3     P4|-------+     |  +----------o P/S (YELLOW)                                                                                                                                     
 |    UP   ___         |         |             |  |  |
 +---------o o---------|P2     Q6|             |  |  +-------o DATA1 (ORANGE)
 |   ___   DOWN        |         |             |  |
 +---o o---------------|P1     SD|----------------------+----o GND (RED)
 |   LEFT  ___         |         |             |  |     |
 +---------o o---------|P0    CLK|-------------+  |     |  --o MIC (BROWN)
 |        RIGHT        |         |                |     |
 +---------------------|GND   P/S|----------------+     |
 |                     |         |                     ---
 |                     +---------+                     ///
---
///

```

## FORMAT

Famicom GAMEPAD communicate in serial communication

### SIGNAL LEVEL

|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|P/S|  H|  L|  L|  L|  L|  L|  L|  L|...|  L|  L|  H|  L|  L|  L|,,,|
|CLK|  H|  L|  H|  L|  H|  L|  H|  L|...|  H|  L|  H|  L|  H|  L|...|
|SBN|  1|  1|  2|  2|  3|  3|  4|  4|...|  8|  8|  1|  1|  2|  2|...|

SBN = Serial Bit Number

### BIT LEVEL(Editing...)

|SBN |  1|  2|  3|  4|  5|  6|  7|  8|  1|  2|  3|...|
|:-: |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|DATA|  A|  B| SL| ST| UP| DW| LF| RT|  A|  B| SL|...|

SL = SELECT, ST = START, DW = Down, LF = Left, RT = Right, ID = Identification(High level)

(Button is pushed => Low level)

## Reference

[ファミコン本体の回路図 | 電子機器 Junker](https://green.ap.teacup.com/junker/116.html)

[NES研究室ージョイパッド](http://hp.vector.co.jp/authors/VA042397/nes/joypad.html)

[NESdev wiki - Controller reading](https://wiki.nesdev.com/w/index.php/Controller_reading)

[ミニファミコンばりの“驚きの白さ”に？ 黄ばんだファミコンを分解&クリーニングしてみた](https://www.google.com/amp/s/kakakumag.com/amp/game/%3fid=9564)
