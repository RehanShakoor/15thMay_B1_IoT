#include<Keypad.h>
#include<LiquidCrystal.h>

byte num1,num2;
char num1char,num2char,operation;
float result;

LiquidCrystal lcd(13,12,11,10,9,8);

char keys[4][4]={{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'k','0','=','+'}};
char digits[10]={'0','1','2','3','4','5','6','7','8','9'};
byte row[4]={7,6,5,4};
byte column[4]={3,2,1,0};

Keypad keypad=Keypad(makeKeymap(keys),row,column,4,4);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  num1char=keypad.waitForKey();
  FindNum1(); 
  lcd.print(num1);
  
  operation=keypad.waitForKey();
  lcd.print(operation);
  
  num2char=keypad.waitForKey();
  FindNum2();
  lcd.print(num2);
  
  keypad.waitForKey();
  lcd.print("=");
  
  calculations();
  keypad.waitForKey();
  lcd.clear();
}  

void calculations(){
  if(operation=='/'){
    result=float(num1)/num2;
    lcd.print(result);
  }
  else if(operation=='x'){
    result=num1*num2;
    lcd.print(result);
  }
  else if(operation=='-'){
    result=num1-num2;
    lcd.print(result);
  }
  else if(operation=='+'){
    result=num1+num2;
    lcd.print(result);
  }
}

void FindNum1(){
  for(int i=0;i<=9;i++){
    if(digits[i]==num1char){
      num1=num1char-'0';
      break;
    }
  }
}

void FindNum2(){
  for(int i=0;i<=9;i++){
    if(digits[i]==num2char){
      num2=num2char-'0';
      break;
    }
  } 
}
