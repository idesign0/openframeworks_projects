#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDistance(5000);
	osc.setup(8000);

	ofBackground(0);
	ofSetFrameRate(60);
	mesh.setMode(OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update(){
	while (osc.hasWaitingMessages()) {
		ofxOscMessage message;
		osc.getNextMessage(message);

		if (message.getAddress() == "/1/amount") {
			uiamount = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/position/1") {
			uipos1 = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/position/2") {
			uipos2 = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/position/3") {
			uipos3 = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/position/4") {
			uipos4 = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/position/5") {
			uipos5 = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/position/6") {
			uipos6 = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/distance") {
			uidistance = message.getArgAsFloat(0);
		}

		if (message.getAddress() == "/1/points") {
			uipoints = message.getArgAsFloat(0);
		}
	}

	ofSeedRandom(30);
	mesh.clear();

	for (int i = 0; i < uiamount; i++)
	{
		ofVec3f position = ofVec3f(
			ofMap(ofNoise(ofRandom(600),ofGetElapsedTimef()*0.006),0,1,uipos1,uipos2), // x cordinate
			ofMap(ofNoise(ofRandom(600), ofGetElapsedTimef()*0.006), 0, 1, uipos3, uipos4), // y cordinate
			ofMap(ofNoise(ofRandom(600), ofGetElapsedTimef()*0.006), 0, 1, uipos5, uipos6 ) // z cordinate
		);

		mesh.addVertex(position);
		mesh.addColor(ofColor(255));

	}

	for (int i = 0; i < mesh.getVertices().size(); i++)
	{
		auto position = mesh.getVertex(i);
		for (int j = 0; j < mesh.getVertices().size(); j++)
		{
			auto jdistance = mesh.getVertex(j);
			auto distance = glm::distance(position, jdistance);
			if (distance<uidistance)
			{
				//mesh.addIndex(i);
				//mesh.addIndex(j);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//cam.begin();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	if (uipoints == 1) {
		for (int i = 0; i < mesh.getVertices().size(); i++)
		{
			ofSetColor(255);
			ofDrawSphere(mesh.getVertex(i), 3);
		}
	}
	mesh.draw();
	//cam.end();

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
