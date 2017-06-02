#ifndef PULSEWIDTHMODULATION_CPP
#define PULSEWIDTHMODULATION_CPP

#include "pwmdriver.h"
#include "Arduino.h"
#include "settings.h"

PWMDriver::PWMDriver() {

  timer = -1;

}

int PWMDriver::selectTimer(int n) {

  switch (n) {
    case 3:

      timer = 3;
      pinA = 2;
      pinB = 3;
      pinC = 5;

    break;
    case 4:

      timer = 4;
      pinA = 6;
      pinB = 7;
      pinC = 8;

    break;
    case 5:

      timer = 5;
      pinA = 46;
      pinB = 45;
      pinC = 44;

    break;
    default:

      Serial.println("Not the right timer.");

    break;
  }

}

int PWMDriver::setFreq(double frequency) {

  if(DEBUG) {

    Serial.println("Calculating Prescaler and Count.");
    Serial.println("");
    Serial.print("Input Frequency: ");
    Serial.println(frequency);
    Serial.println("");

  }

  if(frequency > DRIVER_MAX_FREQUENCY || frequency <= 0.12) {

    // (16.000.000 / (1024 * (65536 - 1))) / 2 = 0,1192111086

    // 16-bit timer limits

    Serial.println("Frequency out of bounds.");

    return -1;

  }

  /*

  frequency = (clock / (prescaler * ( 1 + count))) / 2

  count = (clock / ( 2 * prescaler * frequency)) - 1

  */

  double count;
  long setCount = 0;
  int setPrescaler;

  for(int i = 0; i < 5; i++) {

    count = 2 * prescalerArray[i];

    count = count * frequency;

    count = CPU_F / count;

    count = count - 1;

    if(DEBUG) Serial.println(count);

    if(count > setCount && count <= RESOLUTION16-1) {

      setCount = (long)count;
      setPrescaler = prescalerArray[i];

    }

  }

  if(DEBUG) {

    Serial.println("");
    Serial.print("Count: ");
    Serial.println(setCount);
    Serial.print("Prescaler: ");
    Serial.println(setPrescaler);

  }

  prescaler = setPrescaler;
  count = setCount;

  return 1;

}

#endif
