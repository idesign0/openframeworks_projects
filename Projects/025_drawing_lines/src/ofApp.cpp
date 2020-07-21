#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSetBackgroundColor(255);
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//	if (npts > 1) {
	//	for (int i = 0; i < npts - 1; i++) {
	//		ofDrawLine(pts[i].x, pts[i].y, pts[i + 1].x, pts[i + 1].y);
//		}
//	}
	ofSetColor(ofRandom(155,255), ofRandom(155, 255),ofRandom(155, 255));
	polyline.draw();
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
	if (npts < MAXPOINTS) {
		pts[npts].x = x;
		pts[npts].y = y;
		npts++;
	}

	polyline.addVertex(ofPoint(x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	polyline.addVertex(ofPoint(x, y));

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	npts = 0;
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
