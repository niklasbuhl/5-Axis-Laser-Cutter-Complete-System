#ifndef INSTRUCTIONBUFFER_H
#define INSTRUCTIONBUFFER_H

#define BUFFERSIZE 256

struct Instruction {

  unsigned long freqX; // 0 to 4.294.967.295
  unsigned long freqY;
  unsigned long freqZ;
  unsigned long duration; // Microseconds

};

struct Node {

  Instruction *instructionPtr;
  Node *nextNode;

};

class InstructionBuffer {

public:

  InstructionBuffer();

  int add(Instruction instruction);
  Instruction remove();
  void print(Instruction &instructionPtr);
  void printAll();
  void printHead();

private:

  int locked;

  Instruction instructions[BUFFERSIZE];
  Node buffer[BUFFERSIZE];

  Node *head;
  Node *tail;

};

#endif
