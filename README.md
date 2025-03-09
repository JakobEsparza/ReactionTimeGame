# ReactionTimeGame
Arduino project that measures reaction time using a random LED signal and displays results on an LCD.

This project measures how quickly you can press a button after a random delay. An RGB LED lights up to signal “go,” and the code times your response using millis(). If you press too early, the game flashes the LED red and displays “Too Early!” on the LCD.

Materials:
- Arduino Uno
- 16×2 LCD + potentiometer
- RGB LED + 3 220ohm resistors
- Pushbutton
- Assorted jumper wires + breadboard

Pin Assignments:
| Component | Arduino Pin |
|-----------|------------|
| LCD RS    | 7          |
| LCD EN    | 8          |
| LCD D4    | 9          |
| LCD D5    | 10         |
| LCD D6    | 11         |
| LCD D7    | 12         |
| Button    | 2          |
| LED Red   | 3          |
| LED Green | 5          |
| LED Blue  | 6          |
