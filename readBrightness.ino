void readBrightness()
{
  brightness=255;
  //brightness = map(digitalRead(POTPIN),0,1023,1,255);
  LEDS.setBrightness(brightness);
  //Serial.println("brightness");
  
}
