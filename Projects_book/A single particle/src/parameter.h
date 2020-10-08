#include"ofMain.h"

#pragma once
class parameter
{
public:
	ofPoint eCenter; // center of emmiter
	float eRad; // radius of emitter
	float velRad; // velocity radius of particle
	float lifeTime; // life time of particle
	float rotate; // particles rotation angles per second

	float force; //attraction and repultion force in emitter
	float spinning_force; // spining for inside emitter
	float friction; // friction in range on [0,1]

	void setup();
};

extern parameter params;



