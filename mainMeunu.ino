//main menu
void mainMenu(){
  
  digitalWrite(success, HIGH);
  digitalWrite(attempt1, LOW);
  digitalWrite(attempt2, LOW);
  digitalWrite(attempt3, LOW);
  
  lcd.backlight();
  
  setupHours = 0;
  hrs= "";
  mins = "";
  setupMinutes = 0;
  secs = "";
  setupSeconds = 0;
  loop_path = 0;
  printMenu(F("----MAIN MENU-----"), F(" 1 Calibration"), F(" 2 Irrigation"), F("- 3 More         -"));
  
  boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //cali
          ch = false;
          loop_path = 3;
          smoisture = def;
          
          //caliMenu();
        break;
 
        case '2': //irri
          ch = false;
          irrigMenu();
        break;
        
        case '3': //more
          ch = false;
          mainMenu2();
        break;
            
      }
    }
  }
}

//main menu 2
void mainMenu2(){
  
  lcd.backlight();

  printMenu( F("----MAIN MENU-----"), F(" 1 Settings"), F(" 2 Logout"), F("- 3 Back         -"));
  
  boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //Settings
          ch = false;
         settings();
        break;
 
        case '2': //logout
          ch = false;
          logout();
        break;
        
        case '3': //back
          ch = false;
          mainMenu();
        break;     
      }
    }
  }
}
