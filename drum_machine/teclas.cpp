#include "teclas.h"


Teclas::Teclas() {
  
}

void Teclas::initialize(){
  pca1 = Adafruit_PWMServoDriver(0x41);
  pca2 = Adafruit_PWMServoDriver(0x40);
  pca1.begin();
  pca1.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  pca2.begin();
  pca2.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
  
//  for(int i = 0; i< NTECLAS; i++){
//      delay(100);
//      play_key(i);
//      delay_down[i] = 0;
//  }
  
}

void Teclas::play_key(int key){
  if (delay_down[key] == 0){
    if (key < 9){
      pca1.writeMicroseconds(key, angle2PWM(40 + low_note[key], key));
    } else {
      pca2.writeMicroseconds(key - 9, angle2PWM(40 + low_note[key], key));
    }
    delay_down[key] = millis() + delay1;
  }
  
}

void Teclas::key_up(int key){
  delay_down[key] = 0;
  if (key < 9){
    pca1.writeMicroseconds(key, angle2PWM(57, key));
  } else {
    pca2.writeMicroseconds(key - 9, angle2PWM(57, key));
  }
}




void Teclas::play_loop(){
  for(int i = 0; i<NTECLAS; i++){
      if ((delay_down[i] != 0) and (millis() > delay_down[i])){
        key_up(i);
      }
    }
}

int Teclas::angle2PWM(double x, int i) { /* function angle2PWM */
                                 ////Convert joint angle into pwm command value
  x += CORECTOR[i];
  
  int imp = (x - MIN_ANG[i]) * (MAX_IMP[i] - MIN_IMP[i]) / (MAX_ANG[i] - MIN_ANG[i]) + MIN_IMP[i];
  imp = max(imp, MIN_IMP[i]);
  imp = min(imp, MAX_IMP[i]);

  return imp;
}
