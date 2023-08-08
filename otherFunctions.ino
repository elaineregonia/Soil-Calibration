void confirmSand(String r1, int df){
  boolean ch = true;
  
  printConfirm(r1, "Are you sure?", "Yes=1 or No=0");

  while(ch){
    char key = customKeypad.getKey();
    
    switch(key){
      case '1':
      
        ch = false;
        chdef = df;
        def = chdef;

        printConfirm(F("------------------"),F("Default changed"), F("Successfully!"));
        delay(1000);
        
        mainMenu();

      break;
      
      case '0':
        ch = false;         
        mainMenu();
      break;
  }
  }
}

void confirmType(String r1, int df){
  boolean ch = true;
  
  printConfirm(r1, "Are you sure?", "Yes=1 or No=0");

  while(ch){
    char key = customKeypad.getKey();
    
    switch(key){
      case '1':
      
        ch = false;
        typechDef = df;
        typeDef = typechDef;

        printConfirm(F("------------------"),F("Default changed"), F("Successfully!"));
        delay(1000);
        
        mainMenu();

      break;
      
      case '0':
        ch = false;         
        mainMenu();
      break;
  }
  }
}

void confirmBased(String r1, int df){
  boolean ch = true;
  
  printConfirm(r1, "Are you sure?", "Yes=1 or No=0");

  while(ch){
    char key = customKeypad.getKey();
    
    switch(key){
      case '1':
      
        ch = false;
        basedchdef = df;
        basedDef = basedchdef;

        printConfirm(F("------------------"),F("Default changed"), F("Successfully!"));
        delay(1000);
        
        mainMenu();

      break;
      
      case '0':
        ch = false;         
        changeBased();
      break;
  }
  }
}

void printTimer(){
  
}

//print main menu
int printMenu(String r1, String r2, String r3, String r4){

  lcd.clear();
  
  lcd.setCursor(2,1);
  lcd.print(r2);
  
  lcd.setCursor(2,2);
  lcd.print(r3);

  createCustomCharacters();
  printFrame(r1, r4);
 // "----MAIN MENU-----"
            // "---IRRIGATION-----"
             //"---CALIBRATION----"
}

//print soil
int printSoil(String r1, String r2, String r3){

  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print(r2);
  
  lcd.setCursor(6,2);
  lcd.print(r3);
  
  createCustomCharacters();
  printFrame("THRESHOLD VAL: " + r1,"- B = BACK       -");
             //"THRESHOLD VAL: " + "---"
             //"--THRESHOLD: " + r1 + "--"
             //"------------------"
             //"Loam status:577/65%"
}

int printIrrig(String r2, String r3){
  
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print("Type: " +  r2);
             // "----IRRIGATION----"
  lcd.setCursor(6,2);
  lcd.print("Irrigation Base: " + r3);
  
  createCustomCharacters();
  printFrame("----IRRIGATION----" ,"- B = BACK       -");
           
}

void introSoil(String r1){
  
  lcd.clear();
//  lcd.setCursor(2,1); 
//  lcd.print("Type: Drip");
  
//  lcd.setCursor(1,2);
//  lcd.print(F("Irrigation: Sensor"));
  
  
  createCustomCharacters();
  printFrame("-- Soil: " + r1 + " ----", F("-Press any key...-"));
             //"--Soil: "+ r1 + "----"
           
}

//print confirmation
int printConfirm(String r1, String r2, String r3){

  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(r2);
  
  lcd.setCursor(3,2);
  lcd.print(r3);
  
  createCustomCharacters();
  printFrame(r1, F("------------------"));
}

//border
void printFrame(String r1, String r4)
{
  lcd.setCursor(1,0);
  lcd.print(r1);
  lcd.setCursor(1,3);
  lcd.print(r4);
  lcd.setCursor(0,1);
  lcd.write(byte(0));
  lcd.setCursor(0,2);
  lcd.write(byte(0));
  lcd.setCursor(19,1);
  lcd.write(byte(0));
  lcd.setCursor(19,2);
  lcd.write(byte(0));
  lcd.setCursor(0,0);
  lcd.write(byte(1));
  lcd.setCursor(19,0);
  lcd.write(byte(2));
  lcd.setCursor(0,3);
  lcd.write(byte(3));
  lcd.setCursor(19,3);
  lcd.write(byte(4));
}

void createCustomCharacters()
{
  lcd.createChar(0, verticalLine);
  lcd.createChar(1, char1);
  lcd.createChar(2, char2);
  lcd.createChar(3, char3);
  lcd.createChar(4, char4);
}

//all of led will be turned off
void ledoff(){

  digitalWrite(attempt1, LOW);
  digitalWrite(attempt2, LOW);
  digitalWrite(attempt3, LOW);
  digitalWrite(success, LOW);
}
