#include "ofMain.h"
#include "parameter.h"

#pragma once
class Particle
{
public:
	ofPoint pos; // position of particle
	ofPoint vel; // velocity of particle
	float time; // time of living
	float lifetime; // total lifetime of particle
	
	Particle();
	void setup();
	void update(float dt);
	void draw();
	bool live; // is particle is live
};

