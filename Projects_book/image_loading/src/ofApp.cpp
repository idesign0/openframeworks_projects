#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	image.load("sunflower.jpg");
	//image.saveImage("test.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	for (int i = 0; i < 100; i++)
	{
		ofPushMatrix();
		// translate system cordinate to screen center
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

		//rotate coordinate system on i * 15 degrees
		ofRotate(i * 15);

		//go right on 50+i*10 pixels
		ofTranslate(50 + i * 10, 0);

		//scale the coordinate system for decresing drawing 
		//image size
		float sc1 = 1.0 - i * 0.8 / 20.0;
		ofScale(sc1, sc1);

		image.draw(-100, -100);
		ofPopMatrix();
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
