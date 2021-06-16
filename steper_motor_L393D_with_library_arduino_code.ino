#include<Stepper.h>
const int stepsPerRev=10;
Stepper steps(stepsPerRev,0,1,2,3);

void setup() {
  steps.setSpeed(5);
}

void loop() {
  steps.step(stepsPerRev);
}
