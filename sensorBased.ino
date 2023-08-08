void irrigSensor( int A, int B, int C, int D){

  unsigned long previousMillis = 0;           //To make a delay by using millis() function
  const long interval = 1000;
  
  sensorValue = analogRead(A1);
  percnt = map(sensorValue, wet, dry, 100, 0);

  unsigned long currentMillis = millis();   //Store the current run-time of the system (millis function)
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        
      if(0 <= percnt && A >= percnt){
          str=String("coming from arduino: ")+String("Soil= ")+String(sensorValue)+String("Status= ")+String(percnt);
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
          
          str=String("coming from arduino: ")+String("Soil= ")+String(sensorValue)+String("Status= ")+String(percnt);
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
          
            str=String("coming from arduino: ")+String("Soil= ")+String(sensorValue)+String("Status= ")+String(percnt);
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
      }
}
  
  
//  int soilval =analogRead(soilsens);
//  lcd.clear();
//  lcd.setCursor(0,1);
//  int soilpercent = map(soilval,wet,dry,0,100);
//  lcd.print("Percentage: ");
//  lcd.print(soilpercent);
//  lcd.println("%");
//  
//  delay(1000);
//  if (soilpercent >= 80){
//    analogWrite(LED1,LOW);
//    analogWrite(LED2,LOW);
//    analogWrite(relaymod,LOW);
//  }
//  else if(soilpercent <=79){
//    analogWrite(LED1,HIGH);
//    analogWrite(LED2,HIGH);
//    analogWrite(relaymod,HIGH);
//  
