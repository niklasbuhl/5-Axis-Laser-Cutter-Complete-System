#ifndef INSTRUCTIONBUFFER_H
#define INSTRUCTIONBUFFER_H

#define BUFFERSIZE 256

struct Instruction {

  unsigned int freqX; // 0 to 4.294.967.295
  unsigned int freqY;
  unsigned int freqZ;
  unsigned int duration; // Microseconds

  void set(unsigned int freqX, unsigned int freqY, unsigned int freqZ, unsigned int duration);

};



struct Node {

  int index;
  Instruction *instructionPtr;
  Node *next;
  Node *prev;

};

class InstructionBuffer {

public:

  InstructionBuffer();

  int add(Instruction instruction);
  Instruction remove();

  void printBufferNode(Node *node);
  void printInstruction(Instruction *instructionPtr);

  void printAll();
  void printHead();
  void printTail();

private:

  int locked;

  Instruction instructions[BUFFERSIZE];
  Node buffer[BUFFERSIZE];

  int count;

  Node *head;
  Node *tail;

};

#endif
