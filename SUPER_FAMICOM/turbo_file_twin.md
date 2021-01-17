# NINTENDO SUPER FAMICON PAD
## PIN ASIGN

|No|I/O| Color | Detail   |
|:-:|:-:|:-|:-|
| 1| - |       | GND    |
| 2| O |       | SELECT |
| 3| O |       | DAT2   |
| 4| O |       | DAT1   |
| 5| I |       | P/S    |
| 6| I |       | CLK    |
| 7| I |       | VCC    |

 I = Input to PAD
 
 O = Output from PAD
 
## CONNECTER

```
 /------+---------+
| 1 2 3 | 4 5 6 7 |
 \------+---------+
```

## FORMAT

|CLK | 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|...|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|DAT1| B| Y|SL|ST|UP|DW|LF|RT| A| X| L| R|ID|ID|ID|ID| B| Y|SL|...|

SL = SELECT, ST = START, DW = Down, LF = Left, RT = Right, ID = Identification(High level)

(Button is pushed => Low level)

## Reference

[SFCコントローラの解析](http://familunker.web.fc2.com/electric/sfc_controller.html)

[SFCコントローラの仕組みについて覚え書き](http://microkun.hatenablog.com/entry/2015/07/09/230114)
