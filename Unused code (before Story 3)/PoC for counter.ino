const int left_feedback_pin = 2;
const int right_feedback_pin = 3;
const int EnableLeft = 9;
const int ForwardsLeft = 8;
const int BackwardsLeft = 7;
const int EnableRight = 10;
const int ForwardsRight = 12;
const int BackwardsRight = 11;

volatile unsigned int left_count = 0;
volatile unsigned int right_count = 0;
void left_pulse_interrupt() {
    left_count++;
}
void right_pulse_interrupt() {
    right_count++;
}
void setup() {
    pinMode(left_feedback_pin, INPUT_PULLUP);
    pinMode(right_feedback_pin, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(left_feedback_pin), left_pulse_interrupt, RISING);
    attachInterrupt(digitalPinToInterrupt(right_feedback_pin), right_pulse_interrupt, RISING);

    Serial.begin(115200);
}
void loop() {
    delay(100);
    Serial.writeln(left_count);
    Serial.writeln(right_count);
}