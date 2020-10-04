#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	color = ofColor(0.0, 128.0, 255.0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	for (int i = 0; i < 256; i++)
	{
		ofColor color = ofColor::red;
		color.setBrightness(i);
		ofSetColor(color);
		ofLine(i, 0, i, 50);
	}

	for (int i = 0; i < 256; i++)
	{
		ofColor color = ofColor::red;
		color.setSaturation(i);
		ofSetColor(color);
		ofLine(i, 80, i, 130);
	}

	for (int i = 0; i < 256; i++)
	{
		ofColor color = ofColor::red;
		color.setHue(i);
		ofSetColor(color);
		ofLine(i, 160, i, 210);
	}
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
