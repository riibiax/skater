#ifndef skater_stateGameOver_h
#define skater_stateGameOver_h

#include "ofMain.h"
#include "state.h"
#include "statePlay.h"

class StateGameOver : public State{
    public:
        StateGameOver();
        void setup();
        void update();
        void draw();
        void touchDown(ofTouchEventArgs & touch);
        bool inBound(ofTouchEventArgs & touch, ofRectangle rect, ofPoint pos);
        void clear();
        bool isExit();
        State * getNextState();
    
    private:
        ofImage map;
        ofTrueTypeFont mFont;
        bool isexit;
        ofPoint buttonPosition;
};

#endif
