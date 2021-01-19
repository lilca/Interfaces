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
