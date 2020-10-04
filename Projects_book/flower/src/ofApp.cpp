#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){

	float time = ofGetElapsedTimef()*3.0;
	float value1 = ofMap(sin(time), -1, 1, 0.8, 1);
	float value2 = ofMap(sin(time), -1, 1, 1, 0.8);

	stem[0] = ofPoint(500, 100);
	stem[1] = ofPoint(500, 270);
	stem[2] = ofPoint(500, 300);
	stem[3] = ofPoint(500, 400);

	leftleaf = ofPoint(400, 220*value1);
	rightleaf = ofPoint(600, 220*value2);

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(245,91,91);
	ofSetColor(255,255,0);
	
	ofCircle(stem[0], 40);
	ofLine(stem[0], stem[3]);
	ofTriangle(stem[1], stem[2], leftleaf);
	ofTriangle(stem[1], stem[2], rightleaf);
	


	ofPushMatrix();
	ofTranslate(stem[0]);

	float angle = ofGetElapsedTimef() * 30;
	ofRotate(angle);

	int petals = 30;
	for (int i = 0; i < petals; i++)
	{
		ofRotate(360 / petals);
		ofPoint p1(0, 20);
		ofPoint p2(80, 0);
		ofTriangle(p1, -p1, p2);

	}
	for (int i = 0; i < petals; i++)
	{
		ofNoFill();
		ofSetColor(32);
		ofRotate(360 / petals);
		ofPoint p1(0, 20);
		ofPoint p2(80, 0);
		ofTriangle(p1, -p1, p2);
		ofTriangle(p1 + (1, 1), -p1 - (1, 1), p2 + (1, 1));
		ofFill();
	}
	

	ofPopMatrix();
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
