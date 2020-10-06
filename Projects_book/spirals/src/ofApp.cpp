#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofEnableSmoothing();
	ofSetLineWidth(0.5);
	// allocate drawing buffer
	fbo.allocate(ofGetWidth(), ofGetHeight());

	// fill buffer with white color
	fbo.begin();
	ofBackground(0);
	fbo.end();

	//initialize variable
	a = 0;
	b = 0;

	pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
	colorstep = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	fbo.begin();
	for (int i = 0; i < 200; i++)
	{
		draw_line();
	}
	fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);

	fbo.draw(0, 0);
}

void ofApp::draw_line() {
	// change a
	a += b * DEG_TO_RAD;
	// a holds value in radian, b in degree

	//change b
	b = b + 7;

	//Shift pos in direction defined by angle a
	lastpos = pos; // store last pos value
	ofPoint d = ofPoint(2*cos(a), 2*sin(a));
	float len = 15;
	pos += d * len;

	// change color each 100 steps
	if (colorstep%100==0)
	{
		color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	}
	colorstep++;

	// draw line
	ofSetColor(color);
	ofLine(lastpos,pos);
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
