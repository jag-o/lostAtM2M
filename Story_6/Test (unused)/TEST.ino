const int left_feedback_pin = 2;
const int right_feedback_pin = 3;
const int EnableLeft = 9;
const int ForwardsLeft = 8;
const int BackwardsLeft = 7;
const int EnableRight = 10;
const int ForwardsRight = 12;
const int BackwardsRight = 11;
void setup() {
  pinMode(ForwardsLeft, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(BackwardsLeft, OUTPUT); // Yellow led represents the robot moving backwards.
  pinMode(EnableLeft, OUTPUT); // Red led represents the robot turning on.
  pinMode(ForwardsRight, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(EnableRight, OUTPUT); // Red led` represents the robot turning on.
  pinMode(BackwardsRight, OUTPUT); // Yellow led represents the robot moving backwards.
  lightmeup();
}
void lightmeup() {
    digitalWrite(ForwardsLeft, HIGH);
    digitalWrite(ForwardsRight, HIGH);
    digitalWrite(EnableLeft, HIGH);
    digitalWrite(EnableRight, HIGH);
    delay(3000);
    digitalWrite(ForwardsLeft, LOW);
    digitalWrite(ForwardsRight, HIGH);
    digitalWrite(EnableLeft, LOW);
    digitalWrite(EnableRight, HIGH);
    delay(400);
    digitalWrite(ForwardsLeft, HIGH);
    digitalWrite(ForwardsRight, HIGH);
    digitalWrite(EnableLeft, HIGH);
    digitalWrite(EnableRight, HIGH);
    delay(5000);
    digitalWrite(ForwardsLeft, LOW);
    digitalWrite(ForwardsRight, HIGH);
    digitalWrite(EnableLeft, LOW);
    digitalWrite(EnableRight, HIGH);
    delay(300);
    digitalWrite(ForwardsLeft, HIGH);
    digitalWrite(ForwardsRight, HIGH);
    digitalWrite(EnableLeft, HIGH);
    digitalWrite(EnableRight, HIGH);
    delay(1000);
    digitalWrite(ForwardsLeft, LOW);
    digitalWrite(ForwardsRight, LOW);
    digitalWrite(EnableLeft, LOW);
    digitalWrite(EnableRight, LOW);
    
}
void loop() {

}
