#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	record.setup(true, false);
	record.setWidth(ofGetWidth());
	record.setHeight(ofGetHeight());
	//record.setVideoCodec("mpeg4");

	record.setFFmpegPath(ofToDataPath("ffmpeg.exe"));
	record.setFps(60);
	
	ofSetLineWidth(3);	
	ofSetCircleResolution(128);

	gui.setup();
	gui.add(uiAmount.set("Amount", 1, 1, 30));
	gui.add(uiPower.set("Power", ofVec3f(0), ofVec3f(0), ofVec3f(3.0)));
	gui.add(uiRadius.set("Radius", 0, 0, 60.0));
	gui.add(uiPosition.set("Position", ofVec2f(0),
							ofVec2f(-ofGetWidth(), -ofGetHeight()), 
							ofVec2f(ofGetWidth(), ofGetHeight())));


}

//--------------------------------------------------------------
void ofApp::update(){
	image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	pixels = image.getPixels();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	if (!record.isPaused()) {
		if (brecording) {
			
			ofPushMatrix();
			cam.begin();
			ofTranslate(uiPosition->x, uiPosition->y);
			float radius = uiRadius;
			for (int i = 0; i < uiAmount; i++)
			{
				float noisex = ofNoise((ofGetElapsedTimef() + i)*uiPower->x);
				float noisey = ofNoise((ofGetElapsedTimef() + i)*uiPower->y);
				float noiseZ = ofNoise((ofGetElapsedTimef() + i)*uiPower->z);

				float x = ofGetWidth() / 2 * noisex;
				float y = ofGetHeight() / 2 * noisey;
				float z = ofGetHeight() / 2 * noiseZ;

				ofNoFill();
				ofDrawCircle(x, y, z, radius);

				record.addFrame(pixels);
				
				radius += i;
			}
			cam.end();
			ofPopMatrix();
		}

	}
	if (bHide) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'r':
		brecording = !brecording;
		if (record.isRecording())
		{
			record.stop();
		}
		else
		{	
			string filename = ofToString(ofGetElapsedTimef()) + ".mp4";
			record.setOutputPath(ofToDataPath(filename, true));
			record.startCustomRecord();
		}
		break;
	case 'p':
		if (record.isPaused()) {
			record.setPaused(false);
		}
		else {
			record.setPaused(true);
		}
		break;
	case 'h':
		bHide = !bHide;
		break;

	default:
		break;
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
