void Animation01()
{/*
 FastLED.clear();
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
  LEDS.show();
  */
  //=======================================
 
  
  FastLED.clear();
  MitteDerStrippe=NUM_LEDS/2;
  LSTART=((NUM_LEDS/2)+1);
  RSTART=NUM_LEDS/2;
  LEND=(MitteDerStrippe*BassSmoothed)/100+MitteDerStrippe+1;
  REND=MitteDerStrippe-MitteDerStrippe*BassSmoothed/100;
  int BRIGHT = 0.1*255*BassSmoothed/100+0.9*255;
      Serial.print("\t");
      Serial.print(LEND);
      Serial.print("\t");
      Serial.print(REND);
      Serial.print("\t");
      Serial.print(BRIGHT);
      Serial.print("\t");
  
    for (int L = LSTART; L <= LEND; L++) {
     
      leds [L] = CHSV(0, 255, BRIGHT);

    }

    for (int R = RSTART; R >= REND; R--) {
      leds [R] = CHSV(0, 255, BRIGHT );

    }
   // leds[NUM_LEDS]=CHSV(0,0,BRIGHT);
   // leds[NUM_LEDS+1]=CHSV(0,0,BRIGHT);
    /*
Serial.print((L-(NUM_LEDS/2))*200/NUM_LEDS);
Serial.print("\t");
Serial.print(((NUM_LEDS/2)-R)*200/NUM_LEDS);
*/
    LEDS.show();
   
}
