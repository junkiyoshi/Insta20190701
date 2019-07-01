#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
}
//--------------------------------------------------------------
void ofApp::update() {
	
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	array<float, 2> noise_seeds;
	for (int i = 0; i < noise_seeds.size(); i++) {
		
		noise_seeds[i] = ofRandom(1000);
	}

	auto span = 30;
	for (int x = 0; x <= ofGetWidth(); x += span) {

		vector<glm::vec2> vertices;

		int left_x = x - span * 0.5;
		int right_x = x + span * 0.5;

		vertices.push_back(glm::vec2(left_x, ofMap(ofNoise(noise_seeds[0], left_x * 0.0005 + ofGetFrameNum() * 0.003), 0, 1, 200, ofGetHeight() - 200)));
		vertices.push_back(glm::vec2(right_x, ofMap(ofNoise(noise_seeds[0], right_x * 0.0005 + ofGetFrameNum() * 0.003), 0, 1, 200, ofGetHeight() - 200)));
		vertices.push_back(glm::vec2(right_x, ofMap(ofNoise(noise_seeds[1], right_x * 0.0005 + ofGetFrameNum() * 0.003), 0, 1, 200, ofGetHeight() - 200)));
		vertices.push_back(glm::vec2(left_x, ofMap(ofNoise(noise_seeds[1], left_x * 0.0005 + ofGetFrameNum() * 0.003), 0, 1, 200, ofGetHeight() - 200)));

		auto distance = glm::distance(vertices[0], vertices[3]);
	
		ofFill();
		ofSetColor(39, ofMap(distance, 0, ofGetHeight() * 0.45, 255, 0));
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		ofNoFill();
		ofSetColor(239);
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}