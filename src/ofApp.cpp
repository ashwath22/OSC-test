#include "ofApp.h"

//Listen to localhost
#define HOST "10.0.0.65"

//create osc message object
ofxOscMessage m;
string incomingAddr;
string incomingVal;
int t=100;
string msg[4];
//--------------------------------------------------------------
void ofApp::setup(){
    //now we need to set up a receiver
    receiver.setup(5000);
}

//--------------------------------------------------------------
void ofApp::update(){

    while(receiver.getNextMessage(m)) {
        //just print out the address of the message
//        cout << m.getAddress() + " " + ofToString(m.getArgAsFloat(0)) << endl;
//        cout << m.getAddress() << endl;
        if (m.getAddress() == "museData /elements/beta_absolute"){
            incomingAddr = m.getAddress();
            //create a string to hold the incoming arguments
            string msg_string;
            msg_string = m.getAddress();
            msg_string += ": ";
            
            //loop through the incoming arguments check their type and conver to string as needed
            for(int i = 0; i < m.getNumArgs(); i++){
                // get the argument type
                msg_string += m.getArgTypeName(i);
                msg_string += ":";
                // display the argument - make sure we get the right type
                if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
                    msg_string += ofToString(m.getArgAsFloat(i));
                    incomingVal = ofToString(m.getArgAsFloat(i));
                    msg[i] = incomingVal;
                }
                else{
                    msg_string += "unknown";
                }
//                ofLog(OF_LOG_NOTICE, msg_string);
                ofLog(OF_LOG_NOTICE, "beta 1: " + msg[3] + ", beta 2: " + msg[1] + ", beta 3: " + msg[2] + ", beta 4: " + msg[3]);
            }
    //        sleep(1);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(incomingAddr, 0, 10);
    ofDrawBitmapString(incomingVal, 0, 20);
//    if(incomingAddr == "/1/toggle1" && incomingVal == "0"){
//        ofBackground(255, 0, 0);
//    } else if(incomingAddr == "/1/toggle1" && incomingVal == "1"){
//        ofBackground(0, 255, 0);
//    }
//
//    if(incomingAddr == "/1/fader1"){ /*[notice ] /1/fader1: f:0.61125*/
//        int l = ofMap(ofToFloat(incomingVal),0.0,0.1,0,255);
//        ofSetColor(255,l,0);
//        ofDrawCircle(200,400,l);
//    }
//    if(incomingAddr == "museData /gyro"){
//        ofDrawBitmapString(incomingAddr, 0, 10);
//        ofDrawBitmapString(incomingVal, 0, 20);
//    }
//    if(incomingAddr == "museData /notch_filtered_eeg"){
//        ofDrawBitmapString(incomingAddr, 0, 10);
//        ofDrawBitmapString(incomingVal, 0, 20);
//    }
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
