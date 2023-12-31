/// @file    Pride2015.ino
/// @brief   Animated, ever-changing rainbows.
/// @example Pride2015.ino

#include "FastLED.h"

// Pride2015
// Animated, ever-changing rainbows.
// by Mark Kriegsman

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    8
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER BRG
#define NUM_LEDS    72
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];
bool gReverseDirection = false;
char var;
char var2;
int cache;
long timeCapture;
int dim = 20;
float brt = 0;
bool TorF = true;
int temp = 1;
int offset = 0;
int POS = 0;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns


void setup() {

  delay(3000); // 3 second delay for recovery

  Serial.begin(9600);
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  fill_solid(leds,NUM_LEDS,CRGB(0,0,255));

  FastLED.clear();

}


void loop()
{

  choose();


  if (millis() - timeCapture >= 10800000){

    var = 'O';

  }


  FastLED.show();  
}

void choose()
{
  if(Serial.available()){

    var = Serial.read();
    timeCapture = millis();
    FastLED.clear();

  }
  
  

  if(var == 'P')
  {
      pride();
  }

  if(var == 'C')
  {
      Cylon();
  }

  if(var == 'O')
  {
      FastLED.clear();  // clear all pixel data
      FastLED.show();
  }

  if(var == 'W')
  {
      fill_solid(leds,NUM_LEDS,CRGB(255,255,255));
      FastLED.show();
  }

  if(var == 'S')
  {
      sinelon();
  }

  if(var == 'G')
  {
      Fire2012();
  }

  if(var == 'R')
  {

      randomLights();

  }

  if(var == 'A')
  {

      randomLightsOn();

  }

  if(var == 'B')
  {

      bups();

  }

  if(var == 'Q')
  {

      phaseBeat();

  }

  if(var == 'V')
  {

      PrettyFill();

  }

  if(var == 'U')
  {

      ColorWipe();

  }

  if(var == 'Z')
  {

      Arcade();

  }

    if(var == 'I')
  {

      RGB_Calibrate();

  }

      if(var == 'D')
  {

      Canada();

  }


  if(isDigit(var))
  {
    
    if(var == '9')
    {
      brt = 255;
    }
    
    if(var == '0')
    {
      brt = 25.5;
    }

    if(var == '1')
    {
      brt = 51;
    }
    
    if(var == '2')
    {
      brt = 76.5;
    }
    
    if(var == '3')
    {
      brt = 102;
    }
    
    if(var == '4')
    {
      brt = 127.5;
    }
    
    if(var == '5')
    {
      brt = 153;
    }
    
    if(var == '6')
    {
      brt = 178.5;
    }
    
    if(var == '7')
    {
      brt = 204;
    }
    
    if(var == '8')
    {
      brt = 229.5;
    }


    FastLED.setBrightness(brt);
    Serial.print(brt);

    var = var2;


  }

  var2 = var;
  
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(10000); } }


void Canada(){

  int firHal = NUM_LEDS/4;
  int secHal = (NUM_LEDS/4) * 3;
  int thiHal = (NUM_LEDS/4) * 2;

  fill_solid(leds,NUM_LEDS,CRGB::Red);
  fill_solid(leds,secHal,CRGB(255,255,255));
  fill_solid(leds,thiHal + 1,CRGB::Red);
  fill_solid(leds,thiHal - 2,CRGB(255,255,255));
  fill_solid(leds,firHal,CRGB::Red);


}

void RGB_Calibrate()
{

    leds[0] = CRGB(255,0,0);
    leds[1] = CRGB(0,255,0);
    leds[2] = CRGB(0,255,0);
    leds[3] = CRGB(0,0,255);
    leds[4] = CRGB(0,0,255);
    leds[5] = CRGB(0,0,255);
    leds[6] = CRGB(0,0,0);

}

void Arcade(){


  FastLED.clear();  // clear all pixel data



  uint8_t pos = map(beat16(120, 0), 0, 65535, 2, 5);

  int temppos = pos;

  leds[pos] = CRGB(107, 71, 0);

  while(temppos > 1 && temppos < NUM_LEDS-1)
  {

    leds[temppos] = CRGB(107, 71, 0);

    temppos++;
    temppos++;
    temppos++;

  }

  if(pos == 3){

    leds[0] = CRGB(107, 71, 0);

  }

  if(pos == 4){

    leds[1] = CRGB(107, 71, 0);

  }



  
}

void ColorWipe(){

      int R;
      int G;
      int B;

      int pos = beatsin16( 13, -1, NUM_LEDS );

    if(pos == -1 || pos == NUM_LEDS && cache != pos)
    {

      R = random(0,255);
      G = random(0,255);
      B = random(0,255);

    }

    leds[pos].setRGB( R, G, B);

    cache = pos;

}


void PrettyFill(){

  uint8_t octaves = 1;
  uint16_t x = 0;
  int scale = 100;
  uint8_t hue_octaves = 1;
  uint16_t hue_x = 1;
  int hue_scale = 50;
  uint16_t ntime = millis() / 3;
  uint8_t hue_shift = 5;
  
  fill_noise16 (leds, NUM_LEDS, octaves, x, scale, hue_octaves, hue_x, hue_scale, ntime, hue_shift);
  FastLED.show();

}

void phaseBeat(){



      int R;
      int G;
      int B;

      int pos = beatsin16( 13, -1, NUM_LEDS );

    if(pos == -1 && cache != pos)
    {

      R = random(0,255);
      G = random(0,255);
      B = random(0,255);

      TorF = true;

    }
    else if (pos == NUM_LEDS && cache != pos)
    {

      R = random(0,255);
      G = random(0,255);
      B = random(0,255);

      TorF = false;

    }

  if((pos % 2) == 0 && TorF == true){
    leds[pos].setRGB( R, G, B);
  }
  else if((pos % 2) == 1 && TorF == false){
    leds[pos].setRGB( R, G, B);
  }

    cache = pos;

}

void bups()
{

    int var;

    if(random(1, 300) == 1)
    {

      var = random(0,NUM_LEDS);
      int R = random(0,255);
      int G = random(0,255);
      int B = random(0,255);

      leds[var].setRGB( R, G, B);



    }

      fadeToBlackBy(leds, NUM_LEDS, 3);

    


}

void randomLightsOn()
{

  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  int R;
  int G;
  int B;

  if(pos != cache)
  {


      R = random(0,255);
      B = random(0,255);
      G = random(0,255);

  
  }
  

  leds[pos].setRGB(R, G, B);

  cache = pos;

}

void randomLights()
{

  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  int R;
  int G;
  int B;

  if(pos != cache)
  {
  if(random(1,3) == 1)
  {

      R = 0;
      G = 0;
      B = 0;

  }
  else
  {

      R = random(0,255);
      B = random(0,255);
      G = random(0,255);

  }
  }
  

  leds[pos].setRGB(R, G, B);

  cache = pos;

}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void Cylon() { 
	static uint8_t hue = 0;
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( hue++, 255, 192);
}



void Fire2012()
{


    static uint8_t hue = 0;
    fill_solid(leds,NUM_LEDS,CHSV( (hue++), 255, 192));
  

}

void pride() 
{

  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;
 
  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 1, 3000);
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t brightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < NUM_LEDS; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    CRGB newcolor = CHSV( hue8, sat8, bri8);
    
    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS-1) - pixelnumber;
    
    nblend( leds[pixelnumber], newcolor, 64);
  }
  
}
