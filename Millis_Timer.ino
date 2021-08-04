/********** Millis Timer **********/

const unsigned long eventInterval = 4000;
unsigned long startTime = 0;
unsigned long currentTime;


void setup() {
  Serial.begin(9600);

}

void loop() {

  currentTime = millis();
  if (currentTime - startTime >= eventInterval) {
    startTime = currentTime;
    if ((currentDistance < maxDistance) && (currentDistance != previousDistance){
      // dispense candy
    }
    
  } 

}
