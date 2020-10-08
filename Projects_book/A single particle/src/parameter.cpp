#include "parameter.h"
parameter params;
void parameter::setup() {
	eCenter = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
	eRad = 100;
	velRad = 0;
	lifeTime = 2.0;
	rotate = 0;

	force = 1000;
	spinning_force = 1000;
	friction = 0.05;
}



