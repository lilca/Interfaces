# セガサターンパッド

## コネクタ

(パッド側．短い方が上．番号は右から．

```
 /-----------------\
| 9 8 7 6 5 4 3 2 1 |
|                   |
+-------------------+
```

## ピン配置

|No|I/O| Color | Detail   |
|:-:|:-:|:-|:-|
| 1| I | BRWON | VCC(5V)  |
| 2| O | GREEN | data1    |
| 3| O | BLACK | data0    |
| 4| I | RED   | address0 |
| 5| I | ORANGE| address1 |
| 6| O | BLUE  | VCC(5V)  |
| 7| O | YELLOW| data3    |
| 8| O | GRAY  | data2    |
| 9|   | WHITE | GND      |

I = パッドへ入力

O = パッドから出力

## フォーマット
|a1|a0|   d3|  d2|  d1|d0|
|:-:|:-:|:-:|:-:|:-:|:-:|
| 0| 0|   RB|   X|   Y| Z|
| 0| 1|Right|Left|Down|Up|
| 1| 0|Start|   A|   C| B|
| 1| 1|   LB|   1|   0| 0|

a0,a1 = address(Input)

d0-d3 = data(Output)

(ボタンが押されると => ローレベルつまり”０”)

## 参照
[セガサターンのコントロールパッドの解析](http://kaele.com/~kashima/games/saturn.html)
