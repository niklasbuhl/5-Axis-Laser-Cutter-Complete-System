#ifndef LASERENGINE_H
#define LASERENGINE_H

#include "lasercutter.h" // Cutter Visual
#include "laserpath.h" // Cutting Visual

class LaserEngine {

public:

  LaserEngine();

  void draw();

  LaserCutter cutter;
  LaserPath path;

private:

protected:

};

#endif
