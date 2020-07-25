#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(uilearn.setup("learn"));
	gui.add(uiclearcirlce.setup("clear cirlces"));
	gui.add(uiclearcontouredge.setup("clear contour"));
	gui.add(uithreshold.setup("Thresold", 50, 0, 100));

	cam.setDeviceID(1);
	cam.setup(640,480);
	color.allocate(cam.getWidth(), cam.getHeight());
	grayscale.allocate(cam.getWidth(), cam.getHeight());
	background.allocate(cam.getWidth(), cam.getHeight());
	difference.allocate(cam.getWidth(), cam.getHeight());

	box2d.init();
	box2d.setGravity(0, 30);
	box2d.createGround();
	box2d.createBounds(ofRectangle(0, 0, cam.getWidth(), cam.getHeight()));

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
	cam.update();

	if (cam.isFrameNew()) {
		color.setFromPixels(cam.getPixels());
		grayscale = color;
		difference.absDiff(background, grayscale);
		difference.threshold(uithreshold);

		int minimum = difference.getWidth() * difference.getHeight() * 0.05;
		int maximum = difference.getWidth() * difference.getHeight() * 0.8;

		contour.findContours(difference, minimum, maximum, 1, false);
	}

	if (uilearn) {
		background = color;
	}

	if (uiclearcirlce) {
		circles.clear();
	}
	if (uiclearcontouredge) {
		contouredge->clear();
		background = color;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	color.draw(0, 0);
	if (!contour.blobs.empty()) {
		createContourEdge(ofPolyline(contour.blobs.at(0).pts));
		contouredge->draw();
	}

	for (auto circle : circles) {
		circle->draw();
	}
	gui.draw(); 
}

void ofApp::createContourEdge(ofPolyline polyline) {
	delete contouredge;
	contouredge = new ofxBox2dEdge();
	contouredge->addVertexes(polyline);
	contouredge->create(box2d.getWorld());
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
	auto circle = make_shared<ofxBox2dCircle>();
	circle->setPhysics(8.0, 0.8, 0.1);
	circle->setup(box2d.getWorld(), x, y, 32);
	circles.push_back(circle);
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
