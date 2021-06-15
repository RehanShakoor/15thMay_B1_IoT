#include<Servo.h>
#include<SoftwareSerial.h>
Servo drive;
SoftwareSerial Display(2,3);

byte servoPin=4,errorCount=0;
String password="open",inputString="";

void setup() {
  drive.attach(servoPin);
  Serial.begin(9600);
  Display.begin(9600);
}

void take_serial_input(){
  while(!Serial.available());
  inputString=Serial.readString();
  Serial.println(inputString);
}

void hide_password(){
  byte len=inputString.length();
  for(int i=0;i<=len;i++) Display.print('*');
  Display.println();
}

void open_gate(){
  Display.println("Opening gate");
  byte openningTime=5,openningSteps=1;
  for(int i=0;i<=180;i+=openningSteps){
    drive.write(i);
    delay((openningTime*1000)/(180/openningSteps));
  }
  unsigned long int current=0;
  byte count=0;
  while(1){
   if(millis()>=current+1000){
     Display.print("Gate will remain opened for ");
     Display.print(30-count);
     Display.print(" sec.");
     Display.println();
     current=millis();
     count++;
   }
   if(count==30) break;
  }
  Display.println("Clossing gate");
  drive.write(0);
}

void check_password(){
  if(inputString==password) {
    Display.println("Access granted");
    errorCount=0;
    open_gate();
  }
  else{
   errorCount++;
   Display.println("Access denied, ");
   Display.print(3-errorCount);
   Display.print(" attempts left.");
   Display.println();
   if(errorCount==3) {
    Display.println("Max. limit reaches. Restart the system.");
    while(1);
   }
   else{
    Display.print("Enter password : ");
    take_serial_input();
    hide_password();
    check_password();
   }
  }
}

void loop(){
  Display.print("Enter password : ");
  take_serial_input();
  hide_password();
  check_password();
}
