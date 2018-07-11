// These constant integers define the pins for later use of variables.
const int enable = 9;
const int forward = 8;
const int backwards = 7;

void setup()
{
  // setup() runs once. In this method, it defines the pins in pinMode().
  pinMode(forward, OUTPUT); // Blue led represents the robot moving forwards.
  pinMode(enable, OUTPUT); // Red led represents the robot turning on.
  pinMode(backwards, OUTPUT); // Yellow led represents the robot moving backwards.
}

void blink()
{
  // blink() is a method for representing how the motors work on the rover in terms of LEDs.
  digitalWrite(forward,HIGH); // Enable forward LED
  digitalWrite(enable,HIGH); // Enable enable lED
  delay(10000); // Wait for 10 seconds.
  digitalWrite(forward,LOW); // Disable forward LED
  digitalWrite(enable,LOW); // Disable enable LED
  delay(1000); // Wait for a second.
  digitalWrite(enable,HIGH); // Enable enable LED
  digitalWrite(backwards,HIGH); // Enable backwards LED
  delay(1000);  // Wait for a second.
  digitalWrite(enable,LOW); // Disable enable LED
  digitalWrite(backwards,LOW); // Disable backwards LED
  delay(1000); // Wait for a second.
}

void loop()
{
  // loop() will run forever. This loop() runs blink() forever.
  blink(); // Run blink().
}