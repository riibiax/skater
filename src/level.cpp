#include <level.h>

//--------------------------------------------------------------
void Level::setup() {
    
    timer.setup();
    vision.setup();
    obstacle.setup();
    
    status = SKATER_RUN;
    currentTimeStatus = 1;
    timeRecord = 0;
    obstacleNum = 0;
    origamiNum = 0;
    
    stopDrawingObstacle = true;
    stopDrawingSkater = false;
}

//--------------------------------------------------------------
int Level::getStatus() {
    return status;
}

//--------------------------------------------------------------
int Level::getLevelNumber() {
    return levelNumber;
}

//--------------------------------------------------------------
int Level::getObstacle() {
    return obstacleNum;
}

//--------------------------------------------------------------
bool Level::getStopDrawingSkater() {
    return stopDrawingSkater;
}

//--------------------------------------------------------------
void Level::setObstacle() {
    obstacleNum = (int)ofRandom(1,4); 
}

//--------------------------------------------------------------
void Level::setObstacle(int value) {
    obstacleNum = value;
}

//--------------------------------------------------------------
void Level::increaseLevel() {
    levelNumber ++;
}

//--------------------------------------------------------------
void Level::update() {
    vision.update();
    
    timer.update();
    
    timer.origamiUpdate();
    
    if(vision.getFinalCard()){
        status = SKATER_WINS;
        timer.stopSound();
    }
    else if(timer.getTimeStatus()==6){
        status = SKATER_DEAD;
        stopDrawingSkater = false;
        stopDrawingObstacle = true;
        timer.stopSound();
    }
    else if (obstacleNum == 0)
        controlLevel();
    else if (obstacleNum!=0)
        controlOrigami();
}

//--------------------------------------------------------------
void Level::controlLevel() {
    
    int tempTimeStatus = timer.getTimeStatus();
    if (currentTimeStatus == tempTimeStatus)
        return;
    
    currentTimeStatus = tempTimeStatus;
    
    if (currentTimeStatus == 2 or currentTimeStatus == 3 or currentTimeStatus== 4){
        setObstacle();
        setWaitingForOrigami();
        timer.setOrigamiTime();
    }
}

//--------------------------------------------------------------
void Level::setWaitingForOrigami(){
    
    status = SKATER_BREAK;
    stopDrawingSkater = true;
    stopDrawingObstacle = false;
}

//--------------------------------------------------------------
void Level::controlOrigami(){
    
    origamiNum = vision.getOrigami(obstacleNum);
    
    if (origamiNum == obstacleNum){
        stopDrawingObstacle = true;
        status = SKATER_RUN;
        setObstacle(0);
        timeRecord = ofGetElapsedTimeMillis();
        timer.resetOrigamiTime();
    }
}

//--------------------------------------------------------------
void Level::draw() {
    
    vision.draw();
    
    if (status != SKATER_WINS)
        timer.draw();
    
    if (stopDrawingSkater){
        if(stopDrawingObstacle){
            timeToDrawSolution();
            obstacle.solution(origamiNum);
            obstacle.drawSolution();
        }
        else{
            obstacle.changeModel(obstacleNum);
            obstacle.drawObstacle();
        }

    }
}

//--------------------------------------------------------------
void Level::timeToDrawSolution(){
    
    int time = ofGetElapsedTimeMillis();
    
    if (time - timeRecord >4000){
        stopDrawingSkater = false;
        origamiNum = 0;
    }
}



