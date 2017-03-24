#include "settings.h"

void setup() {

  if(DEBUG_MODE && CONNECTED_TO_PC) {
      Serial.begin(115200);
      while(!Serial);
      Serial.println("Hello, World!");

  }

}

void loop() {

  // Listen to I2C

  // Write to I2C

}

// Instruction Buffer

// Interrupt Reload

// Preload PWM Timer
