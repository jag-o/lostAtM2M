// These constant integers are used to keep the pins constant.
const int enable1 = 9;
const int forward1 = 8;
const int backwards1 = 7;
const int enable2 = 10;
const int forward2 = 12;
const int backwards2 = 11;

// void setup() is used to run the code once only.
void setup() 
{
  // Initilizes the pins needed for the left motor.
  pinMode(forward1, OUTPUT);
  pinMode(backwards1, OUTPUT); 
  pinMode(enable1, OUTPUT);
  // Initilizes the pins needed for the right motor.
  pinMode(forward2, OUTPUT); 
  pinMode(enable2, OUTPUT); 
  pinMode(backwards2, OUTPUT);
  lightmeup(); // Runs lightmeup()!
}

void loop() 
{
  // Unused!
}

void lightmeup()
{
  // lightmeup() is the function used for making it go in a line for 10 seconds.
  // Enable the pins at full speed:
  digitalWrite(forward1, HIGH);
  digitalWrite(forward2, HIGH);
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);
  delay(10000); // Do this for ten seconds.
  // Turn off the pins.
  digitalWrite(forward1, LOW);
  digitalWrite(forward2, LOW);
  digitalWrite(enable1, LOW);
  digitalWrite(enable2, LOW);
 }