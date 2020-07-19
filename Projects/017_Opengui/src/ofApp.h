#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		
		ofxPanel gui;

		ofxIntSlider intslider;
		ofxFloatSlider floatslider;

		ofxToggle toggle;
		ofxButton button;
		ofxLabel label;

		ofxIntField intfield;
		ofxFloatField floatfield;
		ofxTextField textfield;

		ofxVec2Slider Vec2Slider;
		ofxVec3Slider Vec3Slider;
		ofxVec4Slider Vec4Slider;
};
