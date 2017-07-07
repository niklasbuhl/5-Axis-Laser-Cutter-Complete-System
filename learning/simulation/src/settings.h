#ifndef SETTINGS_H
#define SETTINGS_H

#include "ofMain.h"

// All dimensions are in millimeters

#define HEAD_START_X 0
#define HEAD_START_Y 0
#define HEAD_START_Z 100

// Cutting Space
#define SPACE_WIDTH 1000 // X
#define SPACE_DEPTH 1000 // Y
#define SPACE_HEIGHT 400 // Z

#define LASER_ANGLE 45 // Max angle

#define ELEMENT_HEIGHT 20
#define ELEMENT_WIDTH 600
#define ELEMENT_DEPTH 400

#define STEPS_PER_MILLIMETER 1 // This must be calculated.
#define STEPS_PER_DEGREE 1 // Angle Celcius (Maybe go to radians).

// Debugging

#define DEBUG_LASER_UPDATE false
#define LASER_DEBUG_MOVE false

#endif /* end of include guard: SETTINGS_H */
