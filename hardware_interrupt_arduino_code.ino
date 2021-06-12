volatile int x=0;

void setup() {
  attachInterrupt(digitalPinToInterrupt(2),ISR1,RISING); 
  attachInterrupt(digitalPinToInterrupt(3),ISR2,RISING);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13,x);  
}

void ISR1(){
  x=1;
  Serial.println("Interrupt 1 is called , LED ON");
}

void ISR2(){
  x=0;
  Serial.println("Interrupt 2 is called , LED OFF");
}
