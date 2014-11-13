#ifndef skater_Header_h
#define skater_Header_h

#include "ofMain.h"
#include "state.h"
#include "stateCreateOrigami.h"

class StateIntroduction : public State{
    public:
        StateIntroduction();
        void setup();
        void update();
        void draw();
        void touchDown(ofTouchEventArgs & touch);
        void clear();
        bool isExit();
    
    private:
        void drawFirstPage();
        bool inBound(ofTouchEventArgs & touch, ofImage mImage, ofPoint pos, float scale);
        bool inBound(ofTouchEventArgs & touch, ofRectangle rect, ofPoint pos);
    
        bool isexit;
        State * getNextState();
        bool play;
        ofxImageSequence sequence;
        ofxImageSequence sequence2;
    
        ofImage startBackground;
        ofImage startText;
        ofPoint startTextPosition;
    
        float offset;
        //OF_LOOP_NONE
};
#endif
