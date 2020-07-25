#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sound.load("drum.mp3");
	sound.play();
	sound.setLoop(true);

	gui.setup();
	gui.add(volume.set("Volume", 0.5, 0.0, 1.0));
	gui.add(decay.set("Decay", 0.5, 0.0, 1.0));
	gui.add(color.setup("Color", ofColor(155, 155, 155), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(background.setup("Background", ofColor(155,155,155), ofColor(0, 0, 0), ofColor(255, 255, 255)));

	fft = new float[128];
	for(int i=0;i<128;i++){
		fft[i] = 0;
	}

	bands = 64;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSoundUpdate();
	ofSetBackgroundColor(background);

	sound.setVolume(volume);
	soundspectrum = ofSoundGetSpectrum(bands);

	for (int i = 0; i < bands; i++) {
		fft[i] *= decay;
		if (fft[i] < soundspectrum[i]) {
			fft[i] = soundspectrum[i];
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i=0;i<bands;i++){
		//ofDrawRectangle(ofGetWidth() / 2, 128, fft[i] * 100, 128)

		ofSetColor(color);

		ofDrawCircle(200, ofGetHeight() / 2, fft[i] * 100);
		ofDrawCircle(ofGetWidth()-200, ofGetHeight() / 2, fft[i] * 100);

		ofDrawCircle(ofGetWidth() / 2, 200, fft[i] * 100);
		ofDrawCircle(ofGetWidth()/2, ofGetHeight()-200, fft[i] * 100);

		ofDrawCircle(ofGetWidth()/2, ofGetHeight() / 2, fft[i] * 100);
	}
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
