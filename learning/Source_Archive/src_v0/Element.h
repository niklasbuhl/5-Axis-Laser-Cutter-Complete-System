#ifndef ELEMENT_H
#define ELEMENT_H

#include "ofMain.h"
#include "settings.h"
#include "Element.h"

class Element {

public:

  Element();

  void draw();

  ofVec3f pointOfEntry();
  ofVec3f pointOfExit();

  float cuttingLength();

  ofVec3f cuttingVector();

private:

  ofBoxPrimitive element;

};

#endif /* end of include guard: ELEMENT_H */
