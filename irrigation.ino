void irrigation(){
  if (basedDef == 1){
      //sensor
      if (def == 1){
          irrigSensor(43,50,70,80);
      }
      else if (def == 2){
         irrigSensor(43,44,55,60);
      }
      else if (def == 3){
          irrigSensor(30,35,70,71);
      }
      else if (def == 4){
          irrigSensor(30,35,70,71);
      }
    }
    else if (basedDef == 2){
      //timer
    }
}
