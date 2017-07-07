#include "pwmdriver.h"
#include "settings.h"
#include "instructionbuffer.h"

PWMDriver stepperX;
InstructionBuffer buffer;

void setup() {

  Serial.begin(115200);

  delay(500);

  Serial.println();
  Serial.println("Hello, World!");
  Serial.println();

  // Testing

  Instruction instruction;

  instruction.set(1337,42,27,1234);
  buffer.add(instruction);

  instruction.set(2,3,4,5);
  buffer.add(instruction);

  buffer.remove();

  instruction.set(7,9,13,100);
  buffer.add(instruction);

  buffer.printAll();

  buffer.printHead();

}

void loop() {

}
