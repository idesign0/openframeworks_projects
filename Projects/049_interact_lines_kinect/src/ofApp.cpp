#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.setDeviceID(1); 
	camera.setup(640,480);

}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//camera.draw(0,0,640,480);

	for (int i = 0; i < 640 ;i+=16) {
		for (int j = 0; j <480; j += 16) {
			ofColor color = camera.getPixels().getColor(i,j);
			int brightness = color.getBrightness();
			ofPushMatrix();
			ofTranslate(i, j);
			ofRotateZDeg(ofMap(brightness,0,255,0,360));
			ofDrawLine(0 - 8, 0, 0 + 8, 0);
			ofSetLineWidth(ofMap(brightness, 0, 255, 5, 0));
			ofPopMatrix();
		}
	}
}

void ofApp::exit() {
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
