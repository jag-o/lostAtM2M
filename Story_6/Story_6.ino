const int left_feedback_pin = 2;
const int right_feedback_pin = 3;
const int enable1 = 9;
const int forward1 = 8;
const int backwards1 = 7;
const int enable2 = 10;
const int forward2 = 12;
const int backwards2 = 11;

volatile unsigned int left_count = 0;
volatile unsigned int right_count = 0;


void left_pulse_interrupt()
{
  left_count++;
}

void right_pulse_interrupt()
{
  right_count++;
}


void setup() {
  pinMode(forward1, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(backwards1, OUTPUT); // Yellow led represents the robot moving backwards.
  pinMode(enable1, OUTPUT); // Red led represents the robot turning on.
  pinMode(forward2, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(enable2, OUTPUT); // Red led` represents the robot turning on.
  pinMode(backwards2, OUTPUT); // Yellow led represents the robot moving backwards.
  pinMode(left_feedback_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(left_feedback_pin), left_pulse_interrupt, RISING);
  pinMode(right_feedback_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(right_feedback_pin), right_pulse_interrupt, RISING);
  Serial.begin(115200);
  Serial.println("This is a test line");
}
  // put your setup code here, to run once:


void loop() {
  delay(300);
  analogWrite(forward1, 130);
  analogWrite(forward2, 255);
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  analogWrite(forward1, 0);
  analogWrite(forward2, 0);
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
  
  Serial.println("Left motor:");
  Serial.println(left_count);
  Serial.println("Right motor:");
  Serial.println(right_count);
}

void lightmeup() {
  analogWrite(forward1, 130);
  analogWrite(forward2, 255);
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  delay(8000);
  analogWrite(forward1, 0);
  analogWrite(forward2, 0);
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
  exit(0);
} 


