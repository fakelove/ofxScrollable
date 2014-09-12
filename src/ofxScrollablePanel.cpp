//
//  ofxScrollablePanel.cpp
//  example
//
//  Created by Dan Moore on 9/4/14.
//
//

#include "ofxScrollablePanel.h"

#define DAMPING 5.
#define MASS 0.1
#define K 30.

ofxScrollablePanel::ofxScrollablePanel(){
    p=false;
    pOrigin=0;
    desOrigin=0;
    
    reset();
}

void ofxScrollablePanel::setup(ofVec2f _anchor, float _width, float _height){
    rect = ofRectangle(_anchor, _width, _height);
    anchor = _anchor;
    width = _width;
    height = _height;
    reset();
    //ofAddListener(ofEvents().update, this, &ofxScrollablePanel::update);
    scrollBar = ofRectangle(anchor.x+width, 0, 10, height);
}

void ofxScrollablePanel::begin(){
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(anchor);
    ofSetColor(255, 255, 255, 200);
    ofRect(width, 0, 10, height);
    ofSetColor(100, 100, 100, 200);
    if(contentHeight > 0){
        ofRect(width, -ofMap(position, 0, contentHeight, 0, height, true), 10, 15);
    }
    ofTranslate(0, position);


}
void ofxScrollablePanel::setContentHeight(float _height){
    newContentHeight = _height;
}

void ofxScrollablePanel::end(){
    ofPopMatrix();
    ofSetColor(255, 255, 255, 255);
    ofPopStyle();
}

void ofxScrollablePanel::update(){
    
    float t=ofGetElapsedTimef();
    float dt=t-time;
    time=t;
    
    contentHeight = ofLerp(contentHeight, newContentHeight, dt);
    
    float accel=destination-position;
    accel*=(K/MASS);
    accel-=(DAMPING/MASS)*velocity;
    velocity+=(accel*dt);
    position+=(velocity*dt);
}

bool ofxScrollablePanel::pressed(ofPoint pos, int ID){
    p=true;
    pID=ID;
    pOrigin=pos.y;
    desOrigin=destination;
    return true;
}

bool ofxScrollablePanel::dragged(ofPoint pos, int ID){
    if(p && pID==ID){
        destination = desOrigin + (pos.y - pOrigin);
        return true;
    }
    return false;
}

bool ofxScrollablePanel::released(ofPoint pos, int ID){
    if(p && pID==ID){
        destination = desOrigin + (pos.y - pOrigin);
        if(contentHeight<height){
            destination = 0;
        }
        else if(destination>0){
            destination = 0;
        }
        else if(destination< (height-contentHeight)){
            destination = (height-contentHeight);
        }
        p = false;
        return true;
    }
    return false;
}

float ofxScrollablePanel::getWidth(){
    return width;
}
float ofxScrollablePanel::getHeight(){
    return height;
}

void ofxScrollablePanel::reset(){
    position=0;
    destination=0;
    velocity=0;
}