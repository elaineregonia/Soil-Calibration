void ForHours(){

  boolean ch = true;
  
  printTime(F("Set Timer HH:"));

  while(ch){ 
    char key = customKeypad.getKey();

    if(key){
      Serial.println(key);
      counter = counter + 1; 
      lcd.setCursor(counter, 2);
      lcd.print(key);
    }

    if (key == '1'){ hrs = hrs + 1;}
  
    if (key == '2'){ hrs = hrs + 2;}
    
    if (key == '3'){ hrs = hrs + 3;}
  
    if (key == '4'){ hrs = hrs + 4;}
  
    if (key == '5'){ hrs = hrs + 5;}
  
    if (key == '6'){ hrs = hrs + 6;}
  
    if (key == '7'){ hrs = hrs + 7;}

    if (key == '8'){ hrs = hrs + 8;}
  
    if (key == '9'){ hrs = hrs + 9;}
               
    if (key == '0'){ hrs = hrs + 0;}

    if (key == '#'){ clearTimer();}

    if (key == '*'){

      setupHours = hrs.toInt(); // convert from string to int
      Serial.print(setupHours);
      printTime(F("   HOURS:"));
      lcd.setCursor(8, 2);
      lcd.print(setupHours);
      //hrs = "";
      delay(2000);
      counter = 7; 
      sett = 1; // to mins
      ch = false;
      ForMins();
      }

    if (key == 'B'){
      ch = false;
      counter = 7;
      setupHours = 0;
      hrs = "";
      changeBased();
    }
  }
}

void ForMins(){

  boolean ch = true;
  
  printTime(F("Set Timer MM:"));

  while(ch){ 
    char key = customKeypad.getKey();
    
    if(key){
      Serial.println(key);
      counter = counter + 1; 
      lcd.setCursor(counter, 2);
      lcd.print(key);
    }

    if (key == '1'){ mins = mins + 1;}
  
    if (key == '2'){ mins = mins + 2;}
    
    if (key == '3'){ mins = mins + 3;}
  
    if (key == '4'){ mins = mins + 4;}
  
    if (key == '5'){ mins = mins + 5;}
  
    if (key == '6'){ mins = mins + 6;}
  
    if (key == '7'){ mins = mins + 7;}

    if (key == '8'){ mins = mins + 8;}
  
    if (key == '9'){ mins = mins + 9;}
               
    if (key == '0'){ mins = mins + 0;}

    if (key == '#'){ clearTimer();}

    if (key == '*'){

      setupMinutes = mins.toInt();
      Serial.print(setupMinutes);
      printTime(F("  MINUTES:"));
      lcd.setCursor(8, 2);
      lcd.print(setupMinutes);
      //mins = "";
      delay(2000);
      counter = 7;
      sett = 2;
      ch = false;
      ForSecs();
      }

    if (key == 'B'){
       ch = false;
       counter = 7;
       setupMinutes = 0;
       
      mainMenu();
  }
 }
}

void ForSecs(){

  boolean ch = true;
  
  printTime(F("Set Timer SS:"));

  while(ch){ 
    char key = customKeypad.getKey();
    
    if(key){
      Serial.println(key);
      counter = counter + 1; 
      lcd.setCursor(counter, 2);
      lcd.print(key);
    }

    if (key == '1'){ secs = secs + 1;}
  
    if (key == '2'){ secs = secs + 2;}
    
    if (key == '3'){ secs = secs + 3;}
  
    if (key == '4'){ secs = secs + 4;}
  
    if (key == '5'){ secs = secs + 5;}
  
    if (key == '6'){ secs = secs + 6;}
  
    if (key == '7'){ secs = secs + 7;}

    if (key == '8'){ secs = secs + 8;}
  
    if (key == '9'){ secs = secs + 9;}
               
    if (key == '0'){ secs = secs + 0;}

    if (key == '#'){ clearTimer();}

    if (key == '*'){

      setupSeconds = secs.toInt();
      Serial.print(setupSeconds);
      printTime(F("  SECONDS:"));
      lcd.setCursor(8, 2);
      lcd.print(setupSeconds);
      //secs = "";
      delay(2000);
      counter = 7;
      sett = 0;
      printTime(F("  TIME SET:"));
      lcd.setCursor(5, 2);
       Alarm.free(alarm1);
      alarm1 = Alarm.timerRepeat(setupHours, setupMinutes, setupSeconds, Repeats);

      char timest[8];
     const unsigned long All_InSeconds = setupHours * 3600ul + setupMinutes * 60ul + setupSeconds;
     const unsigned long All_InMilliSeconds = All_InSeconds * 1000ul;

     int seconds = All_InSeconds % 60;
     int minutes = (All_InSeconds / 60) % 60;
     int hours = All_InSeconds / 3600ul;
 
      Serial.println(All_InMilliSeconds);

      intervalOff = All_InMilliSeconds;
      lcd.setCursor(5, 2);
      sprintf(timest, "%02d:%02d:%02d",  hours, minutes, seconds);
      lcd.print(timest);
      delay(1000);
       digitalWrite(drip,HIGH);
       digitalWrite(sprinkler,HIGH);
       digitalWrite(relaymod,HIGH);
     
      lcd.clear();
      basedDef= 2;
      delay(200);
      ch = false;
      mainMenu();
      }

    if (key == 'B'){
      ch = false;
      mainMenu();
    }
  }
}

void DisplayTime(){
  lcd.setCursor(5,1);
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
   createCustomCharacters();
  printFrame(F("------------------"), F("------------------"));
    
}
void printDigits(int digits){

   lcd.print(" :");
  if(digits < 10)
   lcd.print("0");
  lcd.print(digits);
 
  
}

// void Repeats(){

//   if(typeDef == 1){
//     dripDelay.start(intervalOff);
//     if (dripDelay.justFinished()) {
//       lcd.setCursor(5,2);
//       lcd.print("PUMP IS ON");
//       digitalWrite(drip, LOW);
//       digitalWrite(relaymod, LOW);
//       dripDelay.start(intervalOff);
//     }
//     // if (outLowDelay.justFinished()) {
//     //   digitalWrite(outPin, HIGH);
//     //   outHighDelay.start(relay);
//     // }
//   }
  
// }

void Repeats(){
loop_timer = 1;
 }


// void Repeats(){
//  const long onDuration = 30000;// OFF time for LED
  
//   intervalOff = All_InMilliSeconds;
//   digitalWrite(10,HIGH);
//   intervalOff;
// if (outHighDelay.justFinished()) {
//     digitalWrite(outPin, LOW);
//     outLowDelay.start(All_InMilliSeconds);
//     }
//     if (outLowDelay.justFinished()) {
//       digitalWrite(outPin, HIGH);
//       outHighDelay.start(relay);
//     }
// }
