//logout
void logout(){
  
  printConfirm(F("------LOGOUT------"), F("Are you sure?"), F("Yes=1 or No=0"));
               
    boolean ch = true;
    while(ch){
      char key = customKeypad.getKey(); 
        if(key){
          switch(key){
            case '1':
             ch = false;
              smoisture = 0;
             
              attempt = 0;
              loop_path = 0;
              clearpw(pw);
              ledoff();
        digitalWrite(drip,HIGH);
       digitalWrite(sprinkler,HIGH);
       digitalWrite(relaymod,HIGH);
              lcd.clear();
              lcd.noBacklight();
              
              loop();
              
             
            break;
            case '0':
              ch = false;         
              mainMenu2();
            break;
          }
          
        }
    }
}
