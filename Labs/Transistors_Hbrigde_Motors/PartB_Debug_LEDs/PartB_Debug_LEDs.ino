void setup(){
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  // outputs for debugging LEDs
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  // outputs for transistors, H-bridge, etc
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop(){
  //outputs for the debugging LEDs
  digitalWrite(4, !digitalRead(2)); //exclamation point means "inverse of"
  digitalWrite(5, !digitalRead(3));
  analogWrite(6, analogRead(0)/4); 
  
  //Outputs for transistors, H-bridge, etc
  digitalWrite(12, !digitalRead(2)); //exclamation point means "inverse of"
  digitalWrite(13, !digitalRead(3));
  analogWrite(11, analogRead(0)/4); 
  
  delay(10);
}