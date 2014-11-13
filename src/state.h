#ifndef skater_state_h
#define skater_state_h

#include "ofMain.h"

class State{
    public:
        State();
        void setup();
        virtual void update();
        virtual void draw();
        void exit();
        virtual void clear();
        virtual void touchDown(ofTouchEventArgs & touch);
    
        virtual bool isExit();
        virtual State * getNextState();
};

#endif
