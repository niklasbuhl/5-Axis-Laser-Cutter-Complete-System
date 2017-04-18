#pragma once

#include "lasercutter.h"

// Laser Cutting Modes

// Laser Cutting Plane

// Activities

#define MOVE 0
#define CUT 1
#define RASTERIZE 2

struct Activity {

  int activity; // 0 is move, 1 is cutting, 2 is rasterizing
  int *actPtr;

};

struct Move { // Moving

  Vector start;
  Vector end;

};

struct Cut { // Cutting

  Vector start;
  Vector end;

};

struct CuttingPlane {

  Laser start;
  Laser end;

  Vertex startPoEn;
  Vertex startPoEx;
  Vertex endPoEn;
  Vertex endPoEx;

  // Color

};

//Rasterize - to be continued...

struct Rasterize { // Rasterizing

};

struct RasterizePlane {

};

// Laser Cutting Path Apparance

class LaserPath {

public:

  LaserPath();
  void draw();

private:

protected:

};
