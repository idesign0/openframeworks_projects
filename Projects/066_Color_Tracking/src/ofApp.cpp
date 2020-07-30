#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.setDeviceID(1);
	camera.setup(640, 480);

	contour.setMinArea(30);
	contour.setMinArea(130);
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();

	if (camera.isFrameNew()) {
		contour.setTargetColor(color);
		contour.setThreshold(30);
		contour.findContours(camera);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	camera.draw(0, 0);
	contour.draw();
	
	ofFill();
	ofSetColor(color);
	ofDrawRectangle(camera.getWidth(), 0, 128, 128);

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
	color = camera.getPixels().getColor(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	color = camera.getPixels().getColor(x, y);
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
