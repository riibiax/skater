#include "statePlay.h"

StatePlay::StatePlay() : State::State(){
    isexit = false;
    setup();
}

void StatePlay::setup(){
    skater.setup();
    
    level.setup();
    
    decor.setup();
    
    //Accelerometer setup
    ofxAccelerometer.setup();
    
    blobs.clear();
    
    delaytime = 50;
}

void StatePlay::update(){
    
    level.update();
    
    skater.update(level.getStatus());
    
    blobs = level.vision.getBlobs();
    
    if(level.getStatus()==0){
        delaytime--;
        if(delaytime==0)
            isexit = true;
    }
}

void StatePlay::draw(){
    
    ofPoint a = ofxAccelerometer.getForce();
    ofPushMatrix();
    level.draw();
    
    if (!level.getStopDrawingSkater())
        skater.draw();
    
   // decor.draw(blobs, ofToFloat(ofToString(a.x,3)));
    ofPopMatrix();
}

void StatePlay::touchDown(ofTouchEventArgs & touch){
    
}

bool StatePlay::isExit(){
    return isexit;
}

void StatePlay::clear(){    
    blobs.clear();
}

State * StatePlay::getNextState(){
    return new StateGameOver();
}


