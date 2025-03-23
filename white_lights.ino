#include "FastLED.h"
// number of LEDs in the strip (just guess)
#define NUM_LEDS 80
// arduino digital pin used to control LEDs
#define DATA_PIN1 2
#define DATA_PIN2 3
#define DATA_PIN3 4
#define DATA_PIN4 5
#define DATA_PIN5 6
#define DATA_PIN6 7
// declare the LED strip 
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
CRGB leds5[NUM_LEDS];
CRGB leds6[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS); 
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds2, NUM_LEDS); 
  FastLED.addLeds<NEOPIXEL, DATA_PIN3>(leds3, NUM_LEDS); 
  FastLED.addLeds<NEOPIXEL, DATA_PIN4>(leds4, NUM_LEDS); 
  FastLED.addLeds<NEOPIXEL, DATA_PIN5>(leds5, NUM_LEDS); 
  FastLED.addLeds<NEOPIXEL, DATA_PIN6>(leds6, NUM_LEDS); 
}

void loop() {
  unsigned long cycleTime = millis() % 6000;
  CRGB nutWhite = CRGB(255, 255, 255);

  if (cycleTime < 3000) {
    // On phase: calculate which step (0-5) we are on. Each step is 500ms.
    int step = cycleTime / 500;
    // When step = 0, only the first strip is lit;
    // when step = 1, strips 1 and 2 are lit; etc.
    if (step >= 0) fill_solid(leds1, NUM_LEDS, nutWhite);
    if (step >= 1) fill_solid(leds2, NUM_LEDS, nutWhite);
    if (step >= 2) fill_solid(leds3, NUM_LEDS, nutWhite);
    if (step >= 3) fill_solid(leds4, NUM_LEDS, nutWhite);
    if (step >= 4) fill_solid(leds5, NUM_LEDS, nutWhite);
    if (step >= 5) fill_solid(leds6, NUM_LEDS, nutWhite);
  } 
  else {
    // Off phase
    fill_solid(leds1, NUM_LEDS, CRGB::Black);
    fill_solid(leds2, NUM_LEDS, CRGB::Black);
    fill_solid(leds3, NUM_LEDS, CRGB::Black);
    fill_solid(leds4, NUM_LEDS, CRGB::Black);
    fill_solid(leds5, NUM_LEDS, CRGB::Black);
    fill_solid(leds6, NUM_LEDS, CRGB::Black);
  }

  FastLED.show();
}