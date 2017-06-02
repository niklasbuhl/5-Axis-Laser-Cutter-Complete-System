#include "pwmdriver.h"
#include "settings.h"
#include "instructionbuffer.h"

PWMDriver stepperX;
InstructionBuffer buffer;

void setup() {

  Serial.begin(115200);

  delay(500);

  Serial.println("Hello, World!");

  Instruction instruction;

  instruction.freqX = 1337;
  instruction.freqY = 42;
  instruction.freqZ = 27;
  instruction.duration = 1234;


  buffer.add(instruction);

  buffer.printHead();

  /*

  stepperX.setFreq(1000);
  stepperX.setFreq(2000);
  stepperX.setFreq(200000);
  stepperX.setFreq(7);
  stepperX.setFreq(0.5);
  stepperX.setFreq(0.2);
  stepperX.setFreq(0.25);
  stepperX.setFreq(0.01);

  */

}

void loop() {

}
