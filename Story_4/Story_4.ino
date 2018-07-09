const int enable = 9;
const int forward = 8;
const int backwards = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(forward, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(enable, OUTPUT); // Red led represents the robot turning on.
  pinMode(backwards, OUTPUT); // Yellow led represents the robot moving backwards.
}

void loop() {
  digitalWrite(forward,HIGH);
  digitalWrite(enable,HIGH);
  delay(1000);
  digitalWrite(forward,LOW);
  digitalWrite(enable,LOW);
  delay(1000);
  digitalWrite(enable,HIGH);
  digitalWrite(backwards,HIGH);
  delay(1000);
  digitalWrite(enable,LOW);
  digitalWrite(backwards,LOW);
  delay(1000);
}
