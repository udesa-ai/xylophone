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
  
  for(int i = 0; i<NTECLAS; i++){
      play_key(i);
  }
  delay(200);
  for(int i = 0; i < NTECLAS; i++){
      key_up(i);
  }
}

void Teclas::play_key(int key){
  if (key < 9){
    pca1.writeMicroseconds(key, angle2PWM(40, key));
  } else {
    pca2.writeMicroseconds(key - 9, angle2PWM(40, key-9));
  }
  delay_down[key] = millis() + delay1;
}

void Teclas::key_up(int key){
  if (key < 9){
    pca1.writeMicroseconds(key, angle2PWM(50, key));
  } else {
    pca2.writeMicroseconds(key - 9, angle2PWM(50, key-9));
  }
}




void Teclas::play_loop(){
  for(int i = 0; i<NTECLAS; i++){
      if ((delay_down[i] != 0) and (millis() > delay_down[i])){
        key_up(i);
        delay_down[i] = 0;
      }
    }
}

int Teclas::angle2PWM(double x, int i) { /* function angle2PWM */
                                 ////Convert joint angle into pwm command value
  int imp = (x - MIN_ANG[i]) * (MAX_IMP[i] - MIN_IMP[i]) / (MAX_ANG[i] - MIN_ANG[i]) + MIN_IMP[i];
  imp = max(imp, MIN_IMP[i]);
  imp = min(imp, MAX_IMP[i]);

  return imp;
}
