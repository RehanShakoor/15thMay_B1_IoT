int R1=5,R2=4,R3=3,R4=2,C1=6,C2=7,C3=8;
int C1_stat,C2_stat,C3_stat;

void setup() {
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(C1,INPUT_PULLUP);
  pinMode(C2,INPUT_PULLUP);
  pinMode(C3,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
    
  digitalWrite(R1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  delay(50);
  C1_stat=digitalRead(C1);
  C2_stat=digitalRead(C2);
  C3_stat=digitalRead(C3);
  if(C1_stat==0) Serial.println("1 is pressed.");
  else if(C2_stat==0) Serial.println("2 is pressed.");
  else if(C3_stat==0) Serial.println("3 is pressed.");

  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  delay(50);
  C1_stat=digitalRead(C1);
  C2_stat=digitalRead(C2);
  C3_stat=digitalRead(C3);
  if(C1_stat==0) Serial.println("4 is pressed.");
  else if(C2_stat==0) Serial.println("5 is pressed.");
  else if(C3_stat==0) Serial.println("6 is pressed.");

  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,LOW);
  digitalWrite(R4,HIGH);
  delay(50);
  C1_stat=digitalRead(C1);
  C2_stat=digitalRead(C2);
  C3_stat=digitalRead(C3);
  if(C1_stat==0) Serial.println("7 is pressed.");
  else if(C2_stat==0) Serial.println("8 is pressed.");
  else if(C3_stat==0) Serial.println("9 is pressed.");

  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,LOW);
  delay(50);
  C1_stat=digitalRead(C1);
  C2_stat=digitalRead(C2);
  C3_stat=digitalRead(C3);
  if(C1_stat==0) Serial.println("* is pressed.");
  else if(C2_stat==0) Serial.println("0 is pressed.");
  else if(C3_stat==0) Serial.println("# is pressed.");
}
