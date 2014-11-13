#ifndef skater_statePlay_h
#define skater_statePlay_h

#include "ofxiPhone.h"
#include "ofxOpenCv.h"
#include "state.h"
#include "skater.h"
#include "level.h"
#include "decor.h"
#include "stateGameOver.h"

class StatePlay : public State{
    public:
        StatePlay();
        void setup();
        void update();
        void draw();
        void touchDown(ofTouchEventArgs & touch);
        void clear();
        bool isExit();
        State * getNextState();
    
        Level level;
        Skater skater;
        Decor decor;
    
        int delaytime;
    
    private:
        vector<ofxCvBlob> blobs;
        bool isexit;
};

#endif
