# NINTENDO SUPER FAMICOM PAD
## PIN ASIGN

|No|I/O| Name   | Detail   |
|:-:|:-:|:-|:-|
| 1| - | GND    | Ground |
| 2| I(?) | SELECT | A expansion pin for input to PAD? |
| 3| O(?) | DAT2   | A expansion pin for output from PAD? |
| 4| O | DAT1   | Button Data |
| 5| I | P/S    | Act like RESET |
| 6| I | CLK    | Clock|
| 7| I | VCC    | 5V(?) |

 I = Input to PAD
 
 O = Output from PAD
 
## CONNECTER

```
 /------+---------+
| 1 2 3 | 4 5 6 7 |
 \------+---------+
```

## FORMAT

Super Famicom PAD communicate in serial communication

### SIGNAL LEVEL

|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|P/S|  H|  L|  L|  L|  L|  L|  L|  L|...|  L|  L|  H|  L|  L|  L|,,,|
|CLK|  H|  L|  H|  L|  H|  L|  H|  L|...|  H|  L|  H|  L|  H|  L|...|
|SBN|  1|  1|  2|  2|  3|  3|  4|  4|...| 16| 16|  1|  1|  2|  2|...|

SBN = Serial Bit Number

### BIT LEVEL

|SBN | 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16| 1| 2| 3|...|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|DAT1| B| Y|SL|ST|UP|DW|LF|RT| A| X| L| R|ID|ID|ID|ID| B| Y|SL|...|

SL = SELECT, ST = START, DW = Down, LF = Left, RT = Right, ID = Identification(High level)

(Button is pushed => Low level)

## Reference

[SFCコントローラの解析](http://familunker.web.fc2.com/electric/sfc_controller.html)

[SFCコントローラの仕組みについて覚え書き](http://microkun.hatenablog.com/entry/2015/07/09/230114)
