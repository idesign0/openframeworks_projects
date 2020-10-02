#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//set screenframe rate
	ofSetFrameRate(60);

	//set initial values
	centre = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
	pos = ofPoint(600,100);
	veclocity = ofPoint(100, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	float dt = 1.0 / 60.0; // time step
	float mass = 3; // mass of the ball
	float rubberlen = 600.0; // segments length
	float k = 0.5; // segments stiffness
	ofPoint g(0.0, 9.8); // gravity force

	//compute huke's law
	ofPoint delta = centre - pos;
	float length = delta.length(); // vector's length
	float hookevalue = k * (length - rubberlen);
	delta.normalize(); // normalize vectors length
	ofPoint hookeForce = delta * (-hookevalue);

	//update velocity and position
	ofPoint force = hookeForce + g; // resulted force
	ofPoint a = force / mass;
	veclocity += a * dt; // euler method
	pos += veclocity * dt; //euler method
}

//--------------------------------------------------------------
void ofApp::draw(){
	//set background
	ofBackground(255);

	// draw rubber as point line 
	ofSetColor(0, 0, 255);
	ofLine(centre.x, centre.y, pos.x, pos.y); // draw line

	//draw ball as red
	ofSetColor(255, 0, 0);
	ofFill();
	ofCircle(pos.x, pos.y, 20);
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
