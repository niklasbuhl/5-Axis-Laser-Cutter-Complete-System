#include "instructionbuffer.h"
#include "settings.h"
#include "arduino.h"

InstructionBuffer::InstructionBuffer() {

  for(int i = 0; i < BUFFERSIZE; i++) {

    buffer[i].instructionPtr = &instructions[i];
    buffer[i].index = i + 1;

  }

  for(int i = 0; i < BUFFERSIZE - 1; i++) {

    buffer[i].next = &buffer[i+1];
    buffer[i+1].prev = &buffer[i];


  }

  buffer[BUFFERSIZE].next = &buffer[0];
  buffer[0].prev = &buffer[BUFFERSIZE];

  head = &buffer[0];
  tail = &buffer[0];

}

int InstructionBuffer::add(Instruction instruction) {

  if(DEBUG_INSTRUCTION_BUFFER) {

    Serial.println("Adding Instruction");
    Serial.print("FreqX:");
    Serial.println(instruction.freqX);
    Serial.print("FreqY:");
    Serial.println(instruction.freqY);
    Serial.print("FreqZ:");
    Serial.println(instruction.freqZ);
    Serial.print("Duration:");
    Serial.println(instruction.duration);

  }

  Instruction **tmpInstructionPtrPtr;
  tmpInstructionPtrPtr = &head->instructionPtr;
  **tmpInstructionPtrPtr = instruction;

  if(DEBUG_INSTRUCTION_BUFFER) {

    Serial.println("Added Instruction");

    Instruction *instructionPtr;

    instructionPtr = head->instructionPtr;

    Serial.print("FreqX:");
    Serial.println(instructionPtr->freqX);
    Serial.print("FreqY:");
    Serial.println(instructionPtr->freqY);
    Serial.print("FreqZ:");
    Serial.println(instructionPtr->freqZ);
    Serial.print("Duration:");
    Serial.println(instructionPtr->duration);

    printInstruction(instructionPtr);

  }

  head = head->next;
  count++;

  return 1;

}

void InstructionBuffer::printAll() {

 Node *ptr = tail;

 for(int i = 0; i < count; i++) {

   printBufferNode(ptr);

   ptr = ptr->next;

 }

}

void InstructionBuffer::printBufferNode(Node *node) {

  Serial.print("Printing buffer node: ");
  Serial.println(node->index);

  printInstruction(node->instructionPtr);

}

void InstructionBuffer::printInstruction(Instruction *instructionPtr) {

  Serial.print("FreqX:");
  Serial.println(instructionPtr->freqX);
  Serial.print("FreqY:");
  Serial.println(instructionPtr->freqY);
  Serial.print("FreqZ:");
  Serial.println(instructionPtr->freqZ);
  Serial.print("Duration:");
  Serial.println(instructionPtr->duration);
  Serial.println();

}

void InstructionBuffer::printHead() {

  Serial.println("Head Instruction.");
  Serial.print("Head Index: ");
  Serial.println(head->index);
  Serial.print("FreqX:");
  Serial.println(head->instructionPtr->freqX);
  Serial.print("FreqY:");
  Serial.println(head->instructionPtr->freqY);
  Serial.print("FreqZ:");
  Serial.println(head->instructionPtr->freqZ);
  Serial.print("Duration:");
  Serial.println(head->instructionPtr->duration);
  Serial.println();

}

Instruction InstructionBuffer::remove() {

  Instruction instruction;

  instruction = *tail->instructionPtr;

  tail = tail->next;

  count--;

  return instruction;

}

void Instruction::set(unsigned int _freqX, unsigned int _freqY, unsigned int _freqZ, unsigned int _duration) {

  freqX = _freqX;
  freqY = _freqY;
  freqZ = _freqZ;

  duration = _duration;

}
