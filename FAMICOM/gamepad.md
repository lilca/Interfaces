# FAMICOM PAD
## PIN ASIGN

### Controller I
|No|I/O|Color| Name   | Detail   |
|:-:|:-:|:-:|:-|:-|
| 1| - |BROWN | GND      | Ground |
| 2| ? |RED   | 4016_D0$ | ? |
| 3| ? |ORANGE| OUT0     | ? |
| 4| ? |YELLOW| 4016_CPU$| ? |
| 5| I |WHITE | VCC      | 5V |

### Controller II
|No|I/O|Color| Name   | Detail   |
|:-:|:-:|:-:|:-|:-|
| 1| O |BROWN | MIC OUT  | Output from mic on controller|
| 2| - |RED   | GND      | Ground |
| 3| ? |ORANGE| 4017_D0$ | ? |
| 4| ? |YELLOW| OUT0     | ? |
| 5| ? |WHITE | 4017_CUP$| ? |
| 6| I |BLUE  | VCC      | 5V |

 I = Input to PAD
 
 O = Output from PAD
 
## CONNECTOR(Editing...)

```
?
```

## FORMAT(Editing...)

Super Famicom PAD communicate in serial communication

### SIGNAL LEVEL(Editing...)

|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|P/S|  H|  L|  L|  L|  L|  L|  L|  L|...|  L|  L|  H|  L|  L|  L|,,,|
|CLK|  H|  L|  H|  L|  H|  L|  H|  L|...|  H|  L|  H|  L|  H|  L|...|
|SBN|  1|  1|  2|  2|  3|  3|  4|  4|...| 16| 16|  1|  1|  2|  2|...|

SBN = Serial Bit Number

### BIT LEVEL(Editing...)

|SBN | 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16| 1| 2| 3|...|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|DAT1| B| Y|SL|ST|UP|DW|LF|RT| A| X| L| R|ID|ID|ID|ID| B| Y|SL|...|

SL = SELECT, ST = START, DW = Down, LF = Left, RT = Right, ID = Identification(High level)

(Button is pushed => Low level)

## Reference

[ファミコン本体の回路図 | 電子機器 Junker](https://green.ap.teacup.com/junker/116.html)
