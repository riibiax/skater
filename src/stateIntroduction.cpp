#include "stateIntroduction.h"

StateIntroduction::StateIntroduction() : State::State(){
    setup();
    isexit = false;
    play = true;
}

void StateIntroduction::setup(){
    offset = 30;
    
    //sequence.loadSequence("IntroAnimation");
    sequence.loadSequence("WhiteText/Frame-", "png", 1, 14, 1);
    sequence.preloadAllFrames();
    sequence.setFrameRate(5);
    
    sequence2.loadSequence("IntroStartPagelayer2/Frame-", "png", 1, 5, 1);
    sequence2.preloadAllFrames();
    sequence2.setFrameRate(5);
    
    startBackground.loadImage("otherintro.png");
    startText.loadImage("start.png");
    startTextPosition = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
}

void StateIntroduction::update(){
    //cout<<sequence.getCurrentFrame()<<"/"<<sequence.getTotalFrames()<<endl;
    if (sequence.getCurrentFrame() == sequence.getTotalFrames()-1) { //play&&
        play = false;
    }
}

void StateIntroduction::draw(){
    ofEnableAlphaBlending();
    ofPushMatrix();
    ofScale(0.5, 0.5);
    if (play) {
        sequence.getFrameForTime(ofGetElapsedTimef())->draw(0,0);
    }
    else{
        //sequence.getFrameAtPercent(0)->draw(0, 0);
        startBackground.draw(0, 0);
        sequence2.getFrameForTime(ofGetElapsedTimef())->draw(0,0);
        startText.draw(ofGetWidth()-startText.getWidth()/2+5,ofGetHeight()-startText.getHeight()/2);
    }
    ofPopMatrix();
}

void StateIntroduction::drawFirstPage(){
    ofBackground(255);
}

void StateIntroduction::touchDown(ofTouchEventArgs & touch){
    if (inBound(touch, startText, startTextPosition, 0.5)) {
        isexit = true;
        //cout<<"OUCH";
    }
}

bool StateIntroduction::inBound(ofTouchEventArgs & touch, ofImage mImage, ofPoint pos, float scale){
    if (touch.x < pos.x + mImage.getWidth()*scale + offset && touch.x > pos.x - offset && touch.y < pos.y + mImage.getHeight()*scale + offset  && touch.y > pos.y - offset) {
        return true;
    }
    
    return false;
}

bool StateIntroduction::inBound(ofTouchEventArgs & touch, ofRectangle rect, ofPoint pos){
    if (touch.x < pos.x + rect.width/2 + offset && touch.x > pos.x - rect.width/2 - offset && touch.y < pos.y + rect.height/2 + offset  && touch.y > pos.y - rect.height/2 - offset) {
        return true;
    }
    
    return false;
}

bool StateIntroduction::isExit(){
    return isexit;
}

void StateIntroduction::clear(){
    sequence.unloadSequence();
    sequence2.unloadSequence();
    startBackground.clear();
    startText.clear();
    startTextPosition.~ofVec3f();
}

State * StateIntroduction::getNextState(){
    StateCreateOrigami * x = new StateCreateOrigami();
    return x;
}