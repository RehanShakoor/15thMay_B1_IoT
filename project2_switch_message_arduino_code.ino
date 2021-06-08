#include<LiquidCrystal.h>
LiquidCrystal lcd(9,8,4,5,6,7);

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
  for(int i=1;i<=3;i++) pinMode(i,OUTPUT); 
}

void display_custom(){
  lcd.setCursor(0,0);
  lcd.createChar(1,smiley);
  lcd.begin(16,2);
  lcd.write(1);
}

void move_custom(){
  lcd.setCursor(0,0);
  lcd.createChar(1,smiley);
  for(int j=5;j>=1;j--){
    for(int i=0;i<=15;i++){
      lcd.setCursor(i,0);
      lcd.write(1);
      delay(j*20);
      lcd.clear(); 
    }
  } 
}

void display_message(){
  lcd.setCursor(0,0);
  lcd.print("You have pressed a button.");
}

void scroll_message(){
  lcd.setCursor(0,0);
  int len=26;
  for(int i=-1;i>=-1*len;i--){
    lcd.setCursor(i,0);
    lcd.print("You have pressed a button.");
    delay(200);
    lcd.clear();
  }
  lcd.setCursor(16,0);
  lcd.print("You have pressed a button.");
  for(int i=15;i>=-1* (len-16);i--){
    lcd.setCursor(i,0);
    lcd.print("You have pressed a button.");
    delay(200);
    lcd.clear();
  }
}
void loop() {
  if(digitalRead(0)) display_message();
  else if(digitalRead(1)) scroll_message();
  else if(digitalRead(2)) display_custom();
  else if(digitalRead(3)) move_custom();
}
