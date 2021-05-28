void setup() {
  for(int pin_no = 0;pin_no <= 7;pin_no++) pinMode(pin_no,OUTPUT);
  for(int pin_no = 13;pin_no >= 11;pin_no--) pinMode(pin_no,INPUT);
}
void pattern_1(){
    for(int pin_no = 0; pin_no <= 7;pin_no++){
    digitalWrite(pin_no,HIGH);
    delay(300);
    digitalWrite(pin_no,LOW);
  }

}
void pattern_2(){
  int left_LED = 4;
  for(int right_LED = 3;right_LED >=0 ;right_LED--){
    digitalWrite(right_LED,HIGH);
    digitalWrite(left_LED,HIGH);
    delay(500);
    digitalWrite(right_LED,LOW);
    digitalWrite(left_LED,LOW);
    left_LED++;
  }
}

void pattern_3(){
  int left_LED = 7;
  for(int right_LED = 0;right_LED <=3 ;right_LED++){
    digitalWrite(right_LED,HIGH);
    digitalWrite(left_LED,HIGH);
    delay(500);
    digitalWrite(right_LED,LOW);
    digitalWrite(left_LED,LOW);
    left_LED--;
  }
}

void loop() {
  
  int pattern1 = digitalRead(13);
  int pattern2 = digitalRead(12);
  int pattern3 = digitalRead(11);

  if(pattern1) pattern_1();
  if(pattern2) pattern_2();
  if(pattern3) pattern_3();
  
}
