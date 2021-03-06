#include "testApp.h"

#include "ofxSuperCollider.h"
#include "ofxSuperColliderServer.h"

ofxSCSynth *synth1 = NULL;
ofxSCSynth *synth2 = NULL;

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofxSuperColliderServer::init();

	synth1 = new ofxSCSynth("sine");
	synth1->create();

	synth2 = new ofxSCSynth("sine");
	synth2->create();		
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	ofxSCSynth perc("perc");
	perc.create();
	perc.set("freq", ofRandom(100, 300));
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	if (synth1)
	{
		synth1->set("freq", 2.0f * x);
		synth1->set("pan", ofMap(x, 0, ofGetWidth(), -1, 1, true));
		
		synth2->set("freq", 2.01f * x);
		synth2->set("pan", ofMap(x, 0, ofGetWidth(), 1, -1, true));
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
}

