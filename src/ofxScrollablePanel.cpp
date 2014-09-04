//
//  ofxScrollablePanel.cpp
//  example
//
//  Created by Dan Moore on 9/4/14.
//
//

#include "ofxScrollablePanel.h"

#define DAMPING 10.
#define MASS 1.
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
}

void ofxScrollablePanel::begin(){
    ofPushMatrix();
    ofTranslate(anchor);
    ofTranslate(0, position);
}

void ofxScrollablePanel::end(){
    ofPopMatrix();
}

void ofxScrollablePanel::update(){
    
    float t=ofGetElapsedTimef();
    float dt=t-time;
    time=t;
    
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
        if(destination > 0){
            destination = 0;
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