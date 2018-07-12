const int EnableLeft = 9;
const int ForwardsLeft = 8;
const int BackwardsLeft = 7;
const int EnableRight = 10;
const int ForwardsRight = 12;
const int BackwardsRight = 11;
void setup() {
    pinMode(ForwardsLeft, OUTPUT);
    pinMode(BackwardsLeft, OUTPUT);
    pinMode(EnableLeft, OUTPUT); 
    pinMode(ForwardsRight, OUTPUT); 
    pinMode(BackwardsRight, OUTPUT); 
    pinMode(EnableRight, OUTPUT);
    fourTimes();
}

void moveForwards(){
  //MOVES THE ROVER FORAWRDS
  digitalWrite(ForwardsLeft, HIGH);
  digitalWrite(ForwardsRight, HIGH);
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
  digitalWrite(BackwardsLeft, LOW);
  digitalWrite(BackwardsRight, LOW);
  delay(1000);
}

void moveForwardsMore(){
  //MOVES THE ROVER FORAWRDS MORE
  digitalWrite(ForwardsLeft, HIGH);
  digitalWrite(ForwardsRight, HIGH);
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
  digitalWrite(BackwardsLeft, LOW);
  digitalWrite(BackwardsRight, LOW);
  delay(1250);
}

void halt(){ 
  //HALTS THE ROBOT
  digitalWrite(ForwardsLeft, LOW);
  digitalWrite(ForwardsRight, LOW);
  digitalWrite(EnableLeft, LOW);
  digitalWrite(EnableRight, LOW);
  digitalWrite(BackwardsLeft, LOW);
  digitalWrite(BackwardsRight, LOW);
  delay(1500);
  }


void turn90Degrees(){
  //TURNS THE ROVER 90 DEGREES ANTICLOCKWISE
  digitalWrite(ForwardsLeft, LOW);
  digitalWrite(ForwardsRight, HIGH);
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
  digitalWrite(BackwardsLeft, HIGH);
  digitalWrite(BackwardsRight, LOW);
  delay(539);
}
void fourTimes(){
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
  turn90Degrees();
  halt();
   moveForwardsMore();
  halt();
  delay(100000000);
}
void loop() {
  }
