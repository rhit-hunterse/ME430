#include <Servo.h>

#define PIN_PUSHBUTTON 2
#define PIN_LED 3
#define PIN_JOYSTICK_X 0
#define PIN_JOYSTICK_Y 1
#define PIN_SERVO 9

Servo myServo; //Construct servo object
String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
 
int joystickX;
int lastSentJoystickX=0;
int joystickY;
int lastSentJoystickY=0;
const int JOYSTICK_THRESHOLD=15; //Same as define (either works)

void setup() {
  Serial.begin(9600);
  inputString.reserve(200); // reserve 200 bytes for the inputString:
 
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_PUSHBUTTON, INPUT_PULLUP);

  myServo.attach(PIN_SERVO);
}

void loop() {
  if (!digitalRead(2)) {
    Serial.println("B");
    delay(500);
  }
// Joystick stuff goes here!
  joystickX= analogRead(PIN_JOYSTICK_X);
  if (abs(joystickX-lastSentJoystickX)> JOYSTICK_THRESHOLD){
    Serial.println(String("X ")+joystickX);
    lastSentJoystickX=joystickX;
  }
  
  joystickY= analogRead(PIN_JOYSTICK_Y);
  if (abs(joystickY-lastSentJoystickY)> JOYSTICK_THRESHOLD){
    Serial.println(String("Y ")+joystickY);
    lastSentJoystickY=joystickY;
  }
  // print the string when a newline arrives:
  if (stringComplete) {
    inputString.toUpperCase(); //mutates (upper and lower case)
    inputString.trim(); //Gets rid of the CR ASCII Value 13
    Serial.println(inputString); //Optional send to MATLAB
    
    // step 1: do something with the message
    if (inputString.equalsIgnoreCase("LED ON")){
      digitalWrite(PIN_LED,HIGH); // turns led oN
    } 
    
    if (inputString.equalsIgnoreCase("LED OFF")){
        digitalWrite(PIN_LED,LOW); //Turns led off 
    } 

      if (inputString.startsWith("SERVO ")) {
      int numDegrees=inputString.substring(6).toInt(); //6, because thats when number shoes up
        myServo.write(numDegrees); //controls servo
        delay(250);

    
  } 
    
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); //serial.read gets int and converts to a char
    
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') { //Line feed. ASCII value 10 (either works)
      stringComplete = true;
    }else { //else statement removes the period from printing
      // add it to the inputString:
    inputString += inChar;
    }
  }
}