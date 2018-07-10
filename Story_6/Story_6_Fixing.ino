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

volatile unsigned int left_count = 0;
volatile unsigned int right_count = 0;

void left_pulse_interrupt() {
    left_count++;
}
void right_pulse_interrupt() {
    right_count++;
}
void checkCounter() {
    if(left_count - right_count < 0) {
        RightSpeed = (RightSpeed - 20);
    }
    else if(left_count - right_count > 0) {
        LeftSpeed = (LeftSpeed - 20);
    }
}
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
void loop() {
    checkCounter();
    delay(250);
}