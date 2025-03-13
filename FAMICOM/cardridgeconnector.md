# ファミコンカートリッジのピンアサイン

## 図面

2.54mm ピッチ

```
先頭の ! は反転

         /--------*
        /         |
    GND |         | RF Vcc
CPU A11 |
CPU A10 |
CPU A09 |
CPU A08 |
CPU A07 |
CPU A06 |
CPU A05 |
CPU A04 |
CPU A03 |
CPU A02 |
CPU A01 |
CPU A00 |
CPU !R/W |     | !ROMSEL(!A15+!φ2)
!IRQ
GND
PPU !RD
VRAM !A10
PPU A06
PPU A06
PPU A06
PPU A06
PPU A06
PPU A01
PPU A00

```