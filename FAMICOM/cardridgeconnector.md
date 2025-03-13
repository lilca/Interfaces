# ファミコンカートリッジのピンアサイン

## 図面

2.54mm ピッチ

```
先頭の / は反転

          /-------*
         /        |
    GND  |01    31| RF Vcc
CPU A11  |02    32| 
CPU A10  |03    33| 
CPU A9   |04    34| 
CPU A8   |05    35| 
CPU A7   |06    36| 
CPU A6   |07    37| 
CPU A5   |08    38| 
CPU A4   |09    39| 
CPU A3   |10    40| 
CPU A2   |11    41| 
CPU A1   |12    42| 
CPU A0   |13    43| 
CPU R/W  |14    44| /ROMSEL(/A15+/M2)
/IRQ     |15    45| 
GND      |16    46| 
PPU /RD  |17    47| 
VRAM A10 |18    48| 
PPU A6   |19    49| 
PPU A5   |20    50| 
PPU A4   |21    51| 
PPU A3   |22    52| 
PPU A2   |23    53| 
PPU A1   |24    54| 
PPU A0   |25    55| 
PPU D0   |26    56| 
PPU D1   |27    57| 
PPU D2   |28    58| 
PPU D3   |29    59| 
+5V      |30    60|
         \        |
          \-------+
```

# 参考文献
[Cartridge connector, NES Dev](https://www.nesdev.org/wiki/Cartridge_connector)
