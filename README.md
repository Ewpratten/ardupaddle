# ardupaddle
A CW/morse code paddle built with an atmega32u4 processor.

I needed a paddle to practice morse code with, so I built one with a AVR chip, and some paper clips. Code should be fairly self-explanitory. Pins `2` and `3` are paddle inputs (pull up), and pin `4` is the voltage output.

## TODOS:

 - [ ] Re-write this to run without the Arduino library. I don't need any fancy features, so plain AVR code should be fine. Maybe switch to using an ATTiny in the process