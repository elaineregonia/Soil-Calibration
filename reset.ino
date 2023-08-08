//reset of system
void resett(){
  
  createCustomCharacters();
  printFrame(F("------------------"), F("------------------"));
  
  lcd.setCursor(3,1);
  lcd.print(F("The user cannot"));

  for(cd=10;cd>=0;cd--){
     lcd.setCursor(2,2);
     lcd.print(F("log-in again!"));
     lcd.setCursor(18,2);
     lcd.print(" ");
     lcd.setCursor(17,2);
     lcd.print(cd);
     delay(1000);

    if(cd == 0){

      printConfirm(F("------------------"), F("Forgot Password?"), F("Yes=1 or No=0"));

    boolean ch = true;
    while(ch){
      char key = customKeypad.getKey(); 
        if(key){
          switch(key){
            case '1':
              ch = false; 
              masterKey();
              
             
            break;
            case '0':
              ch = false;         
              clearpw(pw);
              delay(300);
              attempt = 0;
              ledoff();
            break;
          }
          
        }
       }
    } 
  }   
}
