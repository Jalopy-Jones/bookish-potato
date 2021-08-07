/* using 1 analog pin to read input data from a 4x4 keypad matrix
 *  
Connections:
   390 ohm resistors connected in series between rows
   1.5k ohm resistors connected in series between columns
   a .01uf capacitor between the signal pin and ground (103 ceramic cap)
   a 390 ohm resistor connected between the signal pin and row 0
   a 4.1k ohm resistor connected between 5v and row 0
   ground pin connected to column 3
   
** be sure that the rows are not connected to the columns **

   connect ground to gnd
   connect 5v to 5v
   connect signal pin to Analog(0) on Arduino Uno
*/

// enter analog values from the 4x4 keypad for later use :

// 1 =
// 2 =
// 3 =
// A =
// 4 =
// 5 =
// 6 =
// B =
// 7 =
// 8 =
// 9 =
// C =
// * =
// 0 =
// # =
// D =


/*
  // convert the inputs into the corresponding keypad options:
  int thresholds[5] = {214, 160, 123, 560, 531};
  char keypad[5] = {'1', '2', '3', '*', '#'};
*/

void setup() {
  // Start Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // print button press value to monitor
  int value = analogRead(A0); // connect to pin A0
  Serial.println(value);
  delay(100);
  /*
    // print the keypad value instead of the voltage
    for(int i = 0; i <= 5; i += 1){
      if (analogRead(A0) == thresholds[i]){
        Serial.println(keypad[i]);
      }
    }
  */
}// loop end
