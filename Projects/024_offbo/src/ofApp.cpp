#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	image.load("s4.gif");
	ofSetBackgroundColor(255);
	slidergroup.setName("Color Group");
	slidergroup.add(colors.set("Color Panel", ofVec3f(200, 200, 200), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));
	slidergroup.add(radius.set("Radius", 20, 0, 100));
	fbo.allocate(1024, 768);
	fbo.begin();
	ofClear(255);
	fbo.end();

	//gui.setup(slidergroup);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//gui.draw();
	fbo.draw(0,0);	
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
	fbo.begin();
	//ofSetColor(ofRandom(colors->x), ofRandom(colors->y), ofRandom(colors->z));
	//ofDrawCircle(x,y, radius);
	image.draw(x,y);
	fbo.end();
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
