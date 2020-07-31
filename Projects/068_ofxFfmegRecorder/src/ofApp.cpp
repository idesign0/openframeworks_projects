#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
	
	record.setup(true, false);
	record.setWidth(ofGetWidth());
	record.setHeight(ofGetHeight());
	record.setFFmpegPath(ofToDataPath("ffmpeg.exe"));
	record.setFps(60);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!record.isPaused()) {
		if (brecording)
		{
			fbo.readToPixels(pixels);
			if (pixels.getWidth()>0 && pixels.getHeight() > 0)
			{	
				record.addFrame(pixels);
			}
		}	}
	fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'r' :
		brecording = !brecording;
		if (record.isRecording())
		{
			record.stop();
		}
		else
		{
			record.setOutputPath(ofToDataPath("1.mp4", false));
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
	fbo.begin();
	ofDrawCircle(x, y, 3);
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
