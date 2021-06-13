#include<LiquidCrystal.h>
#include<Keypad.h>
LiquidCrystal lcd(13,12,11,10,9,8);
char keys[4][3]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};

byte rows[4]={7,2,1,0};
byte columns[3]={4,5,6};
byte buzzer=A0,counter=0,cursor_index=0;
bool alarm_on=0;
unsigned long current_millis=0;
String password8Digit="77658144",password4Digit="9835",inputPassword="";

Keypad keypad=Keypad(makeKeymap(keys),rows,columns,4,3);

void setup() {
 lcd.begin(16,2);
 pinMode(A0,OUTPUT);
 pinMode(A1,OUTPUT);
}

void alarm_millis_delay(int sec){
  unsigned long current_millis=millis();
  while(current_millis+(sec*1000)>=millis()){
    if(keypad.getKey()=='*'){
      alarm_on=0;
      break;
    }
  }
}

void alarm(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Alarm is ON");
  alarm_on=1;
  current_millis=millis();
  while(current_millis+30000>=millis()){
    if(alarm_on){
      tone(buzzer,1000);
      alarm_millis_delay(1);
      noTone(buzzer);
      alarm_millis_delay(1);
    }
    else break;
  }
}

void take_password(int len){
  lcd.setCursor(0,1);
  cursor_index=0;
  while(!(inputPassword.length()==len)){
    char passKey=keypad.waitForKey();
    if(passKey=='*') {
      change_password();
      break;
    }
    else if(passKey=='#'){
      if(cursor_index>=1){
        lcd.setCursor(cursor_index-1,1);
        lcd.print(" ");
        lcd.setCursor(cursor_index-1,1);
        cursor_index--;
        inputPassword.remove(inputPassword.length()-1);
      }
      else;
    }
    else{
      inputPassword+=passKey;
      lcd.print("*");
      cursor_index++;
      if(inputPassword.length()==len) delay(200);
    }
  }
}

void take_password4(){
  lcd.clear();
  lcd.setCursor(0,0);
  inputPassword="";
  lcd.print("Enter password");
  take_password(4);
}

void change_password(){
  lcd.clear();
  lcd.setCursor(0,0);
  inputPassword="";
  lcd.print("Enter master pas");
  take_password(8);  
  if(inputPassword==password8Digit){
    lcd.clear();
    lcd.setCursor(0,0);
    inputPassword="";
    lcd.print("Enter new pass.");
    take_password(4);
    password4Digit=inputPassword;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password changed");
    delay(1000);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wrong master pas");
    delay(500);
  }
}

bool password_check(){
  if(inputPassword==password4Digit){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Access granted");
    delay(500);
    return true;
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Access denied");
    delay(500);
    return false;
  }
}

void loop(){
   take_password4();
   counter=1;
   while(1){
     if(password_check()) break;
     if(!password_check()){
      counter++;
      take_password4();
     }
     if(counter==3 and !password_check()){
      alarm();
      change_password();
      break;
     }
   }
}
