/**** Covid Candy Dispenser ****/

#include <Stepper.h>

// Distance Sensor HC-SR04:
#define echoPin 2 // echo pin to arduino digital pin 2
#define trigPin 3 // trig pin to arduino digital pin 3

// Distance Sensor Variables:
long duration;  // variable for ping travel time
float distance; // variable for distance measurement
/* change the maxDistance to the highest distance recorded
   while aiming where the trick-or-treaters will be standing
   (in inches 72" = 6') */
const int maxDistance = 120;

// Stepper Motor 28BYJ-48:
// Number of steps per Motor Revolution
const float stepsPerRev = 32;

// Amount of Gear Reduction for 28BYJ-48 Stepper Motor
const float gearRed = 64;

// Number of steps per geared output rotation
const float stepsOutPerRev = stepsPerRev * gearRed;

// Define Variables:
int stepsRequired;

// Create an Instance of Stepper Class:
/* Specify Pins used for Stepper Motor Coils
   The Pins Used ie. 4,5,6,7 for Arduino Uno
   Connected to 28BYJ-48 Motor Driver In1(4), In2(5), In3(6), In4(7)
   Pins entered in sequence 1-3-2-4 for proper stepping sequence
*/
Stepper stepperMotor(stepsPerRev, 4, 6, 5, 7);


// Millis Timer:
const unsigned long eventInterval = 1000; // 10 seconds between candy dispensing change if needed
unsigned long startTime;
unsigned long currentTime;


void setup() {
  // Distance Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Millis Timer start
  startTime = millis();
  // debug
  Serial.begin(9600);

}

void loop() {
  Serial.println("Start Program");
  // might need to check timer then check distance...

  // check distance sensor:

  // Clears the trigPin condition for a clean High ping
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = microsecondsToInches(duration);

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" inches");


  if (distance < maxDistance) {
    currentTime = millis();
    if (currentTime - startTime >= eventInterval) {
      startTime = currentTime;
      Serial.println("Dispense Candy");
      // Rotate CCW 1/2 turn quickly
      stepsRequired = - stepsOutPerRev; // / 2;
      stepperMotor.setSpeed(900);
      stepperMotor.step(stepsRequired);
      delay(2000);

      Serial.println("Done Dispensing");

    }

    Serial.println("Inside distance");

  }
  
}

// get distance in inches
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}
