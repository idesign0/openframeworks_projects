#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDeviceID(1);
	cam.setup(640, 480);

	imitate(pxprevious, cam);
	imitate(imgdifference, cam);

}

//--------------------------------------------------------------
void ofApp::update(){
	cam.update();

	if (cam.isFrameNew()) {
		absdiff(cam, pxprevious, imgdifference);
		imgdifference.update();
		copy(cam, pxprevious);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//imgdifference.draw(0, 0 ,640,480);
	for (int i = 0; i < cam.getHeight(); i+=8) {
		ofPolyline polyline;
		for (int j = 0; j < cam.getWidth(); j++) {
			ofColor color = imgdifference.getPixels().getColor(j, i);
			int brightness = color.getBrightness();
			polyline.addVertex(j, i + ofMap(brightness, 0, 255, 0, -64));
		}
		polyline=polyline.getSmoothed(5);
		polyline.draw();
	}
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
