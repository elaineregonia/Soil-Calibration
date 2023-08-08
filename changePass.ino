//change pass but type 1st the current
void changepw(){
  boolean ch = true;
  
  lcd.backlight();  
  lcd.clear();
  
  lcd.setCursor(2,1);
  lcd.print("Current password:"); 
  lcd.setCursor(3,2);
  
  createCustomCharacters();
  printFrame("------------------", "------------------");

  cpw = "";
  
  while(ch){
    char key = customKeypad.getKey();
    if(key){
      switch(key){
        case 'C' : //Clear
          clearcpw(cpw);
        break;
        
        case 'D' : //Delete
           deletecpw(cpw);
        break;
        
        case 'B': // back
            ch = false;
            lcd.clear();
            lcd.noBacklight();              
            settings();
        break;
        case '*':   
          if (checkCurrent()){
            changePass();
          }

              
        break;
        
        default:
          cpw =cpw + key;
          hidecpw(cpw); 
      }
    }
  }  
 }

bool checkCurrent(){
  if(cpw.length() < 6 || cpw.length() > 6){
          printConfirm(F("------------------"), F("Password should be"), F("be........"));
          delay(900);
          printConfirm(F("------------------"), F("     6 "),F("character long"));
          delay(900);
          
          clearcpw(cpw);
          return false;

  }
  else if(cpw == dpw){
     cpw = "";
     return true;
 
    }
  else
     printConfirm(F("------------------"),F("Current password"),F("does not match!"));
     delay(500);
     clearcpw(cpw);
     
     return false;
    
 }



//change pass
void changePass(){
  
  boolean ch = true;
  
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(F("New password:")); 
  lcd.setCursor(3,2);
  
  createCustomCharacters();
  printFrame(F("------------------"), F("------------------"));
          
  chpw = "";
  
  while(ch){
    char key = customKeypad.getKey();
    if(key){
      switch(key){
        case 'C' : //Clear
        
            clearchpw(chpw);
            
        break;
        
        case 'D' : //Delete

            deletechpw(chpw);

        break;
        
        case 'B': // back
            ch = false;
            lcd.clear();
                        
            settings();
        break;
        case '*': 

          if(verifyPass()){

          printConfirm(F("------------------"),F("Password changed"), F("Successfully!"));
          
          delay(1000);
          ch = false;

            smoisture = 0;
             
              attempt = 0;
              loop_path = 0;
              clearpw(pw);
          ledoff();
          lcd.clear();
          lcd.noBacklight();
       
          loop();
          }
          
          
        break;
        
        default:
          chpw =chpw + key;
          hidechpw(chpw); 
          
      }
    }
  }
}

bool verifyPass(){
  if(chpw.length() < 6 | chpw.length() > 6){
          printConfirm(F("------------------"), F("Password should be"), F("be........"));
          delay(900);
          printConfirm(F("------------------"), F("     6 "),F("character long"));
          delay(900);
          
          clearchpw(chpw);
          return false;

  }
 else if (chpw == dpw){
        printConfirm(F("------------------"), F("Password should be"), F("be........"));
          delay(900);
        printConfirm(F("------------------"), F("different from"),F("old password"));
        delay(900);
        
        clearchpw(chpw);
        return false;
 }
    else
      dpw = chpw;
      
      return true;
}
