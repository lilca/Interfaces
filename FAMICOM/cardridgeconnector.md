# ファミコンカートリッジのピンアサイン

## 図面

2.54mm ピッチ

```
先頭の '/' は反転

  本体　         ｶｰﾄﾘｯｼﾞ       本体
             /-------+
            /        |
    GND  -- |01    31| -> RF Vcc
CPU A11  -> |02    32| <- M2(クロック)
CPU A10  -> |03    33| <- CPU A12
CPU A9   -> |04    34| <- CPU A13
CPU A8   -> |05    35| <- CPU A14
CPU A7   -> |06    36| <> CPU D7
CPU A6   -> |07    37| <> CPU D6
CPU A5   -> |08    38| <> CPU D5
CPU A4   -> |09    39| <> CPU D4
CPU A3   -> |10    40| <> CPU D3
CPU A2   -> |11    41| <> CPU D2
CPU A1   -> |12    42| <> CPU D1
CPU A0   -> |13    43| <> CPU D0
CPU R/W  -> |14    44| <- /ROMSEL(/A15+/M2)
/IRQ     <- |15    45| <- Audio from 2A03
GND      -- |16    46| -> Audio to RF
PPU /RD  -> |17    47| <- PPU /WR
VRAM A10 <- |18    48| -> VRAM /CE
PPU A6   -> |19    49| <- PPU /A13
PPU A5   -> |20    50| <- PPU A7
PPU A4   -> |21    51| <- PPU A8
PPU A3   -> |22    52| <- PPU A9
PPU A2   -> |23    53| <- PPU A10
PPU A1   -> |24    54| <- PPU A11
PPU A0   -> |25    55| <- PPU A12
PPU D0   <> |26    56| <- PPU A13
PPU D1   <> |27    57| <> PPU D7
PPU D2   <> |28    58| <> PPU D6
PPU D3   <> |29    59| <> PPU D5
+5V      -- |30    60| <> PPU D4
            \        |
             \-------+
```

|項目|説明|
|:-|:-|
|CPU A0-A14||
|CPU /A15||
|CPU R/W||
|CPU D0-D7||
|PPU A0-A13||
|PPU /A13||
|PPU /RD||
|PPU /WR||
|PPu D0-D7||
|+5V||
|GND||
|RF Vcc||
|/IRQ||
|M2||
|VRAM A10||
|VRAM /CE||
|SOUND IN|本体からのカセットへのサウンド|
|SOUND OUT|カセット音源があればSOUND INとミックスして出力|

# 参考文献
[Cartridge connector, NES Dev](https://www.nesdev.org/wiki/Cartridge_connector)

[ファミコンカートリッジコネクタ仕様](https://gamernium.com/archives/1357)
