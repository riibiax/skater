#include "gameApp.h"



//--------------------------------------------------------------
void gameApp::setup(){
    StateIntroduction * x = new StateIntroduction();
    //StatePlay *x = new StatePlay();
    changeState(*x);
}

void gameApp::changeState(State & newstate){
    mState = &newstate;
}

//--------------------------------------------------------------
void gameApp::update(){
    mState->update();
    if(mState->isExit()){
        mState->clear();
        State * x = mState->getNextState();
        delete mState;
        changeState(*x);
    }
}

//--------------------------------------------------------------
void gameApp::draw(){
    mState->draw();
}

//--------------------------------------------------------------
void gameApp::exit(){
    
}

//--------------------------------------------------------------
void gameApp::touchDown(ofTouchEventArgs & touch){
    mState->touchDown(touch);
}

//--------------------------------------------------------------
void gameApp::touchMoved(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void gameApp::touchUp(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void gameApp::touchDoubleTap(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void gameApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void gameApp::lostFocus(){
    
}

//--------------------------------------------------------------
void gameApp::gotFocus(){
    
}

//--------------------------------------------------------------
void gameApp::gotMemoryWarning(){
    
}

//--------------------------------------------------------------
void gameApp::deviceOrientationChanged(int newOrientation){
    
}
