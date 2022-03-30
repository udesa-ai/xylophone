#include <Adafruit_PWMServoDriver.h>

#define NTECLAS 18

#ifndef teclas_h
#define teclas_h
#include "Arduino.h" 
class Teclas {
public:
  Teclas();
  void initialize();
  void play_key(int key, int vel);
  void play_loop();
  void key_up(int key);
private:
  void key_startup();
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
//                                    1    2    3    4    5    6    7    8    9    10    11     12    13    14   15   16   17   18
  float CORECTOR[NTECLAS] =      {    0,  -7,  -1, -14, -10, -15,   1,  -3, -14, -6.8, -4.5, -12.5,   -4, -5.3,   7,  -7,  -6,   3 };
  float low_note_soft[NTECLAS] = { 45.5,  46,  44,  48,  45,  46,  46,  46,  45,   46,   48,    46,   43,   43,  45,  44,  46,  46 };
  float low_note_hard[NTECLAS] = {   40,  40,  38,  42,  39,  40,  40,  40,  39,   40,   42,    40,   37,   37,  39,  38,  40,  40 };
  float high_note[NTECLAS]=      {   57,  57,  57,  57,  57,  57,  57,  57,  57,   57,   57,    57,   57,   57,  57,  57,  57,  57 };
};
#endif
