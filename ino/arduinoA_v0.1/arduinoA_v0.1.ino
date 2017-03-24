#include "settings.h"

void setup() {

  pinMode(13, OUTPUT);

  if(DEBUG_MODE && CONNECTED_TO_PC) {
      Serial.begin(115200);
      while(!Serial);
      Serial.println("Hello, World!");

  }

  // Initialize Instuction Buffer

  // Communicate to RPi

  // Ready!

}

void loop() {

  digitalWrite(13, HIGH);

  delay(200);

  digitalWrite(13, LOW);

  delay(200);

  // Listen to I2C

  // Write to I2C

}

// Instruction Buffer

// Interrupt Reload

// Preload PWM Timer
