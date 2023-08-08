//display of soil and sensor
void soilStart(String soil){

  unsigned long previousMillis = 0;           //To make a delay by using millis() function
  const long interval = 3000;

   unsigned long currentMillis = millis();   //Store the current run-time of the system (millis function)
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        
        introSoil(soil);
      }

}
