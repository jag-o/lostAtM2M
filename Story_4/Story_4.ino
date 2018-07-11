// These constant integers are used to keep the pins constant.
const int enable1 = 9;
const int forward1 = 8;
const int backwards1 = 7;
const int enable2 = 10;
const int forward2 = 12;
const int backwards2 = 11;

void setup() {
  // setup() initilizes the pins.
  pinMode(forward1, OUTPUT); 
  pinMode(enable1, OUTPUT);
  pinMode(backwards1, OUTPUT);
  pinMode(forward2, OUTPUT); 
  pinMode(enable2, OUTPUT); 
  pinMode(backwards2, OUTPUT);
}

void loop()
{
  // loop() will happen forever. This loop() makes it go forwards for one second, stop, then go forwards for one second again.
  // Go forward
  digitalWrite(forward1,HIGH);
  digitalWrite(enable1,HIGH);
  digitalWrite(forward2,HIGH);
  digitalWrite(enable2,HIGH);
  delay(1000); // Wait for one second
  // Disable all motors
  digitalWrite(forward1,LOW);
  digitalWrite(enable1,LOW);
  digitalWrite(forward2,LOW);
  digitalWrite(enable2,LOW);
  delay(1000); // Wait for one second
  // Go forward
  digitalWrite(enable1,HIGH);
  digitalWrite(backwards1,HIGH);
  digitalWrite(enable2,HIGH);
  digitalWrite(backwards2,HIGH);
  delay(1000); // Wait for one second
  // Disable all motors
  digitalWrite(enable1,LOW);
  digitalWrite(backwards1,LOW);
  digitalWrite(enable2,LOW);
  digitalWrite(backwards2,LOW);
  delay(1000); // Wait for one second
}