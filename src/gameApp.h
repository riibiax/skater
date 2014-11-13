#pragma once


#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#include "state.h"
#include "stateIntroduction.h"

class gameApp : public ofxiPhoneApp{
	
    public:
    
        void setup();
        void update();
        void draw();
        void exit();
    
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);
	
        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
        void offScreenController();
        void onScreenController();
    
        void changeState(State & newstate);
    
        ofImage menuImage;
    
        int gameState;
        State * mState;
};
