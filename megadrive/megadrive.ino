// ****************************************************************************************************************
//
//  Megadrive Controller -> USB Keyboard
//  
//  A simple program which converts the input of the megadrive controller, to that of a USB keyboard.
//  
//  Please Note:
//  
//  REQUIRES at least ARDUINO LEONARDO - as uses 'Keyboard' libraries unavaliable to older versions of the board.
//  
//  Settings:
//  
//  Please use the below to select the pin that you are to be using, and the key that you would like to be output 
//  from the keyboard when that button is pressed.
//
//  Arduino Pin Headers:
//
//  A and B pin:
const int abPin = 13;
// Start and C pin:
const int startCPin = 12;
// Up pin:
const int upPin = 11;
// Down pin:
const int downPin = 10;
// Left pin:
const int leftPin = 9;
// Right pin:
const int rightPin = 8;
// Select pin:
const int selectPin = 7;

// USB Keyboard Output:
//
// Please note if you wish to use any special keys, refer to:
// http://arduino.cc/en/Reference/KeyboardModifiers
// 
// A Keyboard Output:
const char aOutput = 'i';
// B Keyboard Output:
const char bOutput = 'o';
// C Keyboard Output:
const char cOutput = 'p';
// Start Keyboard Output:
const char startOutput = ' ';
// Up Keyboard Output:
const char upOutput = 'w';
// Down Keyboard Output:
const char downOutput = 's';
// Left Keyboard Output:
const char leftOutput = 'a';
// Right Keyboard Output:
const char rightOutput = 'd';
//
// That's all, everything below this stars is the lovely but simple program for running the converstion.
//
// ****************************************************************************************************************

// boolean for keeping track of SELECT
boolean selectHigh;

void setup() {
    // Start SELECT as high
    selectHigh = true;
    // A and B  
    pinMode(abPin, INPUT);
    // Start and C
    pinMode(startCPin, INPUT);
    // Up
    pinMode(upPin, INPUT);
    // Down
    pinMode(downPin, INPUT);
    // Left
    pinMode(leftPin, INPUT);
    // Right
    pinMode(rightPin, INPUT);
    // SELECT line
    pinMode(selectPin, OUTPUT);
    // Start SELECT as high
    digitalWrite(selectPin, HIGH);

    // Start USB keyboard output
    Keyboard.begin();
}

void loop() {
    // Check Select line
    if(selectHigh) {
        // B
        !digitalRead(abPin) ? Keyboard.press(bOutput) : Keyboard.release(bOutput);
        // C
        !digitalRead(startCPin) ? Keyboard.press(cOutput) : Keyboard.release(cOutput);
        // Up
        !digitalRead(upPin) ? Keyboard.press(upOutput) : Keyboard.release(upOutput);
        // Down
        !digitalRead(downPin) ? Keyboard.press(downOutput) : Keyboard.release(downOutput);
        // Left
        !digitalRead(leftPin) ? Keyboard.press(leftOutput) : Keyboard.release(leftOutput);
        // Right
        !digitalRead(rightPin) ? Keyboard.press(rightOutput) : Keyboard.release(rightOutput);
        // Change Select line
        selectHigh = false;
        digitalWrite(selectPin, LOW);
    }
    else {
        // A
        !digitalRead(abPin) ? Keyboard.press(aOutput) : Keyboard.release(aOutput);
        // Start
        !digitalRead(startCPin) ? Keyboard.press(startOutput) : Keyboard.release(startOutput);
        // Up
        !digitalRead(upPin) ? Keyboard.press(upOutput) : Keyboard.release(upOutput);
        // Down
        !digitalRead(downPin) ? Keyboard.press(downOutput) : Keyboard.release(downOutput);
        // Change Select line
        selectHigh = true;
        digitalWrite(7, HIGH);
    }
}`
