//input password
void input(){


boolean ch = true;
 
while(ch){
  char key = customKeypad.getKey(); //input keypad

  if (key){
    
    switch(key){
        case '*': //enter
          if(check()){
             ch = false;
            mainMenu();
          };
        break;
        
        case 'D': //delete input
         
          deletepw(pw);
        break;
      
        case 'C': //clear input
        
          clearpw(pw);
        break;

        case '#': 
          
        break;
    
      default:        
          
        lcd.setCursor(0,1);
        pw = pw+key;
        hide_input(pw); 
       
    }
  }  
}
}

//check the password
bool check(){

  while(attempt <=2){
    if(dpw != pw){

      printConfirm(F("------------------"), word_attempt[attempt] + F(" Attempt"),F("Login failed!")); //print text
      
      delay(1000);
      
      clearpw(pw); //clear input password
      attempt++; //attempt login
      if(attempt == 1){
         digitalWrite(attempt1, HIGH);
      }
      else if (attempt == 2){
          digitalWrite(attempt2, HIGH);
    }
    else if (attempt == 3){
       digitalWrite(attempt3, HIGH);
       resett();
    }
    else
        digitalWrite(attempt3, HIGH);
      return false;
      
  }
  else
      attempt = 0;

      return true;
  }
}
