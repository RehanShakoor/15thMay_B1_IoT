#include<Keypad.h>

char keys[4][3]={
  {'A','B','C'},
  {'D','E','F'},
  {'G','H','I'},
  {'J','K','L'}
};
byte row[4]={5,4,3,2};
byte column[3]={6,7,8};
Keypad keypad=Keypad(makeKeymap(keys),row,column,4,3); 

void setup() {
  Serial.begin(9600);
}

void loop() {
  char k=keypad.getKey();
  if(k)
  {
    Serial.println(k);
  }

}
