// These constant variables keep the pins in names, in case they need to change.
const int left_feedback_pin = 2;
const int right_feedback_pin = 3;
const int EnableLeft = 9;
const int ForwardsLeft = 8;
const int BackwardsLeft = 7;
const int EnableRight = 10;
const int ForwardsRight = 12;
const int BackwardsRight = 11;
// These variables are not constant so the speed can be changed on the fly.
int LeftSpeed = 140;
int RightSpeed = 155;
// These counters are used for the amount of times the feedback from the motors come through.
volatile unsigned int left_count = 0;
volatile unsigned int right_count = 0;
// These methods are used for increasing the counters if the interrupt is hit.



void left_pulse_interrupt()
{
  left_count++;
}

void right_pulse_interrupt()
{
  right_count++;
}

// checkCounter() is a method to readjust the motors speed to make the counters the same (hopefully).



void checkCounter() 
{
  if(left_count > right_count) // If the left motor is becoming faster than the right motor:
  {
    digitalWrite(EnableLeft, LOW); // Disable the left motor
    delay(215); // Run the right motor on its own for 215 milliseconds, to adjust
    digitalWrite(EnableLeft, HIGH); // Re-enable the left motor.
  }
  else if(right_count > left_count) // Else, if the right motor is becoming faster than the left motor:
  {
    digitalWrite(EnableRight, LOW); // Disable the right motor
    delay(215); // Run the left motor on its own for 215 milliseconds, to adjust
    digitalWrite(EnableRight, HIGH); // Re-enable the right motor.
  }
  else 
  { 
    // Else, if somehow one motor is not faster than the other:
    LeftSpeed = 150; // Do not adjust the speeds.
    RightSpeed = 140;
  }
}




// setup() initializes the pins needed, and also attaches an interrupt.
void setup()
{
  pinMode(left_feedback_pin, INPUT_PULLUP); // Initializes the left feedback pin.
  pinMode(right_feedback_pin, INPUT_PULLUP); // Initializes the right feedback pin.
  // Enables the default right and left motor enable, forwards, and backwards.
  pinMode(ForwardsLeft, OUTPUT);
  pinMode(BackwardsLeft, OUTPUT);
  pinMode(EnableLeft, OUTPUT); 
  pinMode(ForwardsRight, OUTPUT); 
  pinMode(BackwardsRight, OUTPUT); 
  pinMode(EnableRight, OUTPUT);
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
  // attachInterrupt is a method used to declare interrupts for the pins.
  attachInterrupt(digitalPinToInterrupt(left_feedback_pin), left_pulse_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(right_feedback_pin), right_pulse_interrupt, RISING);
}




// loop() is where we'll be using the above code to check these counters and make sure it progresses in a line.
void loop() 
{
  int rovertime = millis(); // rovertime is a variable for the time the rover is live. The arduino stores its uptime in millis.
  if(rovertime < 8000) // 8000 millseconds is the time to make it go 2 metres.
  {
    // If the rovertime is under 8 seconds, do this code!
    analogWrite(ForwardsLeft, LeftSpeed); // Get the left motor to go at the defined speed.
    analogWrite(ForwardsRight, RightSpeed); // Get the right motor to go at the defined speed.
    delay(800); // Wait for 800 ms
    checkCounter(); // Check the current offset.
    delay(800); // Wait for another 800 ms.
  }
}
