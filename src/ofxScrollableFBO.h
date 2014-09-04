//
//  ofxScrollableFBO.h
//  ofxScrollableFBO
//
//  Created by jvelazqueztraut on 18/02/14.
//
//
#pragma once

#include "ofMain.h"

class ofxScrollableFBO: public ofFbo{
public:
    
    ofxScrollableFBO();
    
    ~ofxScrollableFBO(){};
    
    void load(string path, float w, float h, float f=20.);
    void load(ofPixels text, float w, float h, float f=20.);
    
    void update();
    
    void reset();
        
    float getWidth();
    float getHeight();
    
    bool pressed(ofPoint pos, int ID=0);
    bool dragged(ofPoint pos, int ID=0);
    bool released(ofPoint pos, int ID=0);
        
private:
    float width,height;
    ofVec2f anchor;
    
    ofTexture tex;
    float texWidth,texHeight;
    
    float position;
    float destination;
    float velocity;
    
    bool p;
    int pID;
    float pOrigin;
    float desOrigin;
    
    ofTexture fade;
    float fadeSize;
    
    float time;
};
