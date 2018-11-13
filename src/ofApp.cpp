#include "ofApp.h"

//Listen to localhost
#define HOST "10.0.0.65"

//create osc message object
ofxOscMessage m;
string incomingAddr;
string incomingVal;

string msg[4];
//--------------------------------------------------------------
void ofApp::setup(){
    //now we need to set up a receiver
    receiver.setup(5000);
}

//--------------------------------------------------------------
void ofApp::update(){

    while(receiver.getNextMessage(m)) {
        if (m.getAddress() == "museData /elements/beta_absolute"){
            incomingAddr = m.getAddress();
            //loop through the incoming arguments check their type and conver to string as needed
            for(int i = 0; i < m.getNumArgs(); i++){
                if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
                    incomingVal = ofToString(m.getArgAsFloat(i));
                    msg[i] = incomingVal;
                }
                ofLog(OF_LOG_NOTICE, "beta 1: " + msg[3] + ", beta 2: " + msg[1] + ", beta 3: " + msg[2] + ", beta 4: " + msg[3]);
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(incomingAddr, 0, 10);
    ofDrawBitmapString(incomingVal, 0, 20);
    ofDrawBitmapString(msg[0], 0, 30);
    ofDrawBitmapString(msg[1], 0, 40);
    ofDrawBitmapString(msg[2], 0, 50);
    ofDrawBitmapString(msg[3], 0, 60);
}
