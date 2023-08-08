//sub  menu of cali
void caliMenu(){
 boolean ch = true;
  if (def == 1){
    printMenu(F("---CALIBRATION----"), F(">1 Loam   2 Clay"), F(" 3 Sandy  4 Silt"), F("- 5 Back         -"));
  }
  else if (def == 2){
    printMenu(F("---CALIBRATION----"), F(" 1 Loam  >2 Clay"), F(" 3 Sandy  4 Silt"), F("- 5 Back         -"));
  }
  else if (def == 3){
    printMenu(F("---CALIBRATION----"), F(" 1 Loam   2 Clay"), F(">3 Sandy  4 Silt"), F("- 5 Back         -"));
  }
  else if (def == 4){
    printMenu(F("---CALIBRATION----"), F(" 1 Loam   2 Clay"), F(" 3 Sandy >4 Silt"), F("- 5 Back         -"));
  }
  
 
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //loam
          ch = false;
          smoisture = 1;
        break;
 
        case '2': //clay
          ch = false;
          smoisture = 2;
        break;
        
        case '3': //sandy
          ch = false;
          smoisture = 3;
        break; 

         case '4': //silt
          ch = false;
          smoisture = 4;
        break;  
        
        case '5': //back
          ch = false;
          smoisture = 0;
          mainMenu();
        break; 

      }
    }
  }
}
