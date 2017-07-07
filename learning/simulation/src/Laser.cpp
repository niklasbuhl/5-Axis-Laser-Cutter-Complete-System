#include "ofMain.h"
#include "Laser.h"
#include "settings.h"

// Contructor

Laser::Laser() {

  // Head
  head.setPosition(HEAD_START_X, HEAD_START_Y, HEAD_START_Z);

  // Head Mirror
  mirror.setParent(head);
  mirror.setPosition(0, 0, 0);
  mirror.set(50,50);
  head.rotate(45,0,1,0);

  // Laser Origin is head global position

  // Laser Element Point of Entry

  // Laser Element Point of Exit

  poEntry.setParent(head);
  poExit.setParent(head);

  laserColor = ofColor(200,0,200); // Pink
  laserCuttingColor = ofColor(255,0,255); // Bright Pink
  mirrorColor = ofColor(0,255,255); // Cyan

  angle = mirror.getLookAtDir().angle(ofVec3f(-1,0,0));

  printf("Entry Angle is Exit Angle: %f\n", angle);

  laserLength = head.getZ() / cos(angle);

}

// Update

void Laser::update() {

  // Move


  // Calculate normalized angle
  angle = head.getLookAtDir().angle(ofVec3f(0,0,-1));

  // Calculate lasercutting length
  laserLength = head.getZ() / cos(angle);

  // Debugging length
  if(DEBUG_LASER_UPDATE) printf("Getting Head Height: %f.\n", laserLength);

  // Set laser destination
  poExit.setPosition(0,0,-laserLength);

  // Quaternion
  if(DEBUG_LASER_UPDATE) {

    ofQuaternion ofQ = head.getOrientationQuat();

    printf("Quaternion - x: %f, y: %f, z: %f, w: %f.",ofQ.w(),ofQ.w(),ofQ.w(),ofQ.w());

  }

}

// Draw

void Laser::draw() {


  ofSetColor(laserColor);
  ofDrawArrow(head.getGlobalPosition(),poExit.getGlobalPosition());

  ofSetColor(mirrorColor);
  mirror.draw();

  //head.draw();

  //poExit.draw();

}

// Control

void Laser::manualcontrol(int key, bool keyPressed) {

  switch(key) {

    case 'd': // Positive X
    case 'D':
      togglePositive(keyPressed, &Laser::moveX, &movePosX, &moveNegX);
      break;

    case 'a': // Negative X
    case 'A':
      toggleNegative(keyPressed, &Laser::moveX, &movePosX, &moveNegX);
      break;

    case 's': // Positive Y
    case 'S':
      togglePositive(keyPressed, &Laser::moveY, &movePosY, &moveNegY);
      break;

    case 'w': // Negative Y
    case 'W':
      toggleNegative(keyPressed, &Laser::moveY, &movePosY, &moveNegY);
      break;

    case 32: // Posititve Z
      togglePositive(keyPressed, &Laser::moveZ, &movePosZ, &moveNegZ);
      break;

    case 2304: // Negative Z
    case 2305:
      toggleNegative(keyPressed, &Laser::moveZ, &movePosZ, &moveNegZ);
      break;

    case 358: // Positive A
      togglePositive(keyPressed, &Laser::rotateA, &rotatePosA, &rotatePosA);
      break;

    case 356: // Negative B
      toggleNegative(keyPressed, &Laser::rotateA, &rotatePosA, &rotatePosA);
      break;

    case 357: // Positive B
      togglePositive(keyPressed, &Laser::rotateB, &rotatePosB, &rotatePosB);
      break;

    case 359: // Negative A
      toggleNegative(keyPressed, &Laser::rotateB, &rotatePosB, &rotatePosB);
      break;

    default:
    break;

  }
}

void Laser::togglePositive(bool keyPressed, float(Laser::*func)(int), bool *positive, bool *negative) {

  if(!*positive && !*negative && keyPressed) {

    *positive = true;

    //(this->*func)(1);

  } else if(*positive && !keyPressed) {

    *positive = false;

  }

  //if(*positive) (this->*func)(1);

}

void Laser::toggleNegative(bool keyPressed, float(Laser::*func)(int), bool *positive, bool *negative) {

  if(!*negative && !*positive && keyPressed) {

    *negative = true;

    //(this->*func)(-1);

  } else if(*negative && !keyPressed) {

    *negative = false;

  }

  //if(*negative) (this->*func)(-1);

}

float Laser::moveX(int steps) {

  float nowX = head.getX();
  float newX = nowX + steps * STEPS_PER_MILLIMETER;

  if(LASER_DEBUG_MOVE) printf("NewX: %f, NowX: %f.\n",newX,nowX);

  if(-SPACE_WIDTH / 2  > newX) newX = -SPACE_WIDTH / 2;
  if(newX > SPACE_WIDTH / 2) newX = SPACE_WIDTH / 2;

  // Also need the angle

  head.move(newX - nowX ,0 ,0);

  return newX - nowX;

}

float Laser::moveY(int steps) {

  float nowY = head.getY();
  float newY = nowY + steps * STEPS_PER_MILLIMETER;

  if(LASER_DEBUG_MOVE) printf("NewY: %f, NowY: %f.\n",newY,nowY);

  if(-SPACE_DEPTH / 2  > newY) newY = -SPACE_DEPTH / 2;
  if(newY > SPACE_DEPTH / 2) newY = SPACE_DEPTH / 2;

  // Also need the angle

  head.move(0, newY - nowY ,0);

  return newY - nowY;

}

float Laser::moveZ(int steps) {

  float nowZ = head.getZ();
  float newZ = nowZ + steps * STEPS_PER_MILLIMETER;

  if(LASER_DEBUG_MOVE) printf("NewZ: %f, NowZ: %f.\n",newZ,nowZ);

  if(-SPACE_HEIGHT / 2  > newZ) newZ = -SPACE_HEIGHT / 2;
  if(newZ > SPACE_HEIGHT / 2) newZ = SPACE_HEIGHT / 2;

  // Also need the angle

  head.move(0, 0, newZ - nowZ);

  return newZ - nowZ;

}

float Laser::rotateA(int steps) {

  head.rotate(steps * STEPS_PER_DEGREE, 1, 0, 0);

}

float Laser::rotateB(int steps) {

  head.rotate(steps * STEPS_PER_DEGREE, 0, 1, 0);

}
