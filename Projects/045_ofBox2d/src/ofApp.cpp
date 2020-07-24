#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	box2d.init();
	box2d.setGravity(0, 30);
	box2d.registerGrabbing();

	polyshape.begin();
	polyshape.addVertex(0, 0);
	polyshape.addVertex(64, 0);
	polyshape.addVertex(64, 64);
	polyshape.end();
}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	for (auto circle:circles) {
		circle->draw();
	}

	for (auto rect : rects) {
		rect->draw();
	}

	for (auto polygon : polygons) {
		polygon->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		ofSetFullscreen(true);
	}
	if (key == OF_KEY_ESC) {
		ofSetFullscreen(false);
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
//	if (button == 0) {
//		box2d.createBounds(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
//		auto circle = make_shared<ofxBox2dCircle>();
//		circle->setPhysics(3.0, 0.8, 1);
//		circle->setup(box2d.getWorld(), mouseX, mouseY, 32); 
//		circles.push_back(circle);
//	}

//	if (button == 0) {
//		box2d.createBounds(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
//		auto rect = make_shared<ofxBox2dRect>();
//		rect->setPhysics(3.0, 0.8, 1);
//		rect->setup(box2d.getWorld(), mouseX, mouseY, 32,32);
//		rects.push_back(rect);
//	}

	if (button == 0) {
		box2d.createBounds(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
		auto polygon = make_shared<ofxBox2dPolygon>();
		polygon->addVertices(polyshape.getVertices());
		polygon->setPhysics(3.0, 0.5, 1.0);
		polygon->create(box2d.getWorld());
		polygons.push_back(polygon);
	}
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
