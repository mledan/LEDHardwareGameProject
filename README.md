# LEDHardwareGameProject
A 1-dimensional pong inspired hardware project using the ATTiny85 microcontroller

PARTS LIST
-----------
-ATTiny85 Microcontroller
-USBISP programmer for ATTiny85
-8xNeopixel strip
-wires

ATTiny85 PINOUT
----------------
```
                         +---\/---+                          
    RESET BUTTON -- PB5  |1*     8|  VCC -- +5V              
PLAYER 1 SCORE OUT--PB3  |2      7|  PB2 -- PLAYER 1 BUTTON                    
PLAYER 2 SCORE OUT--PB4  |3      6|  PB1 -- NEOPIXEL DATA    
              0V -- GND  |4      5|  PB0 -- PLAYER 2 BUTTON  
                         +--------+                          
```

Potential Future Enhancements Backlog
---------------------------
-push button actions
-7segment Digit LED Display score keeping
-8x8 matrix version with multidimensions
-gamify
-network play
-raspberry pi port
-python port
-web version javascript port

