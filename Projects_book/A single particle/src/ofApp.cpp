#include "ofApp.h"
#include "parameter.h"
//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFullscreen(false);
	ofSetFrameRate(60);

	int w = ofGetWidth();
	int h = ofGetHeight();

	fbo.allocate(w, h, GL_RGB32F_ARB);

	fbo.begin();
	ofBackground(0);
	fbo.end();

	params.setup();
	history = 0.90;

	time0 = ofGetElapsedTimef();

	boarnRate = 1500;
	boarnCount = 0;


}

//--------------------------------------------------------------
void ofApp::update(){
	float time = ofGetElapsedTimef();
	float dt = ofClamp(time - time0, 0, 0.1);
	time0 = time;
	
	//delete inactive particles
	int i = 0;
	while(i<p.size()){
		if (!p[i].live) {
			p.erase(p.begin() + i);
			//cout << "clear" << endl;
		}
		else {
			i++;
		}
	}
	//born new particle
	boarnCount += dt * boarnRate; // update boarn count value
	//cout << boarnCount << endl;
	if (boarnCount >= 1) {
		int boarN = int(boarnCount); // how many boarn
		boarnCount -= boarN; // correct boarn count
		for (int i = 0; i < boarN; i++) {
			Particle newp;
			newp.setup(); // start new particle
			p.push_back(newp); // add this particlew to array
		}
	}

	for (int i = 0; i < p.size(); i++) {
		p[i].update(dt);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	//1.drawing to buffer
	fbo.begin();
	// draw a semitransperant white rectangle
	// to sightly clearing buffer
	
	ofEnableAlphaBlending();
	float alpha = (1 - history) * 255;;
	ofSetColor(0, alpha);
	ofFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	ofDisableAlphaBlending();
	
	ofFill();
	for (int i = 0; i < p.size(); i++) {
		p[i].draw();
	}
	fbo.end();

	//2. draw buffer on screen
	ofSetColor(255);
	fbo.draw(0,0);
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
