#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255, 255, 255);
	gui.setup();

	gui.add(intslider.setup("Int SLider", 64, 3, 64));
	gui.add(floatslider.setup("Float SLider", 30.0, 0.0, 300.0));
	
	gui.add(toggle.setup("Toggle", false));
	gui.add(button.setup("Button"));
	gui.add(label.setup("Label","This is a Label"));

	gui.add(intfield.setup("Int Field", 100, 0, 100));
	gui.add(floatfield.setup("Float Field", 100.0, 0.0, 100.0));
	gui.add(textfield.setup("Text Field", "text"));

	gui.add(Vec2Slider.setup("String Vec2 Slider", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	gui.add(Vec3Slider.setup("String Vec3 Slider", ofVec3f(100, 150, 90), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));
	gui.add(Vec4Slider.setup("String Vec4 Slider",ofVec4f(0,0,0,0), ofVec4f(0,0,0,0), ofVec4f(255, 255, 255, 255)));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (button) {
		ofSetColor(ofRandom(Vec3Slider->x), ofRandom(Vec3Slider->y), ofRandom(Vec3Slider->z));
	}
	ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 128);
	ofSetCircleResolution(intslider);
	ofSetColor(Vec4Slider->x, Vec4Slider->y, Vec4Slider->z, Vec4Slider->w);
	ofDrawCircle(Vec2Slider->x, Vec2Slider->y, 128);

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
