// Initialize variables for pins and speed.
const int left_feedback_pin = 2;
const int right_feedback_pin = 3;
const int EnableLeft = 9;
const int ForwardsLeft = 8;
const int BackwardsLeft = 7;
const int EnableRight = 10;
const int ForwardsRight = 12;
const int BackwardsRight = 11;
const int LeftSpeed = 130;
const int RightSpeed = 255;
// These counters are used for the amount of times the feedback from the motors come through.
volatile unsigned int left_count = 0;
volatile unsigned int right_count = 0;
// These methods are used for increasing the counters if the interrupt is hit.
void left_pulse_interrupt() {
    left_count++;
}
void right_pulse_interrupt() {
    right_count++;
}
// checkCounter() is a method to readjust the motors speed to make the counters the same (hopefully).
void checkCounter() {
    if(left_count - right_count < 0) {
        RightSpeed = (RightSpeed - 20);
    }
    else if(left_count - right_count > 0) {
        LeftSpeed = (LeftSpeed - 20);
    }
}
void moveTheRover() {
    // Move the GODDAMN ROVER
    analogWrite(ForwardsLeft, LeftSpeed);
    analogWrite(ForwardsRight, RightSpeed);
    digitalWrite(EnableLeft, HIGH);
    digitalWrite(EnableRight, HIGH);
    delay(500);
    checkCounter();
    delay(500);
}
// setup() initializes the pins needed, and also attaches an interrupt.
void setup() {
    pinMode(left_feedback_pin, INPUT_PULLUP);
    pinMode(right_feedback_pin, INPUT_PULLUP);
    pinMode(ForwardsLeft, OUTPUT);
    pinMode(BackwardsLeft, OUTPUT);
    pinMode(EnableLeft, OUTPUT); 
    pinMode(ForwardsRight, OUTPUT); 
    pinMode(BackwardsRight, OUTPUT); 
    pinMode(EnableRight, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(left_feedback_pin), left_pulse_interrupt, RISING);
    attachInterrupt(digitalPinToInterrupt(right_feedback_pin), right_pulse_interrupt, RISING);
    Serial.begin(115200);
}
// loop() is where we'll be using the above code to check these counters and make sure it progresses in a line.
void loop() {
    moveTheRover();
}