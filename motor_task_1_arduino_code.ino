#include<SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial Display(2,3);
Servo drive;
byte servoPin=4;
String password="openservo",inputString="";

void setup() {
  Display.begin(9600);
  Serial.begin(9600); 
  drive.attach(servoPin); 
}

void take_serial_input(){
  while(!Serial.available());
  inputString=Serial.readString();
  Serial.println(inputString);
}

void hide_password(){
  byte len=inputString.length();
  for(int i=1;i<=len;i++) Display.print("*");
  Display.println();
}

void control_servo(){
  while(1){
    Display.println("Press 1 to start servo motor");
    take_serial_input();
    if(inputString=="1") break;
  }
  Display.println("Servo started");
  while(1){
    Display.println("Press 0 to stop servo motor");
    while(!Serial.available()){
      for(int i=0;i<=180;i++){
        drive.write(i);
        delay(5);
      }
      for(int i=180;i>=0;i--){
        drive.write(i);
        delay(5);
      }
    }
    take_serial_input();
    if(inputString=="0"){
        Display.println("Servo stopped");
        drive.write(0);
        break;
    }
  } 
}
void check_password(){
  if(inputString==password){
    Display.println("Access granted");
    control_servo();   
  }
  else{
    Display.println("Access denied");
  }
}

void loop() {
  Display.print("Enter password : ");
  take_serial_input();
  hide_password();
  check_password();
}
