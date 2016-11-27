#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   // ofSetLogLevel(OF_LOG_VERBOSE);
	bSendSerialMessage = false;
	
	loadSettings();
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 115200;

    bUseSerial = serial.setup(serialName[0], baud); //linux example

    if(bUseSerial) {
		bUseSerial = serial2.setup(serialName[1], baud); //linux example		
        unsigned char buf[10];
        serial.writeBytes(buf,10);
        serial2.writeBytes(buf,10);
    }

    poetry.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (bSendSerialMessage){
		
        writeWord(0);
        writeWord(1);
		
		bSendSerialMessage = false;

	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(0);
    ofDrawBitmapString("click to test serial.",20,20);
    for(int i = 0 ;i < 5;i++) {
		
		ofDrawBitmapString(w[i],100 * i+20, 100);
	}
}

//--------------------------------------------------------------
void ofApp::writeWord(int index)
{    
    string str = poetry.getWord(index);
    ofLogNotice() << "Word: " << str;
    if(bUseSerial) {
        unsigned char buf[10];
        for(unsigned int i = 0; i < str.length();i++)
        {
            buf[i] = str.c_str()[i];
        }
        if(index == 0)
			serial.writeBytes(buf,str.length());
		if(index == 1)
			serial2.writeBytes(buf,str.length());
    }
}


//
void ofApp::loadSettings()
{
	if(xml.load("settings.xml") ){
		ofLogNotice() << "settings.xml loaded!";
	} else {
		ofLogWarning() << "unable to load settings.xml";
	}
    
    if(xml.exists("//SERIAL0")) {
        serialName[0] = xml.getValue<string>("//SERIAL0");
    } else {
        serialName[0]  = "/dev/ttyACM0";
    }
       
    if(xml.exists("//SERIAL1")) {
        serialName[1] 	= xml.getValue<string>("//SERIAL1");
    } else {
        serialName[1]  = "/dev/ttyACM1";
    }
    
    if(xml.exists("//SERIAL2")) {
        serialName[2] 	= xml.getValue<string>("//SERIAL2");
    } else {
        serialName[2]  = "/dev/ttyACM2";
    }	
    
    if(xml.exists("//SERIAL3")) {
        serialName[3] 	= xml.getValue<string>("//SERIAL3");
    } else {
        serialName[3]  = "/dev/ttyACM3";
    }	    

    if(xml.exists("//SERIAL4")) {
        serialName[4] 	= xml.getValue<string>("//SERIAL4");
    } else {
        serialName[4]  = "/dev/ttyACM4";
    }	  
        
    for(int i = 0; i < NUM_WORDS; i++) {
		ofLogNotice("loadSettings") << "Port " << i << ": " << serialName[i] ;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	if(key == '1') w[0] = poetry.getWord(0);
	if(key == '2') w[1] = poetry.getWord(1);
	if(key == '3') w[2] = poetry.getWord(2);
	if(key == '4') w[3] = poetry.getWord(3);
	if(key == '5') w[4] = poetry.getWord(4);
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

