#include<SoftwareSerial.h>
SoftwareSerial BT(2,3);

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}

char serialInput;
void loop() {
  if(Serial.available()>0){
    serialInput=Serial.read();
    BT.print("BT ");
    BT.print(serialInput);
    BT.println();
  }
}
