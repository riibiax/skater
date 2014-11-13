#include "timer.h"

//--------------------------------------------------------------
void Timer::setup(){
    
    timeTemp = ofGetElapsedTimeMillis();
    countDown = 0;
    timeStatus = 1;
    timeTempOrigami = 0;
    timerOrigami = 0;
    countDownOrigami = 10;
    timeOrigami = 10000;

    time[0] = 10000; //first obstacle
    time[1] = 25000; // second obstacle
    time[2] = 40000; //third obstacle
    time[3] = 55000; //ten seconds to reach the checkpoint
    time[4] = 65000; //end game
    
    mFont.loadFont("riot.ttf", 20);
	mFont.setLineHeight(18.0f);
	mFont.setLetterSpacing(1.037);

    mySound.loadSound("police.caf");
    mySound.setVolume(0.1f);
    mySound.setLoop(true);
    mySound.play();
}

//--------------------------------------------------------------
void Timer::update(){
    
    ofSoundUpdate();
    
    int timeRef = ofGetElapsedTimeMillis() -timeTemp;    
    
    if(timerOrigami == 0){
        if(timeRef >= time[0] and timeRef < time[1])
            timeStatus = 2; // first obstacle
        else if(timeRef >= time[1] and timeRef < time[2])
            timeStatus = 3; // danger status
        else if(timeRef >= time[2] and timeRef < time[3])
            timeStatus = 4; // danger status
        else if(timeRef >= time[3] and timeRef < time[4]){
            countDown = time[4] - timeRef;
            timeStatus = 5; // danger status
            mySound.setVolume(0.75f);
        }
        else if(timeRef >= time[4]){
            timeStatus = 6; // the skater is dead
            stopSound();
        }
        else
            timeStatus = 1;
    }
}

//--------------------------------------------------------------
void Timer::origamiUpdate(){
    
    if(timerOrigami != 0){
        
        timeTempOrigami = ofGetElapsedTimeMillis() -timerOrigami;
        countDownOrigami = timeOrigami-timeTempOrigami;
    
        if(timeTempOrigami >= timeOrigami)
        timeStatus = 6; // the skater is dead
    }
} 

//--------------------------------------------------------------
void Timer::setOrigamiTime(){
    timerOrigami = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void Timer::resetOrigamiTime(){
    timerOrigami = 0;
    countDownOrigami = 10;
    timeTempOrigami =0;
}

//--------------------------------------------------------------
void Timer::stopSound(){
    mySound.stop();
}

//--------------------------------------------------------------
int Timer::getTimeStatus(){
    return timeStatus;
}

//--------------------------------------------------------------
void Timer::draw(){
    if (timeStatus == 5){
        drawSiren();
        drawCountDown(countDown);
    }
    else if (timerOrigami!=0 and timeTempOrigami < timeOrigami)
        drawCountDown(countDownOrigami);
    else{
        ofSetColor(255, 255, 255);
        ofNoFill();
        ofRect(0, 0, 1, 1); 
    }
}

//--------------------------------------------------------------
void Timer::drawSiren(){
    
    ofSetColor((cos(ofGetElapsedTimef()*PI*2.0f)  + 1.5f)*255, 0, 0);
    ofNoFill();
    ofRect(0, 0, 1, 1);
}

//--------------------------------------------------------------
void Timer::drawCountDown(int value){
    
    string timerstring = ofToString(value/1000);
    
    ofPushMatrix();
        ofEnableAlphaBlending();
    
        ofRectangle bounds = mFont.getStringBoundingBox(timerstring, 0, 0);
    
        ofTranslate(10, ofGetHeight()-bounds.width-10, 0);
        ofRotate(-90);
    
        mFont.drawString(timerstring, -bounds.width/2, bounds.height/2 );
    
    ofPopMatrix();
}

