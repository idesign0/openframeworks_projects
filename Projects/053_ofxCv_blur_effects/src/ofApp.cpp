#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.setDeviceID(1);
	camera.setup(640,480);
	imageblur.allocate(camera.getWidth(), camera.getHeight(),OF_IMAGE_COLOR);

	gui.setup();
	gui.add(uiSelectblur.set("Blur", 0, 0, 2));
	gui.add(uiradius.set("Radius", 60, 0, 100));
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();

	if (camera.isFrameNew()) {
		copy(camera, imageblur);
		
		if (uiSelectblur == 0) {
			blur(imageblur, uiradius);
		}
		else if (uiSelectblur == 1) {
			GaussianBlur(imageblur, uiradius);
		}
		else {
			medianBlur(imageblur, uiradius);
		}

		imageblur.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	imageblur.draw(0, 0);
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
