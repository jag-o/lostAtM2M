// These constant integers define the pins for later use of variables.

const int enable = 9; //This line tells the arduino to use pin9without this line the rover will NOT move at all

const int forward = 8; //This line tells the rover to use pin8 for the forwards motor, without this line the rover will NOT move forwards

const int backwards = 7; //This line tells the arduino to use pin7 for the backwards motor, without this line the rover will NOT move backwards








void setup(){
//Void setup is where all the setting-up code is stored, like telling the arduino what the motors will do

  pinMode(forward, OUTPUT);     //The forwards motor will OUTPUT a responce
  
  pinMode(enable, OUTPUT);      //THe enable motor will OUTPUT a responce
  
  pinMode(backwards, OUTPUT);   //The backwards motor wil OUTPUT a responce
}





void blink(){
//Void blink is a function that tells the motors to have a HIGH intensity for 1 second, then a LOW intensity for one second. This is repeated infinatly
  
  digitalWrite(forward,HIGH);   // Enable forward motor
  
  digitalWrite(enable,HIGH);    // Enable enable motor
  
  delay(1000);                  // Wait for 1 second.
  
  digitalWrite(forward,LOW);    // Disable forward motor
  
  digitalWrite(enable,LOW);     // Disable enable motor
  
  delay(1000);                  // Wait for 1 second.
  
  digitalWrite(enable,HIGH);    // Enable enable motor
  
  digitalWrite(backwards,HIGH); // Enable backwards motor
  
  delay(1000);                  // Wait for 1 second.
  
  digitalWrite(enable,LOW);     // Disable enable motor
  
  digitalWrite(backwards,LOW);  // Disable backwards motor 
  
  delay(1000);                  // Wait for 1 second.
  
                                //Delays are counted in miliseconds, therefore 1000 miliseconds = one second
}




void loop()
{
  // loop() will run forever. This loop() runs blink() forever 
  
  blink(); // Run blink()
}
