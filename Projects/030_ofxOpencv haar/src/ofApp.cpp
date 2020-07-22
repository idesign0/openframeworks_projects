#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camera.listDevices();
	camera.setDeviceID(1);
	camera.getPixelsRef().mirror(false,true);

	camera.setup(640, 480);
		
	color.allocate(camera.getWidth(), camera.getHeight());

	gray.allocate(camera.getWidth(), camera.getHeight());
	haar.setScaleHaar(2);
	haar.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
		camera.update();
	if (camera.isFrameNew()) {
		color.setFromPixels(camera.getPixels());
		gray = color;
	}

	haar.findHaarObjects(gray);
}

//--------------------------------------------------------------
void ofApp::draw(){
	color.draw(0, 0);
	haar.draw(0,0);
	for (int i = 0; i < haar.blobs.size(); i++) {
		haar.draw(0, 0);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		image.grabScreen(0,0,camera.getWidth(),camera.getHeight());
		string filename = "Screenshot_" + ofToString(count, 3, '0') + ".png";
		count++;
		image.save(filename);
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
