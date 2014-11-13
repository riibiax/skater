#include "stateCreateOrigami.h"

StateCreateOrigami::StateCreateOrigami() : State::State(){
    setup();
    isexit = false;
}

void StateCreateOrigami::setup(){
    offset = 10;
    setupFirstPage();
}

void StateCreateOrigami::setupFirstPage(){
    mFont.loadFont("riot.ttf", 14); //jeans.ttf frabk.ttf
	mFont.setLineHeight(18.0f);
	mFont.setLetterSpacing(1.037);
    
    cat.loadImage("cat2.png");
    flower.loadImage("iris.png");
    ramp.loadImage("ramp2.png");
    backgroundimage.loadImage("origamipage1.png");
    
    catPosition = ofPoint(0, 180);
    flowerPosition = ofPoint(200,200);
    rampPosition = ofPoint(60,350);
    
    
    catscale = 0.08;
    flowerscale = 0.55;
    rampscale = 0.13;
    
    state = 0;
}

void StateCreateOrigami::update(){
    
    
}

void StateCreateOrigami::draw(){
    if(state == 0){
        drawFirstPage();
    }
    else if(state == 1){
        ofBackground(255);
        ofEnableAlphaBlending();
        ofSetColor(255);
        ofScale(0.5, 0.5);
        diagram.draw(0, 0);
    }
}

void StateCreateOrigami::drawFirstPage(){
    
    
    ofPushMatrix();
    ofScale(0.5, 0.5);
    backgroundimage.draw(0, 0);
    ofPopMatrix();
    
    //ofBackground(255);
    
    ofEnableAlphaBlending();
    
    /*ofPushMatrix();
     //ofSetColor(0);
     ofTranslate(35, 40, 0);
     string s = "CREATE ORIGAMI";
     ofRectangle rect = mFont.getStringBoundingBox(s, 0, 0);
     mFont.drawString(s, -rect.x, rect.y/2);
     ofPopMatrix();*/
    
    ofEnableAlphaBlending();
    //ofSetColor(255);
    //CAT//
    ofPushMatrix();
    ofTranslate(catPosition);
    ofScale(catscale, catscale);
    ofRotate(-15);
    cat.draw(0, 0);
    ofPopMatrix();
    
    //FLOWER//
    ofPushMatrix();
    ofTranslate(flowerPosition);
    ofScale(flowerscale, flowerscale);
    ofRotate(15);
    flower.draw(0, 0);
    ofPopMatrix();
    
    //RAMP//
    ofPushMatrix();
    ofTranslate(rampPosition);
    ofScale(rampscale, rampscale);
    ramp.draw(0, 0);
    ofPopMatrix();
    
    //BUTTON//
    ofPushMatrix();
    //ofSetColor(0);
    string s = "NEXT";
    ofRectangle rect = mFont.getStringBoundingBox(s, 0, 0);
    buttonPosition = ofPoint(ofGetWidth()-rect.width/2, ofGetHeight()-5);
    ofTranslate(buttonPosition);
    mFont.drawString(s, -rect.width/2, -rect.height/2);
    ofPopMatrix();
}

void StateCreateOrigami::touchDown(ofTouchEventArgs & touch){
    if(state == 0 && touch.numTouches == 1){
        if(inBound( touch, cat, catPosition, catscale)){
            state = 1;
            diagram.loadImage("catdiagram.png");
        }
        else if(inBound( touch, flower, flowerPosition, flowerscale)){
            state = 1;
            diagram.loadImage("irisdiagram.png");
        }
        else if(inBound( touch, ramp, rampPosition, rampscale)){
            state = 1;
            diagram.loadImage("rampdiagram.png");
        }
        else if(inBound(touch, mFont.getStringBoundingBox("NEXT", 0, 0), buttonPosition)){
            isexit = true;
        }
        
    }
    else
        state = 0;
}

bool StateCreateOrigami::inBound(ofTouchEventArgs & touch, ofImage mImage, ofPoint pos, float scale){
    if (touch.x < pos.x + mImage.getWidth()*scale + offset && touch.x > pos.x - offset && touch.y < pos.y + mImage.getHeight()*scale + offset  && touch.y > pos.y - offset) {
        return true;
    }
    
    return false;
}

bool StateCreateOrigami::inBound(ofTouchEventArgs & touch, ofRectangle rect, ofPoint pos){
    if (touch.x < pos.x + rect.width/2 + offset && touch.x > pos.x - rect.width/2 - offset && touch.y < pos.y + rect.height/2 + offset  && touch.y > pos.y - rect.height/2 - offset) {
        return true;
    }
    
    return false;
}

bool StateCreateOrigami::isExit(){
    
    return isexit;
}

void StateCreateOrigami::clear(){
    cat.clear();
    flower.clear();
    ramp.clear();
    backgroundimage.clear();
    diagram.clear();
    mFont.~ofTrueTypeFont();
    catPosition.~ofVec3f();
    flowerPosition.~ofVec3f();
    rampPosition.~ofVec3f();
    buttonPosition.~ofVec3f();
}

State * StateCreateOrigami::getNextState(){
    StateCreateMap * x = new StateCreateMap();
    return x;
}

