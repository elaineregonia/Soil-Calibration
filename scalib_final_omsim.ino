#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Time.h>
#include <TimeAlarms.h>
#include"DHT.h"
#include <millisDelay.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define DHTPIN A2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
SoftwareSerial espSerial(24, 26);
String str;

//keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

char keys[ROWS][COLS]=
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad

//led lights
int success = 10;
int attempt1 = 13;
int attempt2 = 12;
int attempt3 = 11;

//passwords
String pw = "";
String dpw = "123456";
String chpw = "";
String pn = "";
String cpw = "";
String pattern = "1475963";
boolean storedPassword = true;
boolean changedpw = false;
boolean checkPassword = false;
int cd = 0;

//calibration
int def = 1;
int chdef = 0;
int basedDef = 1;
int basedchdef = 0;
int typeDef = 1;
int typechDef = 0;

//irrigation
int relaymod = 50;
int drip = 51;
int sprinkler = 52;
int mist = 53;
int tempo = basedDef;

int counter = 7;

int setupHours = 0;     // How many hours will count down when started
int setupMinutes = 0;   // How many minutes will count down when started
int setupSeconds = 0; 

String hrs; 
String mins;
String secs;

unsigned long intervalOff = 0;
const unsigned long All_InMilliSeconds =0;

millisDelay dripDelay;
const unsigned long relay = 10000;

millisDelay off;
millisDelay sprinklerDelay;

 byte dripState = HIGH;  
 byte sprinklerState = HIGH;  

 unsigned long previousMillisTimer = 0;  
 
 unsigned long intervalTimer = intervalOff;

int sett = 0; 
int switchh = 0; // for opening relay
AlarmID_t alarm1;
int timerSetup = 1;

//Login Attempt
int attempt = 0;
String word_attempt[3] = {"First","Second","Third"};

int period = 5000;
 unsigned long time_now = 0;
//soil moisture
const int dry = 828; //waley tubig
const int wet = 437; //nasa tubig
int sensorValue;
int percnt;
int sensorVal2;
int percnt2;
int smoisture = 0;
int loop_path = 0;
int loop_timer = 0;
//border
byte verticalLine[8] = {B00100,B00100,B00100,B00100,
                        B00100,B00100,B00100,B00100};  

byte char2[8] = {B00000,B00000,B00000,B11100,
                 B00100,B00100,B00100,B00100};

byte char1[8] = {0b00000,0b00000,0b00000,0b00111,
                0b00100,0b00100,0b00100,0b00100};

byte char3[8] = {0b00100,0b00100,0b00100,0b00111,
                0b00000,0b00000,0b00000,0b00000};

byte char4[8] = {0b00100,0b00100,0b00100,0b11100,
                 0b00000,0b00000,0b00000,0b00000};

void setup() {
  Serial.begin(9600);
  //SOIL MOISTURE
  espSerial.begin(9600);

  //LED
  pinMode(attempt1, OUTPUT);
  pinMode(attempt2, OUTPUT);
  pinMode(attempt3, OUTPUT);
  pinMode(success, OUTPUT);

  //IRRIGATION
  pinMode(relaymod, OUTPUT);
  pinMode(drip, OUTPUT);
  pinMode(sprinkler, OUTPUT);

  //LCD BACKLIGHT
  lcd.init();
  

  //START

     setTime(8,59,0,1,1,1); 
 
}

