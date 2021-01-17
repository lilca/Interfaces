## PC-ENGINE GAMEPAD

## CONNECTOR

```
 MINI DIN8 JACK (Cable side)
   /-----\
  / 6 7 8 \
 | 3 4   5 |
  \  1 2  /
   \-----/
```

## PIN ASSIGN
|No|I/O||Name|Detail|
|:-:|:-:|:-:|:-|
|1|I|VCC||
|2|O|UP or TR1|TR1 = Trigger1|
|3|O|RIGHT or TR2|TR2 = Trigger2|
|4|O|DOWN or SELECT||
|5|O|LEFT or RUN||
|6|I|A/B SELECT|Act like button address|
|7|I|STROBE|Button Data is read at the rising edge of this signal|
|8|-|GND||

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

|A/B SELECT|1Y|2Y|3Y|4Y||
|:-|:-|:-|:-|:-|:-|
|0|TR1|TR2|SELECT|RUN| A/B SELECT is Low level|
|1|UP|RIGHT|DOWN|LEFT| A/B SELECT is High level|


Button is pushed => Low level(?)

## References

[PCエンジンの連射機能付きコントローラー](http://rapidturbo2000.blog.fc2.com/blog-entry-95.html)
