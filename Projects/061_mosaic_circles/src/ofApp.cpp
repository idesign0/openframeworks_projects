#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.setDeviceID(1);
	camera.setup(640*2,480*2);
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < camera.getWidth(); i+=32)
	{
		for (int j = 0; j < camera.getHeight(); j+=32)
		{
			ofColor color = camera.getPixels().getColor(i, j);
			ofSetColor(color);
			float brightness = color.getBrightness();
			float radius = ofMap(brightness, 0, 255, 0, 16);
			
			ofDrawCircle(i, j, radius);
		}
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
