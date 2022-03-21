/*
simple drum machine for the pca9685 servos on channels 14 and 15
*/

#include "teclas.h"
#include <Adafruit_PWMServoDriver.h>
//Constants
#define nbPCAServo 16
//Parameters
int MIN_IMP[nbPCAServo] = { 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 };
int MAX_IMP[nbPCAServo] = { 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500 };
int MIN_ANG[nbPCAServo] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int MAX_ANG[nbPCAServo] = { 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180 };
int delay_down[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int delay_up[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int data = 0;
int data1 = 0;
int data2 = 0;
int delay1 = 500;
int delay2 = 200;


//Objects
Adafruit_PWMServoDriver pca1 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pca2 = Adafruit_PWMServoDriver(0x40);


void tecla_down(int tecla){
  if (tecla <10){
    pca1.writeMicroseconds(tecla-1, angle2PWM(40, tecla-1));
  } else {
    pca2.writeMicroseconds(tecla-1 - 9, angle2PWM(40, tecla-1 - 9));
  }
}

void tecla_up(int tecla){
  if (tecla <10){
    pca1.writeMicroseconds(tecla-1, angle2PWM(50, tecla-1));
  } else {
    pca2.writeMicroseconds(tecla-1 - 9, angle2PWM(50, tecla-1 - 9));
  }
}



void tocar_tecla(int tecla){
  int delay1 = 50;
  int delay2 = 100;
  if (tecla <10){
    pca1.writeMicroseconds(tecla-1, angle2PWM(40, tecla-1));
    delay(delay1);
    pca1.writeMicroseconds(tecla-1, angle2PWM(50, tecla-1));
    delay(delay2);// statement(s);
  } else {
    pca2.writeMicroseconds(tecla-1 - 9, angle2PWM(40, tecla-1 - 9));
    delay(delay1);
    pca2.writeMicroseconds(tecla-1 - 9, angle2PWM(50, tecla-1 - 9));
    delay(delay2);// statement(s);
  }
  
}

void pcaScenario() { /* function pcaScenario */
  ////Scenario to test servomotors controlled by PCA9685 I2C Module

  for (int i = 0; i<9; i++) {
    pca1.writeMicroseconds(i, angle2PWM(40, i));
    delay(50);
    pca1.writeMicroseconds(i, angle2PWM(50, i));
    delay(50);// statement(s);
  }
  for (int i = 0; i<9; i++) {
    pca2.writeMicroseconds(i, angle2PWM(40, i));
    delay(50);
    pca2.writeMicroseconds(i, angle2PWM(50, i));
    delay(50);// statement(s);
  }
  

    // for (int pos = MAX_IMP[i]; pos > MIN_IMP[i]; pos -= 10) {
    //   pca.writeMicroseconds(i, pos);
    //   delay(10);
    // }

}
int angle2PWM(double x, int i) { /* function angle2PWM */
                                 ////Convert joint angle into pwm command value

  int imp = (x - MIN_ANG[i]) * (MAX_IMP[i] - MIN_IMP[i]) / (MAX_ANG[i] - MIN_ANG[i]) + MIN_IMP[i];
  imp = max(imp, MIN_IMP[i]);
  imp = min(imp, MAX_IMP[i]);

  return imp;
}


void setup() {
  
  //Init Serial USB
  Serial.begin(9600);
  
  pca1.begin();
  pca1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pca2.begin();
  pca2.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  
  for(int i = 0; i<18; i++){
      tecla_down(i+1);
  }
  delay(200);
  for(int i = 0; i<18; i++){
      tecla_up(i+1);
  }
  Serial.println("Initialize System");
}


void loop() {
  while(true){
    if (Serial.available()>1){
      data1 = Serial.read() - 48;
      data2 = Serial.read() - 48;
      data = data1*10 + data2;
      Serial.println(data);
      tecla_down(data);
      delay_down[data-1] = millis() + delay1;
    }

    for(int i = 0; i<18; i++){
      if ((delay_down[i] != 0) and (millis() > delay_down[i])){
        tecla_up(i+1);
        delay_down[i] = 0;
      }
    }
  }
//  pcaScenario();
}
