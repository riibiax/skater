#ifndef skater_skater_h
#define skater_skater_h


#include "ofMain.h"
#include "ofxImageSequence.h"


#define SKATER_DEAD     0
#define SKATER_WINS     1
#define SKATER_RUN      2
#define SKATER_BREAK    3
#define SKATER_GRAVEL   4
#define SKATER_OIL      5


class Skater{
    
    public:
    
        void setup();
        void update(int status);
        void draw();

    private:
        
        void changeAction(int);
        int currentAction;
        ofxImageSequence sequence;
    
        /*ofPoint position;
        Model* model;*/
    
};
#endif
