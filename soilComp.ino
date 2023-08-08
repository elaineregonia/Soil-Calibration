  //soil computation
void soil(String soil, int A, int B, int C, int D){
  
  boolean ch = true; //for looping
  int screenMsg=0;
  unsigned long previousMillis = 0;           //To make a delay by using millis() function
  const long interval = 1000;
  
  while(ch){
  char key = customKeypad.getKey();

  sensorValue = analogRead(A1);
  percnt = map(sensorValue, wet, dry, 100, 0);

  sensorVal2 = analogRead(A2);
  percnt2 = map(sensorVal2, wet, dry, 100, 0);
   

  if (key){
    switch(key){
            case 'B':
            
              ch = false;
              caliMenu();
              
            break;
      }
    }
 unsigned long currentMillis = millis();   //Store the current run-time of the system (millis function)
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        if(screenMsg==0){   
        if(0 <= percnt && A >= percnt){
          
         printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
            , F("Dry soil"));
            str=String("Coming from Arduino: ")+String("Soil = ")+String(sensorValue)+String(" Status = ")+String(percnt);
            espSerial.println(str);
          if (basedDef == 1){
            if (typeDef == 1){
                //drip
//                    digitalWrite(drip,HIGH);
//                    digitalWrite(sprinkler,LOW);
//                    digitalWrite(relaymod,HIGH);

                      digitalWrite(drip,LOW);
                      digitalWrite(sprinkler,HIGH);
                      digitalWrite(relaymod,LOW);
                   
            }
            else if(typeDef == 2){
                  //sprinkler
//                    digitalWrite(drip,LOW);
//                    digitalWrite(sprinkler,HIGH);
//                    digitalWrite(relaymod,HIGH);

                    digitalWrite(drip,HIGH);
                    digitalWrite(sprinkler,LOW);
                    digitalWrite(relaymod,LOW);
            }
          }
        }
        else if(B <= percnt && C >=percnt){
          
          printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
            , F("Good soil"));
            str=String("Coming from Arduino: ")+String("Soil = ")+String(sensorValue)+String(" Status = ")+String(percnt);
            espSerial.println(str);
          if (basedDef == 1){  
//            digitalWrite(drip,LOW);
//            digitalWrite(sprinkler,LOW);
//            digitalWrite(relaymod,LOW);

              digitalWrite(drip,HIGH);
              digitalWrite(sprinkler,HIGH);
              digitalWrite(relaymod,HIGH);
          }
          
        }
        else if(D <=percnt ){
          
          printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
            , F("Soggy soil"));
          str=String("Coming from Arduino: ")+String("Soil = ")+String(sensorValue)+String(" Status = ")+String(percnt);
            espSerial.println(str); 
          if (basedDef == 1){
//            digitalWrite(drip,LOW);
//            digitalWrite(sprinkler,LOW);
//            digitalWrite(relaymod,LOW);

              digitalWrite(drip,HIGH);
              digitalWrite(sprinkler,HIGH);
              digitalWrite(relaymod,HIGH);
          }
        }
//        else{
//         printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
//            , F("Soggy soil"));
//          
//        }
        screenMsg = 1;
        }
        else
               if(0 <= percnt && A >= percnt){
          
          printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
            , F("Dry soil"));
            str=String("Coming from Arduino: ")+String("Soil = ")+String(sensorValue)+String(" Status = ")+String(percnt);
            espSerial.println(str);
          if (basedDef == 1){
            if (typeDef == 1){
                //drip
//                    digitalWrite(drip,HIGH);
//                    digitalWrite(sprinkler,LOW);
//                    digitalWrite(relaymod,HIGH);

                      digitalWrite(drip,LOW);
                      digitalWrite(sprinkler,HIGH);
                      digitalWrite(relaymod,LOW);
                   
            }
            else if(typeDef == 2){
                  //sprinkler
//                    digitalWrite(drip,LOW);
//                    digitalWrite(sprinkler,HIGH);
//                    digitalWrite(relaymod,HIGH);

                    digitalWrite(drip,HIGH);
                    digitalWrite(sprinkler,LOW);
                    digitalWrite(relaymod,LOW);
            }
          }
        }
        else if(B <= percnt && C >=percnt ){
          
          printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
            , F("Good soil"));
            str=String("Coming from Arduino: ")+String("Soil = ")+String(sensorValue)+String(" Status = ")+String(percnt);
            espSerial.println(str);
          if (basedDef == 1){  
//            digitalWrite(drip,LOW);
//            digitalWrite(sprinkler,LOW);
//            digitalWrite(relaymod,LOW);

              digitalWrite(drip,HIGH);
              digitalWrite(sprinkler,HIGH);
              digitalWrite(relaymod,HIGH);
          }
          
        }
        else if(D <=percnt){
          
          printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
            , F("Soggy soil"));
            str=String("Coming from Arduino: ")+String("Soil = ")+String(sensorValue)+String(" Status = ")+String(percnt);
            espSerial.println(str);
          if (basedDef == 1){
//            digitalWrite(drip,LOW);
//            digitalWrite(sprinkler,LOW);
//            digitalWrite(relaymod,LOW);

              digitalWrite(drip,HIGH);
              digitalWrite(sprinkler,HIGH);
              digitalWrite(relaymod,HIGH);
          }
        }
//        else{
//         printSoil(String(sensorValue),soil + F(" status: ")  + String(percnt) + F("%")
//            , F(""));
//          //delay(1000);
//        }
        screenMsg = 0;
    }
  }
}
