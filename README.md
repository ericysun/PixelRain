<img width="841" alt="pixelRainHeader" src="https://github.com/user-attachments/assets/ab8e5671-c044-4a85-b00c-b33a52d80316" />

# PixelRain
PixelRain is a minimalist arcade game designed for an 8x8 LED matrix controlled via a joystick. Navigate your pixel to dodge falling raindrops, testing your reflexes and precision. Built on a custom PCB, this game offers a blend of simplicity and challenge.

https://github.com/user-attachments/assets/adfabd07-2d7e-452a-b4d8-82c2a8672e57

## Parts
- Arduino Joystick
- 8 90Ω resistors
- 8 PMOS transistors
- 64 LEDs
- Adafruit Metro Mini (Arduino-Compatible Control Board)
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
