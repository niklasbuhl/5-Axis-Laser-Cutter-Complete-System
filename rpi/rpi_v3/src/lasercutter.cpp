#ifndef LASERCUTTER_CPP
#define LASERCUTTER_CPP

#include "lasercutter.h"
#include "ofApp.h"
#include "geometrics.h"
#include "lasercutter_dimensions.h"
#include "lasercutter_colors.h"
#include "global.h"

LaserCutter::LaserCutter() {

  // Init Deathstar

  if(DEBUGMODE) {cout << "Initializing Deathstar." << "\n\r";};

  deathstar.center.x = origin.x + DEATHSTAR_X_OFFSET;
  deathstar.center.y = origin.y + DEATHSTAR_Y_OFFSET;
  deathstar.center.z = origin.z + DEATHSTAR_Z_OFFSET;
  deathstar.radius = DEATHSTAR_RADIUS;
  deathstar.color = deathstarColor;

  if(DEBUGMODE) {cout << "Initializing Head." << "\n\r";};

  head.center.x = origin.x;
  head.center.y = origin.y;
  head.center.z = origin.z;
  head.length = HEAD_LENGTH;
  head.width = HEAD_WIDTH;
  head.height = HEAD_HEIGHT;
  head.frameColor = metalColor;

  if(DEBUGMODE) {cout << "Initializing Table." << "\n\r";};

  table.center.x = origin.x;
  table.center.y = origin.y;
  table.center.z = origin.z + TABLE_MIN_OFFSET;
  table.length = TABLE_LENGTH;
  table.width = TABLE_WIDTH;
  table.height = TABLE_HEIGHT;
  table.planeColor = planeColor;

}

void LaserCutter::drawOrientation() {

  ofSetLineWidth(4);

  ofSetColor(255,0,0); // Red X

  ofLine(origin.x,origin.y,origin.z,origin.x+400,origin.y,origin.z);

  ofSetColor(0,255,0); // Green Y

  ofLine(origin.x,origin.y,origin.z,origin.x,realY*(origin.y+400),origin.z);

  ofSetColor(0,0,255); // Blue Z

  ofLine(origin.x,origin.y,origin.z,origin.x,origin.y,origin.z+400);


}

void LaserCutter::drawDeathStar() {

  ofSetColor(deathstar.color);

  ofDrawIcoSphere(
    scale * deathstar.center.x,
    realY * scale * deathstar.center.y,
    scale * deathstar.center.z,
    scale * deathstar.radius
  );

}

void LaserCutter::drawHead() {

  ofSetColor(head.frameColor);

  ofDrawBox(
    scale * head.center.x,
    realY * scale * head.center.y,
    scale * head.center.z,
    scale * head.length,
    scale * head.width,
    scale * head.height
  );

}

void LaserCutter::drawTable() {

  ofSetColor(table.planeColor);

  ofDrawBox(
    scale * table.center.x,
    realY * scale * table.center.y,
    scale * table.center.z,
    scale * table.length,
    scale * table.width,
    scale * table.height
  );

}

void LaserCutter::drawMirror(Mirror mirror) {

  ofSetColor(mirror.color);

}

void LaserCutter::drawLaserRay(LaserRay laser) {



}
void LaserCutter::drawLaser() {



}
void LaserCutter::drawActuator(Actuator actuator) {



}
void LaserCutter::drawElement(Element element) {


  
}

void LaserCutter::draw() {


  //drawOrientation();
  drawDeathStar();
  drawHead();
  drawTable();

}

float LaserCutter::getScale() {

  return scale;

}

#endif
