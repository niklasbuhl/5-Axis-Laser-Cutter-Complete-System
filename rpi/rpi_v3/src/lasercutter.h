#ifndef LASERCUTTER_H
#define LASERCUTTER_H

// General Geometrics

#include "geometrics.h"
#include "ofColor.h"

// Lasercutter Elements

struct DeathStar {

  ofPoint center;
  int radius;

  ofColor color;

};

struct LaserRay {

  ofPoint start;
  ofPoint end;

  ofColor color;

};

struct Laser {

  ofPoint start;
  ofPoint focus;
  int length;
  ofVec3f end;

  ofColor color;

};

struct Mirror {

  ofPoint center; // Point of impact
  ofVec3f orientation; // XYZ is point of impact.
  int radius;
  int thickness;

  // Color

  ofColor color;

};

struct Table {

  ofPoint center;

  int length;
  int width;
  int height;

  ofColor frameColor;
  ofColor planeColor;

};

struct Actuator {

  ofPoint start;
  ofPoint end;

  // Color

};

struct Head {

  ofPoint center;
  ofVec3f orientation;

  int length;
  int width;
  int height;

  ofColor frameColor;

};

// Element

struct Element {

  Vertex center;

  int length;
  int width;
  int height;

  ofColor color;

};

// Laser Cutter

class LaserCutter {

public:

  LaserCutter();


  void draw();
  float getScale();

private:

  void drawOrientation();
  void drawDeathStar();
  void drawHead();
  void drawTable();
  void drawMirror(Mirror mirror);
  void drawLaserRay(LaserRay laser);
  void drawLaser();
  void drawActuator(Actuator actuator);
  void drawElement(Element element);

protected:

  float scale = 0.1;
  int realY = -1;

  Vertex origin;
  Orientation o;

  // Lasers

  DeathStar deathstar;
  LaserRay laserInit;
  LaserRay laserY;
  LaserRay laserX;
  Laser laserZAB;

  // Head & Mirrors

  Head head;
  Mirror mirrorInit;
  Mirror mirrorXY;
  Mirror mirrorZAB;

  // Setup

  Table table;
  Actuator actuatorX;
  Actuator actuatorY;
  Actuator actuatorZ;

  // Element

};

#endif
