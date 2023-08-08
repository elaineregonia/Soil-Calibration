//hide display of password
void hide_input(String pass){
    lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(F("Enter password:")); 

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

//clear password
void clearpw(String pass){
  pass = "";
  pw= pass;
  hide_input(pw);
}


//delete password
void deletepw(String pass){
  String pas = pass;
  pas.remove(pas.length()-1,1);
  pw = pas;
  hide_input(pw);
}
