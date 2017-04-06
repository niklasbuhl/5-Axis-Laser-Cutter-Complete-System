#ifndef LASER_H
#define LASER_H

struct LaserMirror {

  float centerX;
  float centerY;
  float centerZ;
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

  float length; // X
  float width; // Y
  float height; // Z

  // Color

};

struct Element {

  float posX;
  float posY;
  float posZ;

  float lenght; // X
  float width; // Y
  float height; // Z

  // Color
}

class LaserCutter {

  LaserGenerator deathStar;
  LaserRay laserInit;
  LaserRay laserY;
  LaserRay laserX;
  LaserRay laserZAB;


  laser




};

#endif
