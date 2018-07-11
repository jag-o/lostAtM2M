const x = D3;

void setup() {
  // initialize LED_BUILTIN as an output.
  pinMode(x, OUTPUT);
  pinMode(D2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(x, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(D2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(x, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(D2, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
