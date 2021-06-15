#include<Servo.h>
#include<LiquidCrystal.h>
Servo drive;
LiquidCrystal lcd(13,12,11,10,9,8);
byte servoPin=6,buttonPin=2,buttonCount=-1,lastServoState=0,timeCount=0;
unsigned long current=0;

void setup() {
  lcd.begin(16,2);
  drive.attach(servoPin);
  attachInterrupt(digitalPinToInterrupt(buttonPin),button_ISR,RISING);
}

void button_ISR(){
  buttonCount++;
}

void closeGate(){
  current=millis();
  lcd.clear();
  for(int i=lastServoState;i>=0;i--){
    lcd.setCursor(0,0);
    lcd.print("Clossing gate ");
    drive.write(i);
    delay(100);
    if(current+1000<=millis()){
      lcd.clear();
      current=millis();
      lcd.print("Clossing gate ");
      lcd.setCursor(0,1);
      lcd.print(timeCount-4);
      timeCount--;
    }
    if(timeCount==4) {
      delay(300);
      break;
    }
  }
}

void openGate(){
  lcd.clear();
  current=millis();
  timeCount=0;
  for(int i=0;i<=180;i++){ 
    if(buttonCount==2 or timeCount==14){
      delay(500);
      lastServoState=i;
      closeGate();
      break;
    }
    lcd.setCursor(0,0);
    if(timeCount<4){
      lcd.print("Starting motor");//servo takes time to start.
      delay(60);  
    }
    drive.write(i);
    delay(90);
    if(current+1000<=millis()){
      current=millis();
      if(timeCount>=4){
        lcd.print("Openning gate  ");
        lcd.setCursor(0,1);
        lcd.print(timeCount-3);
      }
      timeCount++;
    }
 }
}

void loop() {
  buttonCount=0;
  lcd.clear();
  delay(100);
  lcd.print("Press button to open gate");
  delay(300);
  for(int i=0;i>=-25;i--){
    lcd.setCursor(i,0);
    lcd.print("Press button to open gate");
    delay(200);
    lcd.clear();
    if(buttonCount==1) {
      openGate();
      break;
    }
  }
}
