void readMSGEQ7()
// Function to read 7 band equalizers
{//Serial.println("beginn read");
digitalWrite(reset, HIGH);
 digitalWrite(reset, LOW);

 for (int i = 0; i <= 6; i++)
 {
 digitalWrite(strobe, LOW);
 delayMicroseconds(30); // to allow the output to settle
  left[i]   = analogRead(MSGEQ7_PIN_L);
  right[i]  = analogRead(MSGEQ7_PIN_R);
 
  digitalWrite(strobe, HIGH);
 }
  right[4]=left[4]; //2 bands are broken on my chip (no changes in their values)
  right[2]=left[2];
  
  /*
  for (int i=0; i<=6; i++)
 {
 Serial.print(left[i]);
 Serial.print("\t");
 }
 Serial.print("|");
 for (int i=0; i<=6; i++)
 {
 Serial.print(right[i]);
 Serial.print("\t");
 }
 Serial.println();
  delay(10);
  */
}
