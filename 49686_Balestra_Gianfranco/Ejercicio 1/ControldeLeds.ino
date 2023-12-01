const int ledPin1 = 9;
const int ledPin2 = 10;
const int buttonPin1 = 4;
const int buttonPin2 = 7;
const int buttonPin3 = 8;

int brightness1 = 0;
int brightness2 = 255;
bool usingLed1 = true;
bool button3Pressed = false;

enum State {
  IDLE,
  INC_LED1,
  DEC_LED1,
  INC_LED2,
  DEC_LED2,
  CHANGE_LED
};

State currentState = IDLE;
State previousState = IDLE;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
}

void loop() {
  switch (currentState) {
    case IDLE:
      if (digitalRead(buttonPin1) == LOW) {
        if (usingLed1) {
          currentState = INC_LED1;
        } else {
          currentState = INC_LED2;
        }
      } else if (digitalRead(buttonPin2) == LOW) {
        if (usingLed1) {
          currentState = DEC_LED1;
        } else {
          currentState = DEC_LED2;
        }
      } else if (digitalRead(buttonPin3) == LOW && !button3Pressed) {
        currentState = CHANGE_LED;
        button3Pressed = true;
      } else if (digitalRead(buttonPin3) == HIGH && button3Pressed) {
        button3Pressed = false;
      }
      break;

    case INC_LED1:
      if (brightness1 < 255) {
        brightness1++;
      }
      analogWrite(ledPin1, brightness1);
      if (digitalRead(buttonPin1) != LOW) {
        currentState = IDLE;
      }
      break;

    case DEC_LED1:
      if (brightness1 > 0) {
        brightness1--;
      }
      analogWrite(ledPin1, brightness1);
      if (digitalRead(buttonPin2) != LOW) {
        currentState = IDLE;
      }
      break;

    case INC_LED2:
      if (brightness2 < 255) {
        brightness2++;
      }
      analogWrite(ledPin2, brightness2);
      if (digitalRead(buttonPin1) != LOW) {
        currentState = IDLE;
      }
      break;

    case DEC_LED2:
      if (brightness2 > 0) {
        brightness2--;
      }
      analogWrite(ledPin2, brightness2);
      if (digitalRead(buttonPin2) != LOW) {
        currentState = IDLE;
      }
      break;

    case CHANGE_LED:
      usingLed1 = !usingLed1;
      if (usingLed1) {
        analogWrite(ledPin1, brightness1);
        analogWrite(ledPin2, 0);
      } else {
        analogWrite(ledPin2, brightness2);
        analogWrite(ledPin1, 0);
      }
      currentState = IDLE;
      break;
  }
}