#include <Stepper.h>

const int stepsPerRevolution = 2048;  // 32 steps * 64:1 gearhead; change this to fit the number of steps per revolution
// for your motor

//const int stepsPerRevolution = 60; //Tell a LIE for now!
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // Order is important (1st two arguments= pair and 2nd two= pair)

void setup() {
  // set the speed at 5 rpm:
  myStepper.setSpeed(5); //based on math
}

void loop() {
  // step one revolution  in one direction:
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
