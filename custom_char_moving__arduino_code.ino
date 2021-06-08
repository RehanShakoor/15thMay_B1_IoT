#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,4,5,6,7);
int r=0,c=0;
byte smiley[8]={
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b01010,
    0b00100,
    0b00000,
    0b00000
};
void setup() {
}

void loop() {
  lcd.createChar(1,smiley);
  lcd.begin(16,2);
  for(c=0;c<=15;c++) {
    lcd.setCursor(c,0);
    lcd.write(1);
    delay(200);
    lcd.clear();
  }  
 }
