boolean TimePeriodIsOver (unsigned long &startOfPeriod, unsigned long TimePeriod) {
  unsigned long currentMillis  = millis();
  if ( currentMillis - startOfPeriod >= TimePeriod ) {
    // more time than TimePeriod has elapsed since last time if-condition was true
    startOfPeriod = currentMillis; // a new period starts right here so set new starttime
    return true;
  }
  else return false;            // actual TimePeriod is NOT yet over
}

void printTime(String r2){

  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print(r2);
  

  createCustomCharacters();
  printFrame("---TIMER BASED----", F("------------------"));
}

void clearTimer(){

  counter = 7;
  hrs = "";
  setupHours = 0;
  mins = "";
  setupMinutes = 0;
  secs = "";
  setupSeconds = 0;
  sett = 0;

  ForHours();
}
