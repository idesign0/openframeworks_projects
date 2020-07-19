#include "circle.h"

void Circle::setup() {
	params.setName("Circle Params");
	params.add(x.set("x", ofGetWidth() / 2, 0, ofGetWidth()));
	params.add(y.set("y", ofGetHeight() / 2, 0, ofGetHeight()));
	
	params.add(colors.set("Colors", ofVec3f(40, 40, 40), ofVec3f(0, 0, 0), ofVec3f(255, 255, 255)));
}