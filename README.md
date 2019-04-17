# Meet Buttons

Physical mute buttons for your Google Hangouts Meet Hardware!

Use an Arduino Leonardo to send the mute audio/video keystrokes, so you don't
need to hit the touchscreen.

## Bill of Materials

* [Arduino Leonardo](https://www.adafruit.com/product/849) or similar ATmega32u4
  based board.
* At least 2 Buttons (for example this [Membrane Keypad](https://www.adafruit.com/product/1332)).
* Jumper Wires
* USB A => micro B cable
* Case (optional)

## Wiring

| Pin | Destination |
| --- | ----------- |
| 2   | audio toggle button |
| 3   | video toggle button |
| gnd | other side of both buttons |

## Known Issues

### Virtual Keyboard

When a keyboard is plugged into a Meet device, the virtual keyboard won't pop up
automatically.  Workaround is to long press on the input field, press Emoji, and
then press the ABC keyboard button.

## Disclaimers

* This is not an official Google product.
* This accessory is not sanctioned by the Google Hangouts Meet team.
