#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255);
	sound.load("drumloop.wav");
	sound.load("drumloop.wav");
	sound.play();
	sound.setLoop(true);

	fft = new float[ofGetWidth()- 200];

	for (int i = 0; i < ofGetWidth() - 200; i++){
		fft[i] = 0;
	} 

	bands = ofGetWidth() - 200;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSoundUpdate();
	soundspectrum = ofSoundGetSpectrum(bands);

	for (int i = 0; i < bands; i++) {
		fft[i] *= 0.9;
		if (fft[i] < soundspectrum[i]) {
			fft[i] = soundspectrum[i];
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(100,100);
	for (int i = 0; i < bands; i+=25) {
		ofSetColor(ofRandom(0,50));
		ofPolyline polyline;
		for (int j = 0; j < bands; j++) {
			polyline.addVertex(j, i - fft[j] * 100);
		}
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
