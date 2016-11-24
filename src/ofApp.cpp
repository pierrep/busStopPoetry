#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_NOTICE);
	bSendSerialMessage = false;
	
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	int baud = 9600;
    bUseSerial = serial.setup(0, baud); //open the first device

	//serial.setup("/dev/ttyUSB0", baud); //linux example
    if(bUseSerial) {
        unsigned char buf[10];
        serial.writeBytes(buf,10);
    }

    poetry.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (bSendSerialMessage){
		
        writeWord();
		
		bSendSerialMessage = false;

	}
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBitmapString("click to test serial.",20,20);

}

//--------------------------------------------------------------
void ofApp::writeWord()
{

    string str = poetry.getWord(0);
    ofLogNotice() << "Word: " << str;
    if(bUseSerial) {
        unsigned char buf[10];
        for(unsigned int i = 0; i < str.length();i++)
        {
            buf[i] = str.c_str()[i];
        }
        serial.writeBytes(buf,str.length());
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	bSendSerialMessage = true;
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

