#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  ofBackground(255);

  ofEnableLighting();
  light.enable();

  camera.setDistance(1000);

}

//--------------------------------------------------------------
void ofApp::update(){

  laser.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

  ofEnableDepthTest();

  light.setPosition(0,0,1000);

  camera.begin();

  // Draw 3D

    lasercutter.draw();
    laser.draw();

  camera.end();

  ofDisableDepthTest();

  // Draw 2D



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  //printf("Key: %i\n", key);

  keys[key] = true;

  laser.manualcontrol(key, keys[key]);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

  keys[key] = false;

  laser.manualcontrol(key, keys[key]);

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
