#include "ofApp.h"
#include "ui.h"
#include "laserengine.h" // Engine
#include "global.h"

#include <cstdlib>

//--------------------------------------------------------------
void ofApp::setup(){

  ofBackground(255, 255, 255);

  ofEnableLighting();
  light.enable();

  camera.setDistance(100);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  ofEnableDepthTest();

  light.setPosition(0,0,1000);

  camera.begin();

  //ofDrawAxis(100);

  ofRotateX(ofRadToDeg(5.5));
  ofRotateZ(ofRadToDeg(0.4));

  laserengine.draw();

  camera.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
