void soilMoisture(){
  if(smoisture == 1){
    soil(F("Loam"), 43,50,70,80);
  }
  else if(smoisture == 2){
    soil(F("Clay"),43,44,55,60);
  }
  else if(smoisture == 3){
    soil(F("Sandy"),30,35,70,71);
  }
  else if(smoisture == 4){
    soil(F("Silt"),30,35,70,71);
  }
}
