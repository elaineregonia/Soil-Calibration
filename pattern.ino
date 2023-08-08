void masterKey(){
boolean ch = true;
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(F("Enter pattern:")); 

  createCustomCharacters();
  printFrame(F("------------------"), F("------------------"));
  lcd.setCursor(3,2);
  
 while(ch){
 char key = customKeypad.getKey(); //input keypad

  if (key){
    
    switch(key){
        case '*': //enter

//          if(pattern == pn){
//            
//            attempt = 0;
//             ledoff();
//             changePass();
//          }
//          else
//          
//          printConfirm(F("------------------"),F("Pattern"),F("does not match!"));
//         delay(500);
//          clearpn(pn);
        //ch= false;
           if(checkPattern()){
             ledoff();
             changePass();
          }
          
        break;
        
        case 'D': //delete input
          deletepn(pn);
        break;
      
        case 'C': //clear input
          clearpn(pn);
        break;
    
      default:      
        
        lcd.setCursor(0,1);
        pn = pn+key;
       hide_pn(pn); 
       
     }
    }
   }
}   

bool checkPattern(){
    if(pn.length() < 7 | pn.length() > 7){
          printConfirm(F("------------------"), F("Pattern should be"), F("be........"));
          delay(900);
          printConfirm(F("------------------"), F("     7 "),F("character long"));
          delay(900);
          
          clearpn(pn);
          return false;

  }
   else if(pattern != pn){
         printConfirm(F("------------------"),F("Pattern"),F("does not match!"));
         delay(500);
         clearpn(pn);
          
         return false;
      }
     else
          attempt = 0;

          return true;
}
