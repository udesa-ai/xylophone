/*
simple drum machine for the pca9685 servos on channels 14 and 15
*/

#include "teclas.h"

//Parameters
int data = 0;
int data1 = 0;
int data2 = 0;

Teclas keyboard = Teclas();

void setup() {
  //Init Serial USB
  keyboard.initialize();
  Serial.begin(57600);
  Serial.println("Initialize System");
  
}


void loop() {
  if (Serial.available()>1){
    data1 = Serial.read() - 48;
    data2 = Serial.read() - 48;
    data = data1*10 + data2;
    Serial.println(data);
    keyboard.play_key(data-1);
  }

  keyboard.play_loop();
//  pcaScenario();
}
