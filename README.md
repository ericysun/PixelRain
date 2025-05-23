# PixelRain
PixelRain is a minimalist arcade game designed for an 8x8 LED matrix controlled via a joystick. Navigate your pixel to dodge falling raindrops, testing your reflexes and precision. Built on a custom PCB, this game offers a blend of simplicity and challenge.

## Parts
- Arduino Joystick
- 8 resistors
- 8 PMOS transistors
- 64 LEDs
- Arduino Uno Mini Control Board
- Custom Circuit Board
#### On the PCB
1. Solder 64 LEDs in the 8x8 Grid
2. Attach a PMOS transistor at the start of each row
3. Attach a pulldown resistor at the bottom of each column
#### On the Joystick:
1. Attach the Vdd and GND to the power rails on the PCB
2. Attach the VRx and VRy to A4 and A5 on the PCB
Look at the wiring diagram for reference.

Debugging Instructions:
- Test each LED individually with a battery in order to check solder connections.
- Make sure the PMOS transistors have gate, drain, and source connected correctly, which is the most likely cause of error on the board.
