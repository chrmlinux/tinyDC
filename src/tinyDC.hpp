#ifndef __TINYDC_HPP__
#define __TINYDC_HPP__

#define FREQ (2048)
#define BIT (8)

#include <Arduino.h>

class tinyDC {

  public:
    tinyDC(void) {};
    ~tinyDC(void) {};


    void begin(int pin1, int pin2, int ch, float fact) {
      _pin1 = pin1;
      _pin2 = pin2;
      _ch = ch;
      _fact = fact;
      pinMode(_pin1, OUTPUT);
      pinMode(_pin2, OUTPUT);
      ledcSetup(_ch, FREQ, BIT);
      ledcAttachPin(_pin2, _ch);
    }

    void pwm(int pwr) {
      ledcWrite(_ch, pwr);
    }

    void cntr(int spd) {
      int pwr = abs(spd) * _fact;
      if (spd > 0) {
        digitalWrite(_pin1, HIGH);
        pwm(255 - (pwr * 0.9));
      } else {
        digitalWrite(_pin1,  LOW);
        pwm(pwr);
      }
    }

  private:
    int _pin1;
    int _pin2;
    int _ch;
    float _fact;;
};

#endif
