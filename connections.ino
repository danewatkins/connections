
// ThingPulse SSD1306 library
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

#include "top.h"
#include "bottom.h"
//#include "bot2.h"
#include "SSD1306Spi.h"
#include "SH1106Spi.h"
// ------------------begin ESP8266'centric----------------------------------
#define FREQUENCY    160                  // valid 80, 160
//
#include "ESP8266WiFi.h"

// ------------------end ESP8266'centric------------------------------------
//SSD1306Spi        display(D0, D2, 18);
SH1106Spi       display(D0, D2, 18);

uint8_t i = 0;
uint8_t j = 0;
void setup() {
  /* Initializations */
  // ------------------begin ESP8266'centric----------------------------------
  WiFi.forceSleepBegin();                  // turn off ESP8266 RF

  // ------------------end ESP8266'centric------------------------------------
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(D8, OUTPUT);
  pinMode(D4, OUTPUT);

  digitalWrite(D8, LOW);
  digitalWrite(D4, LOW);


  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.init();
  // init done


  digitalWrite(D8, HIGH);
  display.flipScreenVertically();
  digitalWrite(D4, HIGH);


}

void loop() {
  display.clear();

  //block one
  digitalWrite(D8, LOW);
  display.drawRect(127, 63, 1, 1);
  display.drawXbm( 0, 0, 128, 64, top[j]);
  display.display();
  digitalWrite(D8, HIGH);

  display.clear();

  display.drawRect(0, 0, 1, 1);



  //block two
  digitalWrite(D4, LOW);
  display.drawXbm(0 , 0, 128, 64, bot[j]);
  display.display();
  digitalWrite(D4, HIGH);

  if (j == 29) {
    j = 0;
  } else {
    j++;
  }

  delay(100);

  //  display.clear();
}
