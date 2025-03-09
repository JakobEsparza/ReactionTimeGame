#include <LiquidCrystal.h>
// LCD pins
LiquidCrystal lcd(7,8,9,10,11,12);

// Button Pin
const int buttonPin = 2;

// RGB LED Pins
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

// Timing Variables
unsigned long startTime;
unsigned long reactionTime;
bool waitingForPress = false;


void setup() {
  //Defining the button pin
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Defining everything for the LED
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //initialize the lcd (16 columns and 2 rows)
  lcd.begin(16,2);
  
  // Displaying an intro
  lcd.clear();
  lcd.print("Get Ready");
  delay(2000);
}

void loop() {
  lcd.clear();
  lcd.print("Press button to");
  lcd.setCursor(0,1);
  lcd.print("Start the round");
 
  waitForButtonPressAndRelease();

  // Display instructoins
  lcd.clear();
  lcd.print("Wait for LED");
  delay(1000);

  //making sure our led is off
  setLEDColor(0, 0, 0);

  //waiting and then turning on our LED
  unsigned long randomDelayTime = random(2000, 5001);
  delay(randomDelayTime);

unsigned long waitStart = millis();
bool userWaited = true;
//anti marques cheating
while (millis() - waitStart < randomDelayTime) {
  if (digitalRead(buttonPin) == LOW) {
     userWaited = false;
     break;
  }
}
if (!userWaited) {
  setLEDColor(0,0,255);
  lcd.clear();
  lcd.print("Too Early!");
  delay(3000);
  setLEDColor(0,0,0);
  return;
}

  
  setLEDColor(0,255,0);

  //recording time
  startTime = millis();
  waitingForPress = true;

  while(waitingForPress){
    if (digitalRead(buttonPin) == LOW) {
      reactionTime = millis() - startTime;
      waitingForPress = false;
    }
  }

//Turn off LED 
setLEDColor(0, 0, 0);

// show reaction time
lcd.clear();
lcd.print("Reaction Time:");
lcd.setCursor(0,1);
lcd.print(reactionTime);
lcd.print(" ms");

// Pause so user can see result
delay(5000);
}

void setLEDColor(byte r, byte g, byte b) {
    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
}

// Wait for a butotn press and release

void waitForButtonPressAndRelease() {
  while (digitalRead(buttonPin) == HIGH) {
  }
  while (digitalRead(buttonPin) == LOW) {
  }
}
