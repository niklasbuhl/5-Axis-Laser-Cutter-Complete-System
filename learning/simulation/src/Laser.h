#ifndef LASER_H
#define LASER_H

#include "ofMain.h"

class Laser {

public:

  Laser(); // Contructor

  void setup();
  void update();
  void draw();

  void manualcontrol(int key, bool keyPressed);

  float moveX(int steps);
  float moveY(int steps);
  float moveZ(int steps);
  float rotateA(int steps); // Around the X axis
  float rotateB(int steps); // Aroudn the Y axis

private:

  void togglePositive(bool keyPressed, float(Laser::*func)(int), bool *positive, bool *negative);
  void toggleNegative(bool keyPressed, float(Laser::*func)(int), bool *positive, bool *negative);

  ofNode head;

  ofPlanePrimitive mirror;
  ofColor mirrorColor;

  ofColor laserColor;
  ofColor laserCuttingColor;

  float angle;
  float laserLength;

  float angleA;
  float angleB;

  bool movePosX, moveNegX, movePosY, moveNegY, movePosZ, moveNegZ, rotatePosA, rotateNegA, rotatePosB, rotateNegB;

};

#endif /* end of include guard: LASER_H */
