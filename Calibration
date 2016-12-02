/*int calibration_max[5]          = {0,0,0,0,0};

int calibration_max_array[5,10] = {{0,0,0,0,0,0,0,0,0,0}, 
                                   {0,0,0,0,0,0,0,0,0,0}, 
                                   {0,0,0,0,0,0,0,0,0,0}, 
                                   {0,0,0,0,0,0,0,0,0,0}, 
                                   {0,0,0,0,0,0,0,0,0,0} };
int calibration_min[5]          = {0,0,0,0,0};                               
int calibration_min_array[5,10] = {{1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}, 
                                   {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}, 
                                   {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}, 
                                   {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}, 
                                   {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000} };

long calibration_map[2,5] = {{0,0,0,0,0}, {1000,1000,1000,1000,1000}};         //{left_max,right_max,bass_max,mid_max,trem_max}, {left_min,right_min,bass_min,mid_min,trem_min}
                                   
 */           

void Calibration()
{
calibration_current[0] = LEFT;
calibration_current[1] = RIGHT;
calibration_current[2] = BASS;
calibration_current[3] = MID;
calibration_current[4] = TREM;
  
for (int i=0; i<=4; i++)
{
if (calibration_max[i]<calibration_current[i])
{
  calibration_max[i]=calibration_current[i];
}
if (calibration_min[i]>calibration_current[i])
{
  calibration_min[i]=calibration_current[i];
}
}

if ((millis()-previous_calibration_time)>calibration_update_rate)
  {
    previous_calibration_time=millis();
    //array shift folgt
    for (int i=0; i<=8; i++)
      { calibration_max_array_LEFT[i] = calibration_max_array_LEFT[i+1];
        calibration_max_array_RIGHT[i] = calibration_max_array_RIGHT[i+1];
        calibration_max_array_BASS[i] = calibration_max_array_BASS[i+1];
        calibration_max_array_MID[i] = calibration_max_array_BASS[i+1];
        calibration_max_array_TREM[i] = calibration_max_array_BASS[i+1];
        calibration_min_array_LEFT[i] = calibration_min_array_LEFT[i+1];
        calibration_min_array_RIGHT[i] = calibration_min_array_RIGHT[i+1];
        calibration_min_array_BASS[i] = calibration_min_array_BASS[i+1];
        calibration_min_array_MID[i] = calibration_min_array_BASS[i+1];
        calibration_min_array_TREM[i] = calibration_min_array_BASS[i+1];
          
      }    
          
                 
        calibration_max_array_LEFT[9] = calibration_max[0];
        calibration_max_array_RIGHT[9] = calibration_max[1];
        calibration_max_array_BASS[9] = calibration_max[2];
        calibration_max_array_MID[9] = calibration_max[3];
        calibration_max_array_TREM[9] = calibration_max[4];
        calibration_min_array_LEFT[9] = calibration_min[0];
        calibration_min_array_RIGHT[9] = calibration_min[1];
        calibration_min_array_BASS[9] = calibration_min[2];
        calibration_min_array_MID[9] = calibration_min[3];
        calibration_min_array_TREM[9] = calibration_min[4];
      

    //durchschnitt aufaddieren
    
    
    for (int i=0; i<=9; i++)
      
        {
        calibration_map_max[0]+=(i+1)*calibration_max_array_LEFT[i]/10;
        calibration_map_max[1]+=(i+1)*calibration_max_array_RIGHT[i]/10;
        calibration_map_max[2]+=(i+1)*calibration_max_array_BASS[i]/10;
        calibration_map_max[3]+=(i+1)*calibration_max_array_MID[i]/10;
        calibration_map_max[4]+=(i+1)*calibration_max_array_TREM[i]/10;
        calibration_map_min[0]+=(i+1)*calibration_min_array_LEFT[i]/10;
        calibration_map_min[1]+=(i+1)*calibration_min_array_RIGHT[i]/10;
        calibration_map_min[2]+=(i+1)*calibration_min_array_BASS[i]/10;
        calibration_map_min[3]+=(i+1)*calibration_min_array_MID[i]/10;
        calibration_map_min[4]+=(i+1)*calibration_min_array_TREM[i]/10;
        }


   //für durchschnitt teilen
     for (int i=0; i<=4; i++)
     { int c = calibration_map_max[i]*10/55;
     int d = calibration_map_min[i]*10/55;
        calibration_map_max[i]=constrain(c,1000,6000); //55=10+9+8+7+6+5+4+3+2+1
        calibration_map_min[i]=constrain(d,0,600);
      }
  
    for (int i=0; i<=4; i++)
    {
      calibration_max[i]          = 0;
      calibration_min[i]          = 200;
    }
  }
}
