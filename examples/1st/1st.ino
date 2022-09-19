#include "tinyDC.hpp"

static tinyDC dcR;
static tinyDC dcL;
#define PIN1 (33)
#define PIN2 (23)
#define PIN3 (19)
#define PIN4 (22)

void dcTrnR(void) {
  Serial.println("TrnR");
  // value -255..0..255
  // value is minus CCW. value is plus CW. 
  dcR.cntr(-128);
  dcL.cntr( 128);
}

void dcTrnL(void) {
  Serial.println("TrnL");
  dcR.cntr( 128);
  dcL.cntr(-128);
}

void dcFwd(void) {
  Serial.println("Fwd");
  dcR.cntr( 128);
  dcL.cntr( 128);
}

void dcBak(void) {
  Serial.println("Bak");
  dcR.cntr(-128);
  dcL.cntr(-128);
}

void dcStp(void) {
  Serial.println("Stp");
  dcR.cntr(0);
  dcL.cntr(0);
}

void setup(void) {
  Serial.begin( 115200 ); while(!Serial); delay(100);
  dcR.begin(PIN1, PIN2, 0, 1.0); // PIN1/PIN2/CH/FACT
  dcL.begin(PIN3, PIN4, 1, 1.0); // PIN3/PIN4/CH/FACT
}

void loop(void) {
  dcFwd();
  delay(2000);
  dcBak();
  delay(2000);
  dcTrnR();
  delay(2000);
  dcTrnL();
  delay(2000);
}
