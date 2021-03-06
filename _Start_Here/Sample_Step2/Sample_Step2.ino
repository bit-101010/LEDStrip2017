/*
 * Wired Wizards 2017 LED example code level 2: Advanced Timing! 
 * by Benjamin Davis
 * 
 * This version is intended to be the third step into the Arduino/NeoPixel environment.
 * 
 * Why:
 * Because our robot may have more than one strip, or may need to do multiple things at the same time, we don't want to use delay(time).
 * 
 * The NeoPixel library is critical to this code. This can be installed following the instructions at https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-installation.
 * 
 */



#include <Adafruit_NeoPixel.h> //adds the neopixel library to the code. This library handles the data going to the strip.

void blink(int r, int g, int b, int wait); //Prototype of the blink function.

Adafruit_NeoPixel blinky = Adafruit_NeoPixel(32, 6, NEO_GRB + NEO_KHZ800); // creates an Adafruit_NeoPixel named "blinky" 32 pixels long, on pin 6. The NEO_GRB + NEO_KHZ800 is magical stuff that the Neopixels library needs to operate.

int red = 48; //these values determine the color being used.
int green = 0; // these values go from 0 to 255, 0 being off and 255 being full power: Full Power is Very Bright!
int blue = 64; //the colors combine to create a single, RGB color.
int frameLength = 1000;

void setup() {
  // put your setup code here, to run once:
  blinky.begin(); // starts the strip running.
  blinky.show(); //displays the default color, all black.
}

void loop() {
  // put your main code here, to run repeatedly:
  blink (red, green, blue, frameLength); //blinks the led once on and off.
  
  blinky.show(); //because the code doesn't have to wait on any delays, we will put this at the end of the code, after all of the changes have been made.
}

void blink(int r, int g, int b, int wait)
{
  static unsigned long startTime = millis(); //gets the current processor time, in milliseconds, and makes it static, meaning the value will stay not reset every time we call the function.
  int frame = (millis() - startTime)/wait; //Calculates which frame of the animation we are on by taking the time elapsed and dividing by how long each frame should be.
  frame %= 2; //evaluates the remainder of frame / 2, then saves that value to frame. This means that odd numbers will return 1, and even numbers will return 0. 
  if(frame == 0){ // the "==" means is egual to, and is used as a comparison. A single "=" would set the value of frame to 0. Not what you want!
    for(int i = 0; i < blinky.numPixels(); i++){ //starts at pixel 0, then adds one until you reach the end of the strip.
      blinky.setPixelColor(i, r, g, b); //paints pixel "i" according the the color values (the last three parameters in setPixelColor).
    }
  } else { // if (frame != 0). this runs if the above condition is not satisfied. Becuase frame will either be equal to 
    for(int i = 0; i < blinky.numPixels(); i++){ //steps through each pixel
      blinky.setPixelColor(i, 0, 0, 0); //and sets them to off (black).
    }
  }
}

