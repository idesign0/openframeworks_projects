#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDistance(100);
	osc.setup(8000);
	ofBackground(0);
	ofSetFrameRate(60);

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			mesh.addVertex(ofPoint(x - size / 2, y - size / 2));
		}
	}

	for (int x = 0; x < size-1; x++)
	{
		for (int y = 0; y < size-1; y++)
		{
			mesh.addIndex(x + y * size);
			mesh.addIndex((x + 1) + y * size);
			mesh.addIndex(x + (y+1) * size);
			mesh.addIndex((x + 1) + y * size);
			mesh.addIndex((x + 1) + (y+1) * size);
			mesh.addIndex(x + (y + 1) * size);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	while (osc.hasWaitingMessages()) {
		ofxOscMessage message;
		osc.getNextMessage(message);

		if (message.getAddress()=="/1/amount")
		{
			uiAmount = message.getArgAsFloat(0);
		}
	}

	int count = 0;

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			ofVec3f position = mesh.getVertex(count);
			position.z = ofMap(ofNoise(count, ofGetElapsedTimef()), 0, 1, 0, uiAmount);
			mesh.setVertex(count, position);
			count++;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushMatrix();
	cam.begin();
	ofSetColor(255);
	mesh.drawWireframe();
	cam.end();
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
