//clear in new pass
void clearchpw(String changed){
  changed = "";
  chpw = changed;
  hidechpw(chpw);
}

//hide input in change pass
void hidechpw(String changed){
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(F("New password:")); 

  
  lcd.setCursor(3,2);
  if(changed.length() > 0){
    for(int i=0; i <= changed.length()-1; i++)
    {
      lcd.print(F("*"));
    }
  }
  createCustomCharacters();
  printFrame(F("------------------"), F("------------------"));
               
}

//del new pass
void deletechpw(String changed){
  String ch = changed;
  ch.remove(ch.length()-1,1);
  chpw = ch;
  hidechpw(chpw);
}

//hide current pass
void hidecpw(String changed){
  lcd.clear();
  lcd.setCursor(2,1);
  lcd.print(F("Current password:")); 

  
  lcd.setCursor(3,2);
  if(changed.length() > 0){
    for(int i=0; i <= changed.length()-1; i++)
    {
      lcd.print(F("*"));
    }
  }
  createCustomCharacters();
  printFrame(F("------------------"), F("------------------"));
               
}

//del current pass
void deletecpw(String changed){
  String ch = changed;
  ch.remove(ch.length()-1,1);
  cpw = ch;
  hidecpw(cpw);
}

//clear current pass
void clearcpw(String changed){
  changed = "";
  cpw = changed;
  hidecpw(cpw);
}
