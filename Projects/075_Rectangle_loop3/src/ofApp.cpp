#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(uiWidth.set("Width", 0, 0, 64));
	gui.add(uiheight.set("Height", 0, 0, 64));
	gui.add(uiXpower.set("x power", 0, 0, 32));
	gui.add(uiYpower.set("y power", 0, 0, 32));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofNoFill();
	ofSetLineWidth(2);

	for (int x = 0; x < 32; x++)
	{
		for (int y = 0; y < 32; y++)
		{
			ofDrawRectangle(x * 64, y * 64, sin(x + ofGetElapsedTimef()) * uiXpower, uiheight);
			ofDrawRectangle(x * 64, y * 64, uiWidth, sin(y + ofGetElapsedTimef()) * uiYpower );
		}
	}

	if (bhide) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	bhide = !bhide;
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
