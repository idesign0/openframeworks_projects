#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetPolyMode(OF_POLY_WINDING_POSITIVE);
	gui.setup();
	gui.add(uimode.set("Mode", 0, 0, 3));
	gui.add(uiPositionX.set("X", ofVec4f(0), ofVec4f(0), ofVec4f(ofGetWidth())));
	gui.add(uiPositionY.set("Y",ofVec4f(0), ofVec4f(0), ofVec4f(ofGetHeight())));
}

//--------------------------------------------------------------
void ofApp::update(){
	if (uimode == 0) {
		ofSetPolyMode(OF_POLY_WINDING_POSITIVE);
	}
	else if (uimode==1)
	{
		ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	}
	else if (uimode == 2)
	{
		ofSetPolyMode(OF_POLY_WINDING_ODD);
	}
	else if (uimode == 3)
	{
		ofSetPolyMode(OF_POLY_WINDING_ABS_GEQ_TWO);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBeginShape();
	
	ofVertex(uiPositionX->x, uiPositionY->x);
	ofVertex(uiPositionX->y, uiPositionY->y);
	ofVertex(uiPositionX->z, uiPositionY->z);
	ofVertex(uiPositionX->w, uiPositionY->w); 

	ofEndShape();

	gui.draw();
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
