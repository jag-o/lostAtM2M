/* 
 * Software Cornwall MeArm Robot Arms
 * Under Tools 
 * set the Board to Spark Fun Pro Micro
 * set the processor to ATmega32U4 (5v, 16MHz)
*/

#include <Servo.h>

const int NUMBER_OF_SERVO = 4;
int PIN[NUMBER_OF_SERVO], value[NUMBER_OF_SERVO];
Servo servo[NUMBER_OF_SERVO];


/*
* Servo number 0 is middle servo
* Servo number 1 is left servo
* Servo number 2 is right servo
* Servo number 3 is claw servo
*/

/*
 * When entering positions keep within these limits
 * middle servo minimum position is 15, maximum is 180
 * left servo minimum position is 81, maximum is 158
 * right servo minimum position is 70, maximum is 156
 * claw servo minimum position is 70, maximum is 180
 */

// These are the series of positions the servos will move to.
int arrayPositions [][4]{   // The bracket is for the rows, the second is number of servo (columns)
  //{80, 145, 90, 147},       // Start Position angles of the four servos in order
  
  {62, 88, 90, 100},       // Turn right, open claw
  {62, 106, 131, 100},      // Move down & forward
  {62, 106, 131, 147},      // Close claw
  {62, 106, 71, 147},       // Move back
  {114, 88, 123, 147},      // Turn left
  {114, 88, 123, 100},      // Release claw
  {114, 88, 90, 100}        // Back off
};


void setup() {
  // setup runs only at start, once.
    Serial.begin(9600);

  // create four servo objects numbered from Zero to 3
for(int number=0; number < NUMBER_OF_SERVO; number++){
  Servo servo[number];
}

  // attach the four servo to their pins
servo[0].attach(10);
servo[1].attach(9);
servo[2].attach(6);
servo[3].attach(5);

}
  

void loop() {
  // main code goes here looping through from Zero to 3 and Zero to 4
  // like this 0,0 - 0,1 - 0,2 - 0,3 - 1,0 - 1,1 - 1,2 etc
  // these are then the posions of the servo from the arrayPositions above
  
  for(int i = 0; i < 7; i++){                    // CHANGE THE NUMBER FOR i < ? TO NUMBER OF ROWS
    for(int j = 0; j < NUMBER_OF_SERVO; j++){    // j is the number of the servos called in turn
      int servoPosition = arrayPositions[i][j];
      servo[j].write(servoPosition);
      Serial.println("Servo number:");
      Serial.println(j);
      Serial.println("Servo Position:");
      Serial.println(servoPosition);
      Serial.println("");
      delay(500);
    }
  }

}

