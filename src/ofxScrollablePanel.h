//
//  ofxScrollablePanel.h
//  example
//
//  Created by Dan Moore on 9/4/14.
//
//

#pragma once

#include "ofMain.h"

class ofxScrollablePanel {
public:
    
    ofxScrollablePanel();
    
    ~ofxScrollablePanel(){};
    void setup(ofVec2f _anchor, float width, float height);
    void update(ofEventArgs& args);
    void begin();
    void end();
    void reset();
    
    float getWidth();
    float getHeight();
    
    bool pressed(ofPoint pos, int ID=0);
    bool dragged(ofPoint pos, int ID=0);
    bool released(ofPoint pos, int ID=0);
    ofRectangle rect;
private:
    float width,height;
    ofVec2f anchor;
    
    float panelWidth,panelHeight;
    
    float position;
    float destination;
    float velocity;
    
    bool p;
    int pID;
    float pOrigin;
    float desOrigin;
    
    float fadeSize;
    
    float time;
};
