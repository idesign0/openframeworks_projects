#include "ofMain.h"

class Circle {
public:
	void setup();

	ofParameterGroup params;
	
	ofParameter<int> x;
	ofParameter<int> y;
	ofParameter<ofVec3f> colors;
};

