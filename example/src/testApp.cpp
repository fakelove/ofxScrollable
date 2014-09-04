#include "testApp.h"

#define FRAME_WIDTH 404
#define FRAME_HEIGHT 504
#define FADE_SIZE 50
//--------------------------------------------------------------
void testApp::setup(){
    textLong.load("textLong.png",FRAME_WIDTH,FRAME_HEIGHT,FADE_SIZE);
    textLong.setAnchorPercent(0.5,0.5);
    textLongPos.set(ofGetWidth()*0.25,ofGetHeight()*0.5);

    panel.setup(ofVec2f(ofGetWidth()*0.75,ofGetHeight()*0.5),404,504);
    textShortPos = ofPoint(ofGetWidth()*0.75,ofGetHeight()*0.5);
}

//--------------------------------------------------------------
void testApp::update(){
    textLong.update();
    
    panel.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(ofColor::white);
    ofSetColor(255);
    
    textLong.draw(textLongPos.x,textLongPos.y);
    
    panel.begin();
    for (int i = 0; i < 100; i++) {
        ofSetColor(255, 0, 255);
        ofCircle(0, i*45, ofMap(sin(ofGetElapsedTimef()), -1, 1, 10, 40));
    }
    panel.end();
    
    
    //Just squares to show the dimensions of the scrollable zone and fade
    ofSetColor(0);
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(ofGetWidth()*0.25,ofGetHeight()*0.5,textLong.getWidth(),textLong.getHeight());
    ofLine(ofGetWidth()*0.25-textLong.getWidth()*0.5,ofGetHeight()*0.5-textLong.getHeight()*0.5+FADE_SIZE,ofGetWidth()*0.25+textLong.getWidth()*0.5,ofGetHeight()*0.5-textLong.getHeight()*0.5+FADE_SIZE);
    ofLine(ofGetWidth()*0.25-textLong.getWidth()*0.5,ofGetHeight()*0.5+textLong.getHeight()*0.5-FADE_SIZE,ofGetWidth()*0.25+textLong.getWidth()*0.5,ofGetHeight()*0.5+textLong.getHeight()*0.5-FADE_SIZE);
    
    //Just squares to show the dimensions of the scrollable zone and fade
    ofSetColor(0);
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofRect(ofGetWidth()*0.75,ofGetHeight()*0.5,textLong.getWidth(),textLong.getHeight());
    ofLine(ofGetWidth()*0.75-textLong.getWidth()*0.5,ofGetHeight()*0.5-textLong.getHeight()*0.5+FADE_SIZE,ofGetWidth()*0.75+textLong.getWidth()*0.5,ofGetHeight()*0.5-textLong.getHeight()*0.5+FADE_SIZE);
    ofLine(ofGetWidth()*0.75-textLong.getWidth()*0.5,ofGetHeight()*0.5+textLong.getHeight()*0.5-FADE_SIZE,ofGetWidth()*0.75+textLong.getWidth()*0.5,ofGetHeight()*0.5+textLong.getHeight()*0.5-FADE_SIZE);
    //
    ofSetRectMode(OF_RECTMODE_CORNER);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    ofRectangle textLongRect(textLongPos.x-0.5*textLong.getWidth(),textLongPos.y-0.5*textLong.getHeight(),textLong.getWidth(),textLong.getHeight());
    if(textLongRect.inside(x,y)){
        textLong.pressed(ofPoint(x,y));
        return;
    }
    ofRectangle textShortRect(textShortPos.x-0.5*panel.getWidth(),textShortPos.y-0.5*panel.getHeight(),panel.getWidth(),panel.getHeight());
    if(textShortRect.inside(x,y)){
        panel.pressed(ofPoint(x,y));
        return;
    }
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if(textLong.dragged(ofPoint(x,y))){
        return;
    }
    if(panel.dragged(ofPoint(x,y))){
        return;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if(textLong.released(ofPoint(x,y))){
        return;
    }
    if(panel.released(ofPoint(x,y))){
        return;
    }
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
