void changeDef(){
  
  printMenu(F("--CHANGE DEFAULT--"), F(" 1 Calibration"), F(" 2 Irrigation"), F("- 3 More         -"));
              //"------------------"
  boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //cali
          ch = false;
          changeCali();
        break;
 
        case '2': //irri
          ch = false;
          changeIrri();
        break;
        
        case '3': //more
          ch = false;
          mainMenu();
        break;
            
      }
    }
  }
}

void changeCali(){

  printMenu(F("--CHOOSE DEFAULT--"), F(" 1 Loam   2 Clay"), F(" 3 Sandy  4 Silt"), F("- 5 Back         -"));
            
  boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //default
          ch = false;
          confirmSand(F("-----LOAM SAND----"),1);
                     
        break;
 
        case '2': //clay
          ch = false;
          confirmSand(F("-----CLAY SAND----"),2);
        break;
        
        case '3': //sandy
          ch = false;
          confirmSand(F("----SANDY SAND----"),3);
        break; 

         case '4': //silt
          ch = false;
          confirmSand(F("-----SILT SAND----"),4);
        break;  
        
        case '5': //back
          ch = false;
          //smoisture = 0;
          changeDef();
        break;  
      }
    }
  }
}

void changeIrri(){
  lcd.backlight();


  printMenu(F("--CHOOSE DEFAULT--"), F(" 1 Types"), F(" 2 Based "), F("  3 Back "));
            
  boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //types
          ch = false;
          changeType();        
        break;
 
        case '2': //base
          ch = false;
           changeBased();
           
        break;

        case '3': //back
          ch = false;
          //smoisture = 0;
          changeDef();
        break;  
      }
    }
  }
 }


void changeType(){
  printMenu(F("-IRRIGATION TYPES-"), F(" 1 Drip "), F(" 2 Sprinkler "), F("  3 Back "));
          
             boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //drip
          ch = false;
          confirmType(F("------ DRIP ------"),1);
                       // "------------------"
        break;
 
        case '2': //sprinkler
          ch = false;
          confirmType(F("---- SPRINKLER ---"),2);
                        //"------------------"
        break;
        
        case '3': //more
          ch = false;
          changeIrri();
        break;
            
      }
    }
  }
}

void changeBased(){
  printMenu(F("-IRRIGATION BASED-"), F(" 1 Sensor "), F(" 2 Timer "), F("  3 Back "));
          
             boolean ch = true;
  while(ch){
    char key = customKeypad.getKey();
    
    if(key){
      switch(key){
        case '1': //sensor
          ch = false;
          confirmBased(F("----- SENSOR -----"),1);
                       //"------------------"
        break;
 
        case '2': //timer
          ch = false;
          
          ForHours();

          //timerB = 1;
          //confirmBased(F("----- TIMER -----"),2);
                       //"------------------"
          
        break;
        
        case '3': //more
          ch = false;
          changeIrri();
        break;
            
      }
    }
  }
}
