void setup() {
  pinMode(13,OUTPUT);
  for(int i=1;i<=5;i++) pinMode(i,OUTPUT);
}

void alarm1(){
  digitalWrite(13,HIGH);
  tone(11,1000);
  delay(2000);
  noTone(11);
  digitalWrite(13,LOW);  
}

void alarm2(){
  digitalWrite(13,HIGH);
  tone(11,2000);
  delay(4000);
  noTone(11);
  digitalWrite(13,LOW);
}

void alarm3(){
  digitalWrite(13,HIGH);  
  tone(11,3000);
  delay(6000);
  noTone(11);
  digitalWrite(13,LOW);  
}

void alarm4(){
  digitalWrite(13,HIGH);  
  tone(11,4000);
  delay(8000);
  noTone(11);
  digitalWrite(13,LOW);  
}

void alarm5(){
  digitalWrite(13,HIGH);  
  tone(11,5000);
  delay(10000);
  noTone(11);
  digitalWrite(13,LOW);  
}

void loop(){
  if(digitalRead(1)) alarm1();
  else if(digitalRead(2)) alarm2();
  else if(digitalRead(3)) alarm3();    
  else if(digitalRead(4)) alarm4();
  else if(digitalRead(5)) alarm5();  
}
