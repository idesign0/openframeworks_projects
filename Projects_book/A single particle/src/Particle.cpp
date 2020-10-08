#include "Particle.h"

ofPoint randomPointInCircle(float maxrad) {
	ofPoint pnt;
	float rad = maxrad;
	float ang = ofRandom(0, M_TWO_PI);
	pnt.x = sin(ang)*rad;
	pnt.y = cos(ang)*rad;
	return pnt;
}

Particle::Particle() {
	live = false;
}

void Particle::setup(){
	pos = params.eCenter + randomPointInCircle(params.eRad);
	vel = randomPointInCircle(params.velRad);
	time = 0;
	lifetime = params.lifeTime;
	live = true;
}

void Particle::update(float dt) {
	if (live) {
		vel.rotate(0, 0, params.rotate*dt);

		ofPoint acc; // acceleration
		ofPoint delta = pos - params.eCenter;
		float len = delta.length();

		if (ofInRange(len, 0, params.eRad)) {
			delta.normalize();

			//attraction/repultion force
			acc += delta * params.force;

			//spining force
			acc.x += -delta.y*params.spinning_force;
			acc.y += delta.x*params.spinning_force;
		}

		vel += acc * dt; // euler method
		vel *= (1 - params.friction);

		pos += vel*dt;
		time += dt;
		if (time > lifetime) {
			live = false;
		}
	}
}

void Particle::draw() {
		if (live) {
			float size = ofMap(
				fabs(time - lifetime / 2), 0, lifetime/2, 4, 2);

			ofColor color = ofColor::red;
			float hue = ofMap(time, 0, lifetime, 128, 255);
			color.setHue(hue);
			ofSetColor(color);

			ofCircle(pos, size);
		}
}