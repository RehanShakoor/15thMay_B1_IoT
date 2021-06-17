#include<EEPROM.h>
const byte LEDPin=13,SwitchPin=3,address1=0,address2=1;
byte count=EEPROM.read(address2);
bool LEDStatus=0;

void setup() {
  pinMode(LEDPin,OUTPUT);
  pinMode(SwitchPin,INPUT);
  changeDefaultValues();
}

void changeDefaultValues(){
  if(EEPROM.read(address2)==1 and EEPROM.read(address1)==1) EEPROM.write(address1,0);
  else if(EEPROM.read(address1)==255){ //factory set value.
    EEPROM.write(address1,0); 
    EEPROM.write(address2,1);
    count=EEPROM.read(address2);
  }
  else LEDStatus=EEPROM.read(address1);
  count++;
  EEPROM.write(address2,count); 
}

void checkStatus(){
  while(!digitalRead(SwitchPin));
  LEDStatus=!LEDStatus;
  EEPROM.write(address1,LEDStatus);
  while(digitalRead(SwitchPin));
}

void loop(){
  digitalWrite(LEDPin,EEPROM.read(address1));
  checkStatus(); 
}
