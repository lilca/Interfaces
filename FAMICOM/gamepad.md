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
---o o ---        |hef4021bp|
    UP    ___
 +---------o o----|P7    VCC|-------------------+
 |          A     |         |                   |
 |                |Q5     P6|                   +----o VCC
 |                |         |
 |         -------|Q7     P5|          +-------------o CLK
 |   ___    DAT   |         |          |
 +---o o----------|P3     P4|          |  +----------o P/S                                                                                                                                                                      
 |    UP   ___    |         |          |  |
 +---------o o----|P2     Q6|          |  |  +-------o DATA1
 |   ___   DOWN   |         |          |  |  |
 +---o o----------|P1     SD|----------------+  +----o GND
 |   LEFT  ___    |         |          |  |     |
 +---------o o----|P0    CLK|----------+  |     |
 |        RIGHT   |         |             |     |
 +----------------|GND   P/S|-------------+     |
 |                |         |                  ---
 |                +---------+                  ///
---
///
   START  ___
----------o o---
         SELECT
白 VCC
橙 P/S
黄 CLK
茶 GND SD
赤 Q7
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
