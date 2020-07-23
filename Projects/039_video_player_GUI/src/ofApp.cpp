#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.load("ocean2.mp4");
	video.play();

	control.add(playpause.set("Play/Pause", false));
	control.add(volume.set("Volume", 0.5, 0, 1));
	control.add(scrub.set("Scrub", 0.0, 0.0, video.getTotalNumFrames()));

	gui.setup(control);
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	video.setVolume(volume);

	if (playpause) {
		video.setPaused(false);
	}
	else {
		video.setPaused(true);
	} 

	if (video.isPaused()) {
		video.setFrame(scrub);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	video.draw(0, 0,640,480);
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
