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
    void update();
    void begin();
    void end();
    void reset();
    
    float getWidth();
    float getHeight();
    
    bool pressed(ofPoint pos, int ID=0);
    bool dragged(ofPoint pos, int ID=0);
    bool released(ofPoint pos, int ID=0);
    void setContentHeight(float _height);
    float getContentHeight(){
        return contentHeight;
    }
    ofRectangle getRect(){
        return rect;
    }
    float getScroll(){
        return position;
    }
    ofRectangle getScrollBar(){
        return scrollBar;
    }
protected:
    ofRectangle scrollBar;
    ofRectangle rect;
    float position;
private:
    float width,height;
    float contentHeight;
    float newContentHeight;
    ofVec2f anchor;
    
    float panelWidth,panelHeight;
    

    float destination;
    float velocity;
    
    bool p;
    int pID;
    float pOrigin;
    float desOrigin;
    
    float fadeSize;
    
    float time;
};
