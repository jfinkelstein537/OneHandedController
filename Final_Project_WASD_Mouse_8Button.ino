#include <Keyboard.h>
#include <Mouse.h>
const int joystick1X = 2;
const int joystick1Y = 3;
const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 6;
const int button6 = 7;
const int joystickPress = 8;
const int mouseLeftButton = 1;
const int joystick2X = 5;
const int joystick2Y = 4;


int cursorSpeed = 35;
int responseDelay =20;
int threshold = cursorSpeed/7;
int center = cursorSpeed/2;

void setup() {
  // put your setup code here, to run once:
   pinMode(joystickPress, INPUT_PULLUP);
   pinMode(mouseLeftButton, INPUT_PULLUP);
   pinMode(button1, INPUT_PULLUP);
   pinMode(button2, INPUT_PULLUP);
   pinMode(button3, INPUT_PULLUP);
   pinMode(button4, INPUT_PULLUP);
   pinMode(button5, INPUT_PULLUP);
   pinMode(button6, INPUT_PULLUP);
   Keyboard.begin();
   Mouse.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int xReading = readAxis(joystick2X);
  int yReading = readAxis(joystick2Y);
  
  Mouse.move(xReading, yReading, 0);
  
  if(analogRead(joystick1X) > 750)
  {
    Keyboard.press('d');
  }
  if(analogRead(joystick1X) < 300)
  {
    Keyboard.press('a');
  }
  if(analogRead(joystick1Y) > 750)
  {
    Keyboard.press('w');
  }
  if(analogRead(joystick1Y) < 300)
  {
    Keyboard.press('s');
  }
  if(digitalRead(joystickPress) == LOW)
  {
    Keyboard.press('r');
  }
  if(digitalRead(button1) == LOW)
  {
    Keyboard.press('z');
  }
  if(digitalRead(button2) == LOW)
  {
    Keyboard.press('x');
  }
  if(digitalRead(button3) == LOW)
  {
    Keyboard.press('c');
  }
  if(digitalRead(button4) == LOW)
  {
    Keyboard.press('v');
  }
  if(digitalRead(button5) == LOW)
  {
    Keyboard.press('b');
  }
  if(digitalRead(button6) == LOW)
  {
    Keyboard.press('n');
  }
  if(digitalRead(mouseLeftButton) == LOW) {
    
    if(!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
      delay(100);
  //    Mouse.release();
    }
  }
   else {
    if(Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  delay(responseDelay);
  Keyboard.releaseAll();
}

int readAxis(int thisAxis){
  int reading = analogRead(thisAxis);
  reading = map(reading, 0, 1032, 0, cursorSpeed);

  int distance = reading - center;

  if(abs(distance) < threshold) {
    distance = 0;
  }
  return distance;
}

