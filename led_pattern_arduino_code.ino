void setup() {
  for(int i=7;i<=13;i++) pinMode(i,OUTPUT);
  for(int i=1;i<=3;i++) pinMode(i,INPUT);
}

void pattern1(){
  for(int i=7;i<=13;i++){
    digitalWrite(i,HIGH);
    delay(200);
    digitalWrite(i,LOW);
  }
}

void pattern2(){
  int left_led=7;
  int right_led=13;
  while(left_led<=right_led){
    digitalWrite(left_led,HIGH);
    digitalWrite(right_led,HIGH);
    delay(200);
    digitalWrite(left_led,LOW);
    digitalWrite(right_led,LOW);
    left_led++;
    right_led--;    
  } 
}


void pattern3(){
  int left_led=10;
  int right_led=10;
  while(left_led>=7){
    digitalWrite(left_led,HIGH);
    digitalWrite(right_led,HIGH);
    delay(200);
    digitalWrite(left_led,LOW);
    digitalWrite(right_led,LOW);
    left_led--;
    right_led++;    
  } 
}



void loop() {
  if(digitalRead(1)) pattern1();
  else if(digitalRead(2)) pattern2();
  else if(digitalRead(3)) pattern3();
}
