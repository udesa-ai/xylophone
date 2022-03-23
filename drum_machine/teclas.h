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
  void key_up(int key);
private:
  int angle2PWM(double x, int i);
  int delay1 = 50;
  int delay2 = 500;
  Adafruit_PWMServoDriver pca1;
  Adafruit_PWMServoDriver pca2;
  unsigned long delay_down[NTECLAS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int MIN_IMP[NTECLAS] = { 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500 };
  int MAX_IMP[NTECLAS] = { 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500 };
  int MIN_ANG[NTECLAS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int MAX_ANG[NTECLAS] = { 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180, 180 };
//                          1   2  3    4   5    6  7   8    9  10  11   12  13  14 15  16  17 18
  int CORECTOR[NTECLAS] = { 0, -8, 0, -14, -8, -14, 2, -3, -12, -5, -6, -14, -4, -6, 6, -5, -5, 4 };
  int low_note[NTECLAS] = { 0,  0, -2,   2, -1,   0, 0,  0,  -1,  0,  2,   0, -3,  -3,-1, -2,  0, 0 };
};
#endif
