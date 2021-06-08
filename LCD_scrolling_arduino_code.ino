#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,4,5,6,7);
int len=43;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("This is a test string for testing scrolling");
  delay(1000);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("This is a test string for testing scrolling");
  delay(1000);
  for(int i=-1;i>=(-1*len);i--){
    lcd.setCursor(i,0);
    lcd.print("This is a test string for testing scrolling");
    delay(100);
    lcd.clear();
    delay(10);
  }
  delay(300);
  lcd.setCursor(16,0);
  lcd.print("This is a test string for testing scrolling");
  for(int i=15;i>=-1*(len-16);i--){
    lcd.setCursor(i,0);
    lcd.print("This is a test string for testing scrolling");
    delay(100);
    lcd.clear();
    delay(10);
  }
  delay(300);
}
