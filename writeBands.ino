void writeBands()
{//Serial.println("beginn write");

    for (band = 0; band < 7; band++)
  {
    LEFT  = (left[0]  + left[1]  + left[2]  + left[3]  + left[4]  + left[5]  + left[6]);
    RIGHT = (right[0] + right[1] + right[2] + right[3] + right[4] + right[5] + right[6]);
    BASS  = (left[0]  + left[1]  + right[0] + right[1]);
    //BASS = (left[0]+right[0])*2;
    MID   = (left[2]  + left[3]  + right[2] + right[3]);
    TREM  = (left[4]  + left[5]  + right[4] + right[5]);
    /* Certainly it can also devided in BASS_L, BASS_R, MID_L, MID_R, TREM_L, and TREM_R .. (use a different mapping) */
    /*BASS_L  = (left[0]  + left[1] );
    BASS_R  = (right[0] + right[1]);
    MID_L   = (left[2]  + left[3]);
    MID_R   = (right[2] + right[3]);
    TREM_L  = (left[4]  + left[5]);
    TREM_R  = (right[4] + right[5]);*/
  }
   /* There is way too much data available from the two MSGEQ7 (14 values each reading)
     A method is just to group and sum up 
     */
   

   /*
      // just to see the values coming in to decide on mapping
     Serial.print(LEFT);
     Serial.print("\t");
     Serial.print(RIGHT);
     Serial.print("\t");
     Serial.print(BASS);
     Serial.print("\t");
     Serial.print(MID);
     Serial.print("\t");
     Serial.print(TREM);
     Serial.print("\t");
     Serial.println(" | ");
     */

/*
for (int i=0; i<7; i++)
{ Serial.print(left[i]);
Serial.print("\t");
}
Serial.print(" | ");
Serial.print("\t");
Serial.print(LEFT);
//Serial.println();
*/
}   
