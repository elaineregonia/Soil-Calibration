//hide pattern 
void hide_pn(String pass){
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(F("Enter pattern:")); 

  
  lcd.setCursor(3,2);
  if(pass.length() > 0){
    for(int i=0; i <= pass.length()-1; i++)
    {
      lcd.print(F("*"));
    }
  }
  createCustomCharacters();
  printFrame(F("------------------"), F("------------------"));
}

//clear pattern
void clearpn(String pass){
  pass = "";
  pn= pass;
  hide_pn(pn);
}


//delete pattern
void deletepn(String pass){
  String pas = pass;
  pas.remove(pas.length()-1,1);
  pn = pas;
  hide_pn(pn);
}
