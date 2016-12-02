/* VU-Meter
 A horizontal RGB Strip is "divided" in the middle and shows the sound levels of a stereo signal 
 with lights propagating to left and right.
 
 Inspiration was taken from Jeremy Blum's Arduino Tutorial Series - Episode 14 - Lights and Sound Holiday Special
 Sample Code 2 - Driving all 160 LEDs using an array powered by both stereo channels
 http://www.jeremyblum.com
 
 Big Thanks to Daniel Garcia, Mark Kriegsman, Robert Atkins for all the work on the fantastic FASTLED Library.
 Mat Bettinson created awesome effects using the MSGEQ7 

 The most useful Tutorial on the MSGEQ7 was found here
 http://tronixstuff.com/2013/01/31/tutorial-arduino-and-the-msgeq7-spectrum-analyzer/  
 
 Hardware:
 RGB-Strip (the FASTLED lib supports most available Hardware !)
 Two MSGEQ7 7 Segment Graphic Equalizer IC
 
 The circuit:
 * A0 Left Channel
 * A1 Right Channel
 * Digital 4 Strobe
 * Digital 5 Reset
 * Digital 6 LED Data Pin
 * Digital 8 LED Clock Pin
 * use a stable 5V Power supply
 * Don't forget to connect all your grounds!

 J.Bruegl, May 2015 
 */

// LED setup
#include <FastLED.h>
#define NUM_LEDS          192
#define LED_PIN          2

#define COLOR_ORDER       GRB     // normally GRB ! There are also GBR strips out there
#define CHIPSET           NEOPIXEL  // WS2812b
#define POTPIN A0
#define MSGEQ7_PIN_L A0
#define MSGEQ7_PIN_R A1
#define strobe 4
#define reset 5
#define FRAMES_PER_SECOND  60

CRGB leds[NUM_LEDS];
//CHSV leds[NUM_LEDS];

//Set Strip Constants


//Set up arrays for cycling through all the pixels.  I'm assuming you have an even number of lights.
//uint32_t left_array[NUM_LEDS/2];
//uint32_t right_array[NUM_LEDS/2];
//uint32_t full_array[NUM_LEDS];
uint8_t gHue = 0;
// MSGEQ7 Equalizer DEFINITIONS

int left   [7]; // store band values in these arrays
int right  [7];
int band;
int LEFT  =  0;
int RIGHT =  0;
int BASS  =  0;
int MID   =  0;
int TREM  =  0;
/*
int BASS_L  =  0;
int MID_L   =  0;
int TREM_L  =  0;
int BASS_R  =  0;
int MID_R   =  0;
int TREM_R  =  0;
*/

//====CALIBRATION=============
unsigned long previous_calibration_time=0;
int calibration_update_rate = 200; //in ms
int calibration_map_max[5] = {0,0,0,0,0};         //{left_max,right_max,bass_max,mid_max,trem_max}, {left_min,right_min,bass_min,mid_min,trem_min}
int calibration_map_min[5] = {200,200,200,200,200}; 
int calibration_current[5] = {0,0,0,0,0};

int calibration_max[5]          = {0,0,0,0,0};

int calibration_max_array_LEFT[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_max_array_RIGHT[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_max_array_BASS[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_max_array_MID[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_max_array_TREM[10] = {0,0,0,0,0,0,0,0,0,0};

int calibration_min_array_LEFT[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_min_array_RIGHT[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_min_array_BASS[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_min_array_MID[10] = {0,0,0,0,0,0,0,0,0,0};
int calibration_min_array_TREM[10] = {0,0,0,0,0,0,0,0,0,0};
                                   
int calibration_min[5]          = {0,0,0,0,0};                               



int LEFT_MAX = 0;
int RIGHT_MAX = 0;
int BASS_MAX = 0;
int TREM_MAX = 0;
int MID_MAX = 0;
int LEFT_MIN = 1000;
int RIGHT_MIN = 1000;
int BASS_MIN = 1000;
int MID_MIN = 1000;
int TREM_MIN = 1000;




int brightness = 0;
int LeftSmooth[5] = {0,0,0,0,0};
int RightSmooth[5] = {0,0,0,0,0};
int RightSmoothed = 0;
int LeftSmoothed = 0;
int SmoothFactor=15; //Length of Left/Right Smooth Array: 1+2+3+4+5=15
int BassSmooth[5] = {0,0,0,0,0};
int BassSmoothed = 0;

int LSTART=0;
  int RSTART=0;
  int REND=0;
  int LEND=0;
int MitteDerStrippe=0;

void setup() {
  
  delay(2000);            // sanity check delay - allows reprogramming if accidently blowing power w/leds
  FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(115200);
  Serial.println("setup erfolgreich");
  delay(200);
MitteDerStrippe=NUM_LEDS/2;
  
  
    pinMode    (reset, OUTPUT);    // reset
    pinMode (strobe, OUTPUT);    // strobe
    //pinMode (POTPIN, INPUT);
    pinMode (MSGEQ7_PIN_L, INPUT);
    pinMode (MSGEQ7_PIN_R, INPUT);
    
    digitalWrite    (reset,LOW);   // reset low
    digitalWrite(strobe,HIGH);  

Serial.println("Setup Teil 2 Erfolgreich");
delay(200);
   
}

void loop()
{
  readBrightness();
  readMSGEQ7();
  writeBands();
  //Calibration();
  //minmax();
  NormalizeBands();
  SmoothBands();
  Animation01();
  FastLED.delay(1000/FRAMES_PER_SECOND);
  Serial.println();
}
