#include<EEPROM.h>

const byte tempPin1=A0,tempPin2=A1;
int address=0,inputAddress=0;


void setup() {
  Serial.begin(9600);
}

float readTemp(){
  int reading1=0,reading2=0;
  float voltage=0,temp;
  reading1=analogRead(tempPin1);
  reading2=analogRead(tempPin2);
  voltage=(reading2-reading1)*5/1023.0;
  temp=voltage*100;
  return temp;
}

void printTemp(){
  inputAddress=Serial.parseInt();
  Serial.println(inputAddress);
  Serial.print("Temp. = ");
  Serial.print(EEPROM.read(inputAddress));
  Serial.println();
}


void loop() {
  Serial.print("Enter address of EEPROM : ");
  while(!Serial.available()){
    if(address>1023) address=0;
    EEPROM.write(address,readTemp());
    address++;
  }
  printTemp();   
}
