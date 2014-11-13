#ifndef skater_level_h
#define skater_level_h


#include "ofMain.h"
#include "obstacle.h"
#include "timer.h"
#include "vision.h"


#define SKATER_DEAD     0
#define SKATER_WINS     1
#define SKATER_RUN      2
#define SKATER_BREAK    3
#define SKATER_GRAVEL   4
#define SKATER_OIL      5


class Level {
    
    public:
    
        void setup();
        void draw();
        void update();
        
        void increaseLevel();

        int getLevelNumber();
        int getStatus();
    
        bool getStopDrawingSkater();

        Vision vision;
    
    private :

        void setWaitingForOrigami();
        void setObstacle();
        void setObstacle(int value);
        int getObstacle();   
        void controlOrigami();
        void controlLevel();
        void timeToDrawSolution();
    
        int currentTimeStatus;
        int status; //if status ==1 ok, if status==0 death, status ==2 level is finished 
        int obstacleNum;
        int origamiNum;
        int levelNumber = 1;
        int timeRecord;
    
        bool stopDrawingSkater;
        bool stopDrawingObstacle;
    
        Obstacle obstacle;
        Timer timer;
};

#endif

