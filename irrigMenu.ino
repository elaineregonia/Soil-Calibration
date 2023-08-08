// irri menu
void irrigMenu(){

  if (typeDef == 1){
    printMenu(F("----IRRIGATION----"), F(" Type: Drip"), F(""), F("- B= Back         -"));
  }
  else if(typeDef == 2){
    printMenu(F("----IRRIGATION----"), F(" Type: Sprinkler"), F(""), F("- B= Back         -"));
  }

  if (basedDef == 1){
    lcd.setCursor(2,2);
    lcd.print(F(" Base: Sensor"));
  }
  else if (basedDef == 2){
    lcd.setCursor(2,2);
    lcd.print(F(" Base: Timer"));
  }
  
  
  
  boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case 'B': //Back to menu
        ch = false;
        mainMenu();
                 
        break;
     }
    }
  }
}
