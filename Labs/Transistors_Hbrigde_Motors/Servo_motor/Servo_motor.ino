#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int potValue; //declares a global variable 
int degrees; //declares a global variable

void setup(){
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  // outputs for debugging LEDs
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  // outputs for servo
  myservo.attach(9); //what pin to attach servo to pin 9
}

void loop(){
  //outputs for the debugging LEDs
  digitalWrite(4, !digitalRead(2)); //exclamation point means "inverse of"
  digitalWrite(5, !digitalRead(3));
  analogWrite(6, analogRead(0)/4); 
  
  //Outputs for transistors, H-bridge, etc
  if (!digitalRead(2)) {  //digital read get value of pin. not pressing=high, do press button grounds it and brings it low
     myservo.write(0); //short task
  } else if (!digitalRead(3)) { //assuming first thing is false, then ask 2nd question. 2nd question not asked if first thing is true
    myservo.write(180); //task: how far to turn
  } else {
    potValue=analogRead(0); // value ranges from 0 to 1023 (analogRead(0) is where the potentiometer is plugged in)
    degrees= map(potValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo.write(degrees);
  }
  
  delay(10);
}