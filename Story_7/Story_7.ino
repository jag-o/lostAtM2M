// These constant integers define the pins needed for movement.
const int EnableLeft = 9;
const int ForwardsLeft = 8;
const int BackwardsLeft = 7;
const int EnableRight = 10;
const int ForwardsRight = 12;
const int BackwardsRight = 11;

void setup()
{
  // void setup() initilizes the pins needed for spinning, only runs once.
  pinMode(ForwardsLeft, OUTPUT);
  pinMode(BackwardsLeft, OUTPUT);
  pinMode(EnableLeft, OUTPUT); 
  pinMode(ForwardsRight, OUTPUT); 
  pinMode(BackwardsRight, OUTPUT); 
  pinMode(EnableRight, OUTPUT);
  // Runs the fourTimes() code.
  fourTimes();
}

void moveForwards()
{
  // moveForwards() moves the rover forwards for 1 second.
  // Turns the forwards motors on on each rover.
  digitalWrite(ForwardsLeft, HIGH);
  digitalWrite(ForwardsRight, HIGH);
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
  delay(1000); // Does this for one second.
}

void halt()
{ 
  // halt() halts the robot for 1.5 seconds.
  // Disables all motors:
  digitalWrite(ForwardsLeft, LOW);
  digitalWrite(ForwardsRight, LOW);
  digitalWrite(EnableLeft, LOW);
  digitalWrite(EnableRight, LOW);
  digitalWrite(BackwardsLeft, LOW);
  digitalWrite(BackwardsRight, LOW);
  delay(1500); // Does this for 1.5 seconds.
}

void turn90Degrees()
{
  // turn90Degrees() turns the rover using the opposite forwards and backwards motors.
  // Turns the right motor on going forwards, and turns the left motor on going backwards.
  digitalWrite(ForwardsLeft, LOW);
  digitalWrite(ForwardsRight, HIGH);
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
  digitalWrite(BackwardsLeft, HIGH);
  digitalWrite(BackwardsRight, LOW);
  delay(540); // Does this for .540 of a second.
}

void turn90DegreesMore() {
  // turn90DegreesMore() is a copy of turn90Degrees(), however the delay is increased to compensate for the ground.
  // Turns the right motor on going forwards, and turns the left motor on going backwards.
  digitalWrite(ForwardsLeft, LOW);
  digitalWrite(ForwardsRight, HIGH);
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
  digitalWrite(BackwardsLeft, HIGH);
  digitalWrite(BackwardsRight, LOW);
  delay(570); // Does this for .570 of a second.
}

void fourTimes()
{
  // fourTimes() sticks the above methods into a simple function for easy calling.
  moveForwards();
  halt();
  turn90Degrees();
  halt();
  moveForwards();
  halt();
  turn90Degrees();
  halt();
  moveForwards();
  halt();
  turn90DegreesMore();
  halt();
  moveForwards();
  halt();
  delay(100000000); // Waits for 1.16 days!
}

void loop()
{
  // Unused code, however Arduino has a fit if you don't include it.
}