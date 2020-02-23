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
#define NUMPIXELS 8 // Popular NeoPixel ring size
#define pixelON 255
#define trail1 pixelON/4
#define trail2 pixelON/9
#define trail3 pixelON/16
#define trail4 pixelON/25
#define trail5 pixelON/36
#define trail6 pixelON/49
#define trail7 pixelON/64
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
  pinMode(5, OUTPUT);    // sets the digital pin 13 as output
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setBrightness(15);
  pixels.clear();
  //ShowPixelsSplash();

}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    
 
    switch(i){
      case 0:
      pixels.setPixelColor(0, pixels.Color(pixelON, 0, 0));
    //                                    |
    // Here be LIGHT------> Momentum DOWN V
    
      pixels.setPixelColor(1, pixels.Color(trail1, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail6, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail7, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 1:
      pixels.setPixelColor(0, pixels.Color(trail1, 0, 0));

      pixels.setPixelColor(1, pixels.Color(pixelON, 0, 0));
    //                                    |
    // Here be LIGHT------> Momentum DOWN V
      pixels.setPixelColor(2, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail6, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail7, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 2:
      pixels.setPixelColor(0, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail1, 0, 0));
    
      pixels.setPixelColor(2, pixels.Color(pixelON, 0, 0));
    //                                    |
    // Here be LIGHT------> Momentum DOWN V
      pixels.setPixelColor(3, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail6, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
      
    case 3:
      pixels.setPixelColor(0, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail1, 0, 0));

      pixels.setPixelColor(3, pixels.Color(pixelON, 0, 0));
    //                                    |
    // Here be LIGHT------> Momentum DOWN V
      pixels.setPixelColor(4, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail5, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 4:
      pixels.setPixelColor(0, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail1, 0, 0));

      pixels.setPixelColor(4, pixels.Color(pixelON, 0, 0));
    //                                    |
    // Here be LIGHT------> Momentum DOWN V
      pixels.setPixelColor(5, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail4, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 5:
      pixels.setPixelColor(0, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail1, 0, 0));

      pixels.setPixelColor(5, pixels.Color(pixelON, 0, 0));
      
    //                                    |
    // Here be LIGHT------> Momentum DOWN V
      pixels.setPixelColor(6, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail3, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 6:
      pixels.setPixelColor(0, pixels.Color(trail6, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail1, 0, 0));

      pixels.setPixelColor(6, pixels.Color(pixelON, 0, 0));
    //                                    |
    // Here be LIGHT------> Momentum DOWN V
      pixels.setPixelColor(7, pixels.Color(trail2, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 7:


    //resolve momentum
    for(int j = 1; j<50*.2; j++){ // adjust how much should be resolved with that j limiter (resolution of changes?)
      pixels.setPixelColor(0, pixels.Color(trail7/j, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail6/j, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail5/j, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail4/j, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail3/j, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail2/j, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail1/j, 0, 0));  
      pixels.setPixelColor(7, pixels.Color(pixelON, 0, 0));
      //                                    |
    // Here be LIGHT------> Momentum DOWN V
      pixels.show();
      delay(DELAYMOMENTUM);
      }
      break;
    default:
      break;
    }

    
 

   
    
  }

  


  
  for (int i = NUMPIXELS-1; i > -1; i--) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    //pixels.clear();
   
    

    // set trailing leds
   switch(i){
    case 7:
      pixels.setPixelColor(0, pixels.Color(trail7, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail6, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail1, 0, 0));
    // Here be LIGHT------> Momentum UP ^
    //                                  |
    pixels.setPixelColor(7, pixels.Color(pixelON, 0, 0));
    
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 6:
      pixels.setPixelColor(0, pixels.Color(trail6, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail1, 0, 0));
    // Here be LIGHT------> Momentum UP ^
    //                                  |     
      pixels.setPixelColor(6, pixels.Color(pixelON, 0, 0));
    
      pixels.setPixelColor(7, pixels.Color(trail1, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
   case 5:
      pixels.setPixelColor(0, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail1, 0, 0));
    // Here be LIGHT------> Momentum UP ^
    //                                  |   
    pixels.setPixelColor(5, pixels.Color(pixelON, 0, 0));  
     
      pixels.setPixelColor(6, pixels.Color(trail1, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail2, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break; 
    
    case 4:
      pixels.setPixelColor(0, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail1, 0, 0));
    // Here be LIGHT------> Momentum UP ^
    //                                  |
    pixels.setPixelColor(4, pixels.Color(pixelON, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail1, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail3, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 3:
      pixels.setPixelColor(0, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail1, 0, 0));
    // Here be LIGHT------> Momentum UP ^
    //                                  |
    pixels.setPixelColor(3, pixels.Color(pixelON, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail1, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail4, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    
    case 2:
      pixels.setPixelColor(0, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(1, pixels.Color(trail1, 0, 0));
    // Here be LIGHT------> Momentum UP ^
    //                                  |
    pixels.setPixelColor(2, pixels.Color(pixelON, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail1, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail5, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 1:
      pixels.setPixelColor(0, pixels.Color(trail1, 0, 0));
    // Here be LIGHT------> Momentum UP ^
    //                                  |
    
      pixels.setPixelColor(1, pixels.Color(pixelON, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail1, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail2, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail3, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail4, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail5, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail6, 0, 0));
      
  pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
      break;
    case 0:
    
     //resolve momentum
    for(int j = 1; j<50*.2; j++){ // adjust how much should be resolved with that j limiter (resolution of changes?)
      

      pixels.setPixelColor(0, pixels.Color(pixelON, 0, 0));
      // Here be LIGHT------> Momentum UP ^
      //                                  |
      pixels.setPixelColor(1, pixels.Color(trail1/j, 0, 0));
      pixels.setPixelColor(2, pixels.Color(trail2/j, 0, 0));
      pixels.setPixelColor(3, pixels.Color(trail3/j, 0, 0));
      pixels.setPixelColor(4, pixels.Color(trail4/j, 0, 0));
      pixels.setPixelColor(5, pixels.Color(trail5/j, 0, 0));
      pixels.setPixelColor(6, pixels.Color(trail6/j, 0, 0));
      pixels.setPixelColor(7, pixels.Color(trail7/j, 0, 0));
      pixels.show();
      delay(DELAYMOMENTUM);
      }
    default:
      //return false;
      break;
    }    
  
  }

    
}
