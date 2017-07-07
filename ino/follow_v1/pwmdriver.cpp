#include "pwmdriver.h"
#include "Arduino.h"
#include "settings.h"

PWMDriver::PWMDriver() {

  timer = -1;

}

int PWMDriver::selectTimer(int n) {

  switch (n) {

    case 1:

      Serial.println("Don't use this timer.");
      return false;
      break;

    case 2:

      Serial.println("Don't use this timer.");
      return false;
      break;

    case 3:

      timer = 3;
      pinA = 2;
      pinB = 3;
      pinC = 5;
      return true;
      break;

    case 4:

      timer = 4;
      pinA = 6;
      pinB = 7;
      pinC = 8;
      return true;
      break;

    case 5:

      timer = 5;
      pinA = 46;
      pinB = 45;
      pinC = 44;
      return true;
      break;

    default:

      Serial.println("Not the right timer.");
      return false;
      break;

  }

}

int PWMDriver::setFreq(double frequency) {

  if(DEBUG_PWMDRIVER) {

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

    return false;

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

    if(DEBUG_PWMDRIVER) Serial.println(count);

    if(count > setCount && count <= RESOLUTION16-1) {

      setCount = (long)count;
      setPrescaler = prescalerArray[i];

    }

  }

  if(DEBUG_PWMDRIVER) {

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
