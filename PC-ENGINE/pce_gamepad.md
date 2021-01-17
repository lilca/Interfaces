## PC-ENGINE GAMEPAD

## CONNECTOR

```
 MINI DIN8 JACK
   /-----\
  / 6 7 8 \
 | 3 4   5 |
  \  1 2  /
   \-----/
```

## PIN ASSIGN
|No|Name|Detail|
|:-:|:-:|:-|
|1|VCC||
|2|UP or TR1|TR1 = Trigger1|
|3|RIGHT or TR2|TR2 = Trigger2|
|4|DOWN or SELECT||
|5|LEFT or RUN||
|6|A/B SELECT|Act like button address|
|7|STROBE|Button data is read at the rising edge of this signal|
|8|GND||

## GAMEPAD INSIDE
```
           +-------------------------+
           |    R ARRAY( 47Kohm )    |+-------------------------o 1 : VCC(5V)
           +-------------------------+   +---------+
     ___    | | | |           | | | |    |         |
 +---o o----+----------------------------+ 1A   1Y |---^^^------o 2 : UP & TR1
 | TRIGGER 1  | | |    ___    | | | |    |         |  330ohm
 +---------------------o o----+----------+ 1B   2Y |---^^^------o 3 : RIGHT & TR2
 |   ___      | | |    UP       | | |    |         |  330ohm
 +---o o------+--------------------------+ 2A   3Y |---^^^------o 4 : DOWN & SELECT
 | TRIGGER 2    | |    ___      | | |    |         |  330ohm
 +---------------------o o------+--------+ 2B   4Y |---^^^------o 5 : LEFT & RUN
 |   ___        | |   RIGHT       | |    |     _   |  330ohm
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
