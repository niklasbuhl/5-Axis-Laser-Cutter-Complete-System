#ifndef PULSEWIDTHMODULATION_H
#define PULSEWIDTHMODULATION_H

#define CPU_F 16000000
#define RESOLUTION8 256 // Maximum timer count (8bit) = 256
#define RESOLUTION16 65536 // Maximum timer count (16bit) = 65536

// Pin 11 and 12: Timer1 (8bit)
// Pin 9 and 10: Timer2 (8bit)

class PWMDriver {

public:

  PWMDriver();

  int selectTimer(int n);

  int setFreq(double frequency);

  int reset();
  int start();
  int pause();
  int stop();

private:

  int timer;

  int resolution;

  int count, prescaler;

  int pinA, pinB, pinC;

  // Registers: x (timer), n (pin)

  int *TimerCountControlReg;          // TCCRxn   Timer / Counter Control Register (Prescaler & Mode).
  int *TimerCounterReg;               // TCNTx    Timer / Counter Register (The actual timer value).
  int *OutputCompareReg;              // OCRxA    Output Compare Register.
  int *InputCaptureReg;               // ICRx     Input Capture Register (16bit).
  int *TimerCounterInterruptMaskReg;  // TIMSKx   Timer/Counter Interupt Mask Register (Enable/Disable Timer Interrupts).
  int *TimerCounterInterruptFlagReg;  // TIFRx    Timer/Counter Interrupt Flag Register Indicates a pending timer intererupt.

  int *functionPtr;

  int prescalerArray[5] = {1,8,16,256,1024};

};

#endif
