#ifndef skater_timer_h
#define skater_timer_h


#include "ofMain.h"


class Timer{
    
    public:
    
        void setup();
        void update();
        void draw();
        int getTimeStatus();
        void setOrigamiTime();
        void resetOrigamiTime();
        void origamiUpdate();
        void stopSound();

    private:
    
        void drawSiren();
        void drawCountDown(int value);

        ofTrueTypeFont mFont;
    
        ofSoundPlayer mySound;
    
        int timerOrigami;
        int timeTemp;
        int timeStatus;
        int time[5];
    
        int timeOrigami;
        int timeTempOrigami;
        int countDownOrigami;
        int countDown;
    

};

#endif
