#include "ofMain.h"
#include "settings.h"
#include "LaserCutter.h"

LaserCutter::LaserCutter() {


  plane.set(SPACE_WIDTH, SPACE_DEPTH);
  plane.setPosition(0, 0, 0);
  //plane.rotate(90, 1, 0, 0);
  planeColor = ofColor(200,200,200);

}

void LaserCutter::draw() {

  // Plane

  ofSetColor(planeColor);
  plane.draw();

  // Mirrors

  // Laser Generator

}
