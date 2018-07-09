
void setup() {
  // initialize LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(50);                       // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(2, HIGH);    // turn the LED off by making the voltage LOW
  delay(50);                       // wait for a second
}
