void humidity_mist(){
  int temp = dht.readTemperature();

 if (temp >=21 && temp <= 32){

   
    lcd.setCursor(0,0);
    lcd.print("Ambient Temp: ");
    lcd.print(temp);
    lcd.print((char)223); 
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Environment is quite clear.");

}
  else if(temp >=33){
    
//    if(digitalWrite(drip, HIGH) || digitalWrite(sprinkler, HIGH)){
//        
//    }
   
    lcd.setCursor(0,0);
    lcd.print("Ambient Temp: ");
    lcd.print(temp);
    lcd.print((char)223); 
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Environment is hot.");

    }
  else{
   
    lcd.setCursor(0,0);
    lcd.print("Ambient Temp:");
    lcd.print(temp);
    lcd.print((char)223); 
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Environment is cold.");

    }
}