void loop() {
lcd.init();
if(loop_path == 0){
   
lcd.backlight();
  startts();
  
  lcd.clear();

 counter = 7;
 
  hrs = "";
  setupHours = 0;
  mins = "";
  setupMinutes = 0;
  secs = "";
  setupSeconds = 0;
 
char key =  customKeypad.getKey();
while(key == NO_KEY)
{
 key =  customKeypad.getKey();
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
    
  DisplayTime();
  if(basedDef == 2){
   Alarm.delay(900);
  }
  if(loop_timer == 1){
    Timer_on();
  }
}
if (key != NO_KEY){
   lcd.clear();
loop_path = 1;
 

}
}

if(loop_path == 1){
  char key =  customKeypad.getKey();
while(key == NO_KEY)
{
 key =  customKeypad.getKey();
 setupstats();
  
}
if (key != NO_KEY){
  lcd.clear();
  loop_path = 2;
  


}
}

if(loop_path == 2){
  attempt != 3? input() : resett();
}
if(loop_path ==3){
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
 
  if (tempo == 1){
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
  else if (tempo == 2){
    //timer
    //ForHours();
  }
}

}
void setupstats(){
  if (def == 1){
    lcd.setCursor(2,0); 
    lcd.print("  Soil: Loam");
                  //"------------------"
  }
  else if (def == 2){
   lcd.setCursor(2,0); 
    lcd.print("  Soil: Clay");  
  }
  else if (def == 3){
   lcd.setCursor(2,0); 
    lcd.print("  Soil: Sandy"); 
  }
  else if (def == 4){
  lcd.setCursor(2,0); 
    lcd.print("  Soil: Silt");
  }

  if (typeDef == 1){
    lcd.setCursor(2,1); 
    lcd.print("  Type: Drip");
  }
  else if(typeDef == 2){
    lcd.setCursor(2,1); 
    lcd.print("Type: Sprinkler");
  }

  if (basedDef == 1){
    lcd.setCursor(1,2);
    lcd.print(F("Irrigation: Sensor"));
     lcd.setCursor(1,3);
     lcd.print(F("Press Any Key..."));
  }
  else if (basedDef == 2){
    lcd.setCursor(1,2);
    lcd.print(F("Irrigation: Timer"));
     lcd.setCursor(1,3);
    lcd.print(F("Press Any Key..."));

  }
}
void Timer_on(){
  unsigned long intervalOn = 180000;  
 unsigned long currentMillis = millis();

 if (currentMillis - previousMillisTimer >= intervalTimer) {
    previousMillisTimer = currentMillis;

    if(typeDef == 1){

      if (dripState == HIGH){
        lcd.clear();
        lcd.setCursor(5,2);
        lcd.print("PUMP IS ON");
        dripState = LOW;
        intervalTimer = intervalOn;
      }
      else{
        lcd.clear();
        lcd.setCursor(5,2);
        lcd.print("PUMP IS OFF");
        dripState = HIGH;
        intervalTimer = intervalOff;
        loop_timer = 0;
      
      }

      digitalWrite(drip, dripState);
      digitalWrite(relaymod,dripState);
      
      // digitalWrite(drip,LOW);
      // digitalWrite(sprinkler,HIGH);
      // digitalWrite(relaymod,LOW);
      // digitalWrite(10,HIGH);
      // delay(10000);
      // lcd.clear();
      // digitalWrite(drip,HIGH);
      // digitalWrite(sprinkler,HIGH);
      // digitalWrite(relaymod,HIGH);
    }
    if(typeDef == 2){
      if (sprinklerState == HIGH){
        lcd.setCursor(5,2);
        lcd.print("PUMP IS ON");
        sprinklerState = LOW;
        intervalTimer = intervalOn;
      }
      else{
        lcd.setCursor(6,2);
        lcd.print("PUMP IS OFF");
        sprinklerState = HIGH;
      intervalOff = intervalTimer ;
      }

      digitalWrite(sprinkler, sprinklerState);
      digitalWrite(relaymod,sprinklerState);
      // lcd.setCursor(5,2);
      // lcd.print("PUMP IS ON");  
      // digitalWrite(drip,HIGH);
      // digitalWrite(sprinkler,LOW);
      // digitalWrite(relaymod,LOW);  
      // delay(180000);
      // lcd.clear();
      //   digitalWrite(drip,HIGH);
      // digitalWrite(sprinkler,HIGH);
      // digitalWrite(relaymod,HIGH);
      
      }
 }
}
  
