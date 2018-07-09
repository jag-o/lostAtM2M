const int enable1 = 9;
const int forward1 = 8;
const int enable2 = 10;
const int forward2 = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(forward1, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(enable1, OUTPUT); // Red led represents the robot turning on.
  pinMode(forward2, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(enable2, OUTPUT); // Red led` represents the robot turning on.

  analogWrite(forward1, 80);
  analogWrite(forward2, 100);
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
}
