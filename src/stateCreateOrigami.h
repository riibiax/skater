#ifndef skater_StateCreateOrigami_h
#define skater_StateCreateOrigami_h

#include "ofMain.h"
#include "state.h"
#include "stateCreateMap.h"

class StateCreateOrigami : public State{
    public:
        StateCreateOrigami();
        void setup();
        void update();
        void draw();
        void touchDown(ofTouchEventArgs & touch);
        void clear();
        bool isExit();
    
    private:
        void drawFirstPage();
        void setupFirstPage();
        bool inBound(ofTouchEventArgs & touch, ofImage mImage, ofPoint pos, float scale);
        bool inBound(ofTouchEventArgs & touch, ofRectangle rect, ofPoint pos);
    
        bool isexit;
        State * getNextState();
    
        ofImage backgroundimage;
        ofImage cat;
        ofImage flower;
        ofImage ramp;
        ofImage diagram;
    
        ofPoint catPosition;
        ofPoint flowerPosition;
        ofPoint rampPosition;
        ofPoint buttonPosition;
    
        float catscale;
        float flowerscale;
        float rampscale;
    
        int state;
        ofTrueTypeFont mFont;
        float offset;
};

#endif
