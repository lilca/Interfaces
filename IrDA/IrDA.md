# 赤外線通信

## 周期
(パッド側．短い方が上．番号は右から．

|メーカー|キャリア[nm]|サブキャリア[kHz]|duty比|変調単位[us]|フレーム[bit]|データ(bit)|
|:-:|:-:|:-|:-|
|NEC|950|38|1/3|562|FIX32|8（データ） + 8（データ反転）|
|家電協|950|33~40(38)|1/3|350~500(425)|VAR48,トレーラ|16（カスタムコード） + 4（パリティ）|
|SONY|950|40|1/3|600|FIX7|5/8/13のアドレス|
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
[赤外線リモコンの通信フォーマット](http://elm-chan.org/docs/ir_format.html)
