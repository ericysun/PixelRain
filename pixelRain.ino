const byte ANODE_PINS[8] = {6, 7, 8, 9, 10, 11, 12, 13};
const byte CATHODE_PINS[8] = {A3, A2, A1, A0, 5, 4, 3, 2};
byte grid[8][8]; //0 is off, 1 LED is on, 2 is for basket
byte paddleColumn = 2;
int dropletX = 0;
int dropletY = -1;
bool gameOver = false;

unsigned long lastMoveTime = 0;
// unsigned int fallDelay = 200; //hard level <--we can change the level to demo to Crista depending on what she wants
unsigned int fallDelay = 400; //mid level
// unsigned int fallDelay = 800; //easy level

void setup() {
  Serial.begin(115200);
  Serial.print("Grid:");
  Serial.print(grid[0][0]);
  for (byte i = 0; i < 8; i++) {
    pinMode(ANODE_PINS[i], OUTPUT);
    pinMode(CATHODE_PINS[i], OUTPUT);
    digitalWrite(ANODE_PINS[i], HIGH);
    digitalWrite(CATHODE_PINS[i], HIGH);
  }
  randomSeed(analogRead(A4));
}

void loop() {
  if (!gameOver) {
    readJoystickInput();
    updateBasket();
    maybeDropDroplet();
  }
  else {
    while (true);
  }
  updateLEDs();
}

//We have to map 1024 bit raw input to col # w/ map cast
void readJoystickInput() {
  int joystickXValue = analogRead(A5);
  paddleColumn = map(joystickXValue, 0, 1023, 0, 5);
}

// change basket position each move
void updateBasket() {
  for (byte i = 0; i < 8; i++) {
    grid[7][i] = 0;
  }
  for (byte i = 0; i < 3; i++) {
    grid[7][paddleColumn + i] = 2;
  }
}

// Start or move droplet down
void maybeDropDroplet() {
  if (millis() - lastMoveTime >= fallDelay) {
    lastMoveTime = millis();
    if (dropletY >= 0) {
      grid[dropletY][dropletX] = 0;
      dropletY++;
    }
    else {
      dropletX = random(0, 8);
      dropletY = 0;
    }

    if (dropletY < 7) {
      grid[dropletY][dropletX] = 1;
    }
    else {
      if (dropletX >= paddleColumn && dropletX <= paddleColumn + 2) {//user caught it spawn new one
        dropletY = -1;
      }
      else {// the user didn't catch it end game
        gameOver = true;
      }
    }
  }
}

// Draw the frame buffer to the LED grid
void updateLEDs() {
  for (byte row = 0; row < 8; row++) {
    digitalWrite(ANODE_PINS[row], LOW);

    for (byte col = 0; col < 8; col++) {
      if (grid[row][col] != 0) {
        digitalWrite(CATHODE_PINS[col], LOW);
      }
      else {
        digitalWrite(CATHODE_PINS[col], HIGH);
      }
    }
    delayMicroseconds(500);
    digitalWrite(ANODE_PINS[row], HIGH);
    for (byte col = 0; col < 8; col++) {
      digitalWrite(CATHODE_PINS[col], HIGH);
    }
  }
}

