#ifndef skater_obstacle_h
#define skater_obstacle_h

#include "ofMain.h"
#include "ofxImageSequence.h"

#define DOG        1
#define OLDLADY    2
#define CROWD      3
#define WALL       4

#define DOGCAT           1
#define OLDLADYFLOWER    2
#define CROWDRAMP        3


class Obstacle{
    
    public:
    
        void setup();
        void drawObstacle();
        void drawSolution();
        void changeModel(int newModel);
        void solution(int newModel);
    
    private:
    
        int currentModel;
        int currentSolution;
        ofxImageSequence sequenceObstacle;
        ofxImageSequence sequenceSolution;

 
};

#endif
