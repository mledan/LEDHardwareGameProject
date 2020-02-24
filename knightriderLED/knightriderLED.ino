// Neopixel LED Pong with hardware buttons 2020 Mladen Milesic
// Based on NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 8 MHz ATTiny85
#endif

 ///////////////////////////////////////////////////////////////
//                         +---\/---+                          //
//                    PB5  |1*     8|  VCC -- +5V              //
//                    PB3  |2      7|  PB2                     //
// PLAYER 1 BUTTON -- PB4  |3      6|  PB1 -- NEOPIXEL DATA    //
//              0V -- GND  |4      5|  PB0 -- PLAYER 2 BUTTON  //
//                         +--------+                          //
 ///////////////////////////////////////////////////////////////   
                   
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        1 // USING ATTINY85 PINOUT

// constants won't change. They're used here to set pin numbers:
#define buttonPin  4     // the number of the pushbutton pin
#define buttonPin2 0    // the number of the pushbutton pin

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8 // Popular NeoPixel strip size
#define pixelON 255
// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 75 // Time (in milliseconds) to pause between pixels
#define DELAYMOMENTUM 15 // Time (in milliseconds) to pause between pixels to resolve momentum, typically want this to be 100 times less than delayval <---

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 8000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
// initialize the LED pin as an output:
  pinMode(5, OUTPUT);    // sets the digital pin 5 as output
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(15);
  pixels.clear();
  //ShowPixelsSplash();

}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(pixelON, 0, 0)); 
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

  for (int i = NUMPIXELS-1; i > -1; i--) { // For each pixel...
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(pixelON, 0, 0)); 
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop  
  }

    
}
