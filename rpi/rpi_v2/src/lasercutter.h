#ifndef LASER_H
#define LASER_H

struct XYZ {

  // X-coordinate
  float x;

  // Y-coordinate
  float y;

  // Z-coordinate
  float z;

}

struct Angle {

  // Angle between
  float a;

  // Angle between
  float b;

}

struct LaserVector {

  XYZ pos;
  float a;
  float b;

};

struct MoveVector {

  // XYZ Starting Point
  XYZ start;

  // XYZ Ending Point
  XYZ end;

};

struct LaserMirror {

  XYZ center;
  float angleXY;
  float angleZ;

  int radius;

  // color

};

struct LaserRay {
  float startX;
  float startY;
  float startZ;
  float endX;
  float endY;
  float endZ;

  // Color

};

struct Table {

  float centerX;
  float centerY;
  float centerZ;

  float length; // Z
  float width; // Y

  // Color

};

struct LaserGenerator {

  // Cylinder

};

struct LaserHead {

  float posX;
  float posY;
  float posZ;

  float length; // X
  float width; // Y
  float height; // Z

  // Color

};

struct Element {

  // Element Center Position
  float posX;
  float posY;
  float posZ;

  // Element Dimensions
  float lenght; // X
  float width; // Y
  float height; // Z

  // Color
}

struct Actuator {

  // Actuator Start Positions
  float startX;
  float startY;
  float startZ;

  // Actuator Start Positions
  float endX;
  float endY;
  float endZ;

  // Actuator Appearance

  // Color

}

struct LaserCut {



}

struct LaserMove {

  // Point of Entry Start Vector
  float poEnStartX;
  float poEnStartY;
  float poEnStartZ;
  float poEnStartA;
  float poEnStartB;

  // Point of Entry End Vector
  float poEnEndX;
  float poEnEndY;
  float poEnEndZ;
  float poEnEndA;
  float poEnEndB;

}

class LaserCutter {

  // Laser

  LaserGenerator deathStar;
  LaserRay laserInit;
  LaserRay laserY;
  LaserRay laserX;
  LaserRay laserZAB;

  // Mirror

  LaserMirror mirrorInit;
  LaserMirror mirrorXY;
  LaserMirror mirrorZAB;

  // Actuators

  Actuator actuatorX;
  Actuator actuatorY;
  Actuator actuatorZ;

  // Physical

  Table table;

  // Element

  Element element;

};

class LaserCuttingPath {

  LaserVector laserStart;
  LaserVector laserEnd;

};

#endif
