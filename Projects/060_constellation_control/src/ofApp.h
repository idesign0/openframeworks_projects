#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofEasyCam cam;

		ofxOscReceiver osc;
		ofMesh mesh;

		float uiamount;
		float uipos1;
		float uipos2;
		float uipos3;
		float uipos4;
		float uipos5;
		float uipos6;
		float uidistance;
		bool uipoints;
};
