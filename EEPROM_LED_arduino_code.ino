#include<EEPROM.h>
const byte LEDPin=13,SwitchPin=3,address=0;
bool LEDStatus=EEPROM.read(address);

void setup() {
  pinMode(LEDPin,OUTPUT);
  pinMode(SwitchPin,INPUT);
}

void checkStatus(){
  while(!digitalRead(SwitchPin));
  LEDStatus=!LEDStatus;
  EEPROM.write(address,LEDStatus);
  while(digitalRead(SwitchPin));
}

void loop(){
  if(EEPROM.read(address)==255) EEPROM.write(address,0); 
  digitalWrite(LEDPin,EEPROM.read(address));
  checkStatus(); 
}






//void loop() {
//  if(EEPROM.read(address)==255) SwitchStatus=digitalRead(SwitchPin); 
//  else SwitchStatus=EEPROM.read(address); 
//  
//  if(SwitchStatus) digitalWrite(LEDPin,HIGH);
//  else digitalWrite(LEDPin,LOW);
//
//  if(digitalRead(SwitchPin)){
//    
//  }
//  
//  SwitchStatus=digitalRead(SwitchPin);
//  EEPROM.write(address,SwitchStatus);
//}
