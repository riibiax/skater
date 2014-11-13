#include "stateCreateMap.h"


StateCreateMap::StateCreateMap() : State::State(){
    setup();
}

void StateCreateMap::setup(){
    map.loadImage("Level1MapColour.png");
    
    mFont.loadFont("riot.ttf", 11); //jeans.ttf frabk.ttf
	mFont.setLineHeight(18.0f);
	mFont.setLetterSpacing(1.037);
    
    isexit = false;
}


void StateCreateMap::update(){
    
}

void StateCreateMap::draw(){
    //ofBackground(255);
    //ofEnableAlphaBlending();
    
    ofPushMatrix();
    //ofSetColor(255);
    ofScale(0.5, 0.5);
    map.draw(0, 0);
    ofPopMatrix();
    
    /*ofPushMatrix();
     ofSetColor(0);
     string s = "CREATE MAP";
     ofRectangle rect = mFont.getStringBoundingBox(s, 0, 0);
     ofTranslate(rect.height/2, ofGetHeight()-rect.width/2-5, 0);
     ofRotate(-90);
     mFont.drawString(s, -rect.width/2, rect.height/2);
     ofPopMatrix();*/
    
    ofPushMatrix();
    //ofSetColor(0);
    string s = "NEXT";
    ofRectangle rect = mFont.getStringBoundingBox(s, 0, 0);
    buttonPosition = ofPoint(ofGetWidth()-rect.height, rect.width/2+5);
    ofTranslate(buttonPosition);
    ofRotate(-90);
    mFont.drawString(s, -rect.width/2, rect.height/2);
    ofPopMatrix();
    
}
void StateCreateMap::touchDown(ofTouchEventArgs & touch){
    if(inBound(touch, mFont.getStringBoundingBox("NEXT", 0, 0), buttonPosition)){
        isexit = true;
    }
}

bool StateCreateMap::inBound(ofTouchEventArgs & touch, ofRectangle rect, ofPoint pos){
    int offset = 10;
    if (touch.x < pos.x + rect.height/2 + offset && touch.x > pos.x - rect.height/2 - offset && touch.y < pos.y + rect.width/2 + offset  && touch.y > pos.y - rect.width/2 - offset) {
        return true;
    }
    
    return false;
}

bool StateCreateMap::isExit(){
    return isexit;
}

void StateCreateMap::clear(){
    map.clear();
    mFont.~ofTrueTypeFont();
    buttonPosition.~ofVec3f();
}

State * StateCreateMap::getNextState(){
    return new StatePlay();
}

