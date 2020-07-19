#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	Slidergroup.setName("Sliders");
	Slidergroup.add(intslider.set("Int Slider", 50, 0, 64));
	Slidergroup.add(floatslider.set("Float Slider", 3.0, 0, 64.0));

	circle.setup();
	maingroup.add(circle.params);
	maingroup.add(Slidergroup);
	gui.setup(maingroup);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetCircleResolution(intslider);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(circle.colors->x, circle.colors->y, circle.colors->z);
	ofDrawCircle(circle.x, circle.y, floatslider);
	gui.draw();
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
