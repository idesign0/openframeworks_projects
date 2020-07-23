#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	speedx.resize(1);
	speedy.resize(1);
	speedz.resize(1);

	for (int i = 0; i < speedz.size(); i++) {
		speedx[i] = ofRandom(0.5, 1.5);
		speedy[i] = ofRandom(0.5, 1);
		speedz[i] = ofRandom(0.5, 1.5);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.begin();
	float time = ofGetElapsedTimef();
	ofNoFill();
	ofDrawBox(ofGetHeight(), ofGetHeight(), ofGetHeight());

	for (int i = 0; i < speedx.size(); i++){
		//ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
		
		float x = ofGetHeight() * ofNoise(time * speedx[i]);
		float y = ofGetHeight() * ofNoise(time * speedy[i]);
		float z = ofGetHeight() * ofNoise(time * speedz[i]);
		
		ofTranslate(-ofGetHeight() / 2, -ofGetHeight() / 2, -ofGetHeight() / 2);
		ofDrawSphere(x, y, z, 32);
		ofTranslate(ofGetHeight() / 2, ofGetHeight() / 2, ofGetHeight() / 2);
	}

	camera.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case OF_KEY_UP : 
		 speedx.push_back(ofRandom(0.5, 1));
		 speedy.push_back(ofRandom(0.5, 1.5));
		 speedz.push_back(ofRandom(0.5, 1));
			break;
	case OF_KEY_DOWN: 
		if (!(speedx.size() <= 0)) {
			speedx.pop_back();
			speedy.pop_back();
			speedz.pop_back();
		}
		break;

	default:
		break;
	}
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
