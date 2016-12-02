void SmoothBands()
{
  for (int i=0; i<=3; i++)
  {BassSmooth[i]=BassSmooth[i+1];
    //LeftSmooth[i]=LeftSmooth[i+1];
    //RightSmooth[i]=RightSmooth[i+1];
    /*Serial.print(LeftSmooth[i]);
    Serial.print("\t");
    Serial.print(RightSmooth[i]);
    Serial.print("\t");*/
  }
  BassSmooth[4]=BASS;
  //LeftSmooth[4]=LEFT;
  //RightSmooth[4]=RIGHT;
/*Serial.print("\t");
  Serial.print("Smoothed");
  Serial.print("\t");
  Serial.print(LEFT);
  Serial.print("\t");
  Serial.print(RIGHT);
  Serial.print("\t");*/
  BassSmoothed=0;
  //LeftSmoothed=0;
  //RightSmoothed=0;

  for (int i=4; i>=0; i--)
  {
    //LeftSmoothed+=(i+1)*LeftSmooth[i]/SmoothFactor;
    //RightSmoothed+=(i+1)*RightSmooth[i]/SmoothFactor;
    BassSmoothed+=(i+1)*BassSmooth[i]/SmoothFactor;
  }

constrain(BassSmoothed, 0, 100);
 // constrain(LeftSmoothed, 0, (NUM_LEDS/2));
 // constrain(RightSmoothed, 0, (NUM_LEDS/2));


  
  
}
