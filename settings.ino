void settings(){

  printMenu(F("-----SETTINGS-----"), F(" 1 Change Pass"), F(" 2 Change Default"), F("- 3 Back         -"));
            
  boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //Change Pass
          ch = false;
          changepw();
        break;
 
        case '2': //Change Def
          ch = false;
          changeDef();
        break;
        
        case '3': //Back
          ch = false;
          mainMenu();
        break; 
      }
    }
  }
}
