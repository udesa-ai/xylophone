#include <Adafruit_PWMServoDriver.h>

#define NTECLAS 18

#ifndef teclas_h
#define teclas_h
#include "Arduino.h" 
class Teclas {
public:
  Teclas();
  void initialize();
  void play_key(int key);
  void play_loop();
private:
  int angle2PWM(double x, int i);
  void key_up(int key);
  int delay1 = 50;
  int delay2 = 500;
  Adafruit_PWMServoDriver pca1;
  Adafruit_PWMServoDriver pca2;
  int delay_down[NTECLAS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int MIN_IMP[NTECLAS] = { 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 };;
  int MAX_IMP[NTECLAS] = { 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500 };
  int MIN_ANG[NTECLAS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int MAX_ANG[NTECLAS] = { 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180 };
};
#endif
