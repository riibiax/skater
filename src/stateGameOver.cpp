#include "stateGameOver.h"


StateGameOver::StateGameOver() : State::State(){
    setup();
}

void StateGameOver::setup(){
    map.loadImage("map.png");
    
    mFont.loadFont("riot.ttf", 11); //jeans.ttf frabk.ttf
	mFont.setLineHeight(18.0f);
	mFont.setLetterSpacing(1.037);
    
    isexit = false;
    
}


void StateGameOver::update(){
    
}

void StateGameOver::draw(){
    ofBackground(255);
    ofEnableAlphaBlending();
    
    ofPushMatrix();
    ofSetColor(0);
    string s = "RESTART?";
    ofRectangle rect = mFont.getStringBoundingBox(s, 0, 0);
    buttonPosition = ofPoint(ofGetWidth()-rect.height, rect.width/2+5);
    ofTranslate(buttonPosition);
    ofRotate(-90);
    mFont.drawString(s, -rect.width/2, rect.height/2);
    ofPopMatrix();
    
}
void StateGameOver::touchDown(ofTouchEventArgs & touch){
    if(inBound(touch, mFont.getStringBoundingBox("NEXT", 0, 0), buttonPosition)){
        isexit = true;
    }
}

bool StateGameOver::inBound(ofTouchEventArgs & touch, ofRectangle rect, ofPoint pos){
    int offset = 10;
    if (touch.x < pos.x + rect.height/2 + offset && touch.x > pos.x - rect.height/2 - offset && touch.y < pos.y + rect.width/2 + offset  && touch.y > pos.y - rect.width/2 - offset) {
        return true;
    }
    
    return false;
}

bool StateGameOver::isExit(){
    clear();
    return isexit;
}

void StateGameOver::clear(){
    map.clear();
    mFont.~ofTrueTypeFont();
    buttonPosition.~ofVec3f();
}

State * StateGameOver::getNextState(){
    return new StatePlay();
}