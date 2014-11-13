#ifndef skater_stateCreateMap_h
#define skater_stateCreateMap_h

#include "ofMain.h"
#include "state.h"
#include "statePlay.h"

class StateCreateMap : public State{
    public:
        StateCreateMap();
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
