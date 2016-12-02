void NormalizeBands()
{Serial.print(BASS);
Serial.print("\t");
    LEFT  = constrain(map(LEFT,  400, 1800,  0, (NUM_LEDS/2)), 0, (NUM_LEDS/2));
    RIGHT = constrain(map(RIGHT, 1000, 3000,  0,  (NUM_LEDS/2)),  0,  (NUM_LEDS/2));
    BASS  = constrain(map(BASS,  400, 3000,   5, 100),  5, 100);
    MID   = constrain(map(MID,   190, 2800,   0, 255),  0, 255);
    TREM  = constrain(map(TREM,  200, 2500,   0, 255),  0, 255);
Serial.print(BASS);

    //DIAGNOSE
// see what's coming out
/*
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
     
    */
    
}
