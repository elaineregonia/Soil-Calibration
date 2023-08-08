//start of sytem
void startts(){
  
    createCustomCharacters();
    printFrame(F("------------------"), F("------------------"));
    lcd.setCursor(2,1);
    lcd.print(F(" 6 WONDER PETS"));
    
    delay(1000);

    lcd.clear();
    
    createCustomCharacters();
    printFrame(F("------------------"), F("------------------"));
    
    lcd.setCursor(7,1);
    lcd.print(F("Soil"));
    lcd.setCursor(3, 2);
    lcd.print(F(" Calibration"));
    delay(1000);
}
