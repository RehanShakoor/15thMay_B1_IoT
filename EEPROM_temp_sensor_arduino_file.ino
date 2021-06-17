#include<EEPROM.h>

const byte tempPin1=A0,tempPin2=A1;
byte address=0;
int reading1=0,reading2=0;
float voltage=0,temp;

void setup() {
  Serial.begin(9600);
}

void readTemp(){
  reading1=analogRead(tempPin1);
  reading2=analogRead(tempPin2);
  voltage=(reading2-reading1)*5/1023.0;
  temp=voltage*100;
  EEPROM.write(address,temp);
}



void loop() {
  Serial.print("Enter address of EEPROM : ");
  while(!Serial.available()) readTemp();
  address=Serial.parseInt();
  Serial.println(address);
  Serial.print("Temp. = ");
  Serial.print(EEPROM.read(address));
  Serial.println(); 
}
