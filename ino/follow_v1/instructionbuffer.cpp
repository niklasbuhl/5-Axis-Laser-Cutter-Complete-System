#ifndef INSTRUCTIONBUFFER_CPP
#define INSTRUCTIONBUFFER_CPP

#include "instructionbuffer.h"
#include "settings.h"
#include "arduino.h"

InstructionBuffer::InstructionBuffer() {

  for(int i = 0; i < BUFFERSIZE; i++) {

    buffer[i].instructionPtr = &instructions[i];

  }

  for(int i = 0; i < BUFFERSIZE - 1; i++) {

    buffer[i].nextNode = &buffer[i+1];

  }

  buffer[BUFFERSIZE].nextNode = &buffer[0];

  head = &buffer[0];
  tail = &buffer[0];


}

int InstructionBuffer::add(Instruction instruction) {

  if(DEBUG) {

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

  /*

  head->instructionPtr.freqX = instruction.freqX;
  head->instructionPtr.freqY = instruction.freqY;
  head->instructionPtr.freqZ = instruction.freqZ;
  head->instructionPtr.duration = instruction.duration;

  */

  if(DEBUG) {

    Serial.println("Added Instruction");

    Instruction *instructionPtr;

    instructionPtr = head->instructionPtr;

    /*

    Serial.print("FreqX:");
    Serial.println(instructionPtr->freqX);
    Serial.print("FreqY:");
    Serial.println(instructionPtr->freqY);
    Serial.print("FreqZ:");
    Serial.println(instructionPtr->freqZ);
    Serial.print("Duration:");
    Serial.println(instructionPtr->duration);

    */

    print(instructionPtr);

  }

  head = head->nextNode;

  return 1;

}

void InstructionBuffer::printAll() {

 Node *ptr = tail;

 /*

 while(ptr != head) {

 }

 */


}

void InstructionBuffer::print(Instruction &instructionPtr) {

  

  Serial.print("FreqX:");
  Serial.println(instructionPtr->freqX);
  Serial.print("FreqY:");
  Serial.println(instructionPtr->freqY);
  Serial.print("FreqZ:");
  Serial.println(instructionPtr->freqZ);
  Serial.print("Duration:");
  Serial.println(instructionPtr->duration);

}

void InstructionBuffer::printHead() {

  Serial.println("Head Instruction");
  Serial.print("FreqX:");
  Serial.println(head->instructionPtr->freqX);
  Serial.print("FreqY:");
  Serial.println(head->instructionPtr->freqY);
  Serial.print("FreqZ:");
  Serial.println(head->instructionPtr->freqZ);
  Serial.print("Duration:");
  Serial.println(head->instructionPtr->duration);

}

Instruction InstructionBuffer::remove() {

  Instruction instruction;

  instruction = *tail->instructionPtr;

  return instruction;

}

#endif
