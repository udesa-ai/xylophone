#include <Adafruit_PWMServoDriver.h>

#define NTECLAS

#ifndef teclas_h
#define teclas_h
#include "Arduino.h" 
class Teclas {
public:
  Teclas();
  void play_key(int key);
  void play_loop();
private:
  int delay1;
  int delay2;
  int delay_up[NTECLAS];
  int delay_down[NTECLAS];
  Adafruit_PWMServoDriver pca1;
  Adafruit_PWMServoDriver pca2;
};
#endif
