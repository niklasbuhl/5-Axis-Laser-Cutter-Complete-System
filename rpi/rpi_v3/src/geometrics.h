#pragma once

#include "ofPoint.h"

struct Vertex { // ofPoint

  float x; // X-axis position
  float y; // Y-axis position
  float z; // Z-axis position

  ofPoint ofP;

};

struct Angle {

  float a; // Radians around X-axis
  float b; // Radians around Y-axis

  ofVec3f v; // Unit angle vector

};

struct Vector {

  Vertex xyz; // Center of origin

  //

  Angle angle; // Unit angle

  int l; // Length

  //

  ofVec3f ofV; // Vector coordinates

};

struct Orientation {

  Vertex origin;
  ofVec3f vec;

};
