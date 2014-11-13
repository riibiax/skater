#include <obstacle.h>


//--------------------------------------------------------------
void Obstacle::setup(){
    currentModel = 0;
    currentSolution = 0;
}

//--------------------------------------------------------------
void Obstacle::drawObstacle(){
    
    sequenceObstacle.getFrameForTime(ofGetElapsedTimef())->draw(ofGetWidth()/8, ofGetHeight()/4);
}


//--------------------------------------------------------------
void Obstacle::drawSolution(){
    
    sequenceSolution.getFrameForTime(ofGetElapsedTimef())->draw(ofGetWidth()/8, ofGetHeight()/4);
}

//--------------------------------------------------------------
void Obstacle::changeModel(int newModel){
    if (newModel == currentModel)
        return;
    
    sequenceObstacle.unloadSequence();
    currentModel = newModel;
    switch (currentModel) {
        case DOG:
            sequenceObstacle.loadSequence("dog/Frame-", "png", 1, 2, 2);
            break;
        case OLDLADY:
            sequenceObstacle.loadSequence("oldlady/Frame-", "png", 1, 3, 2);
            break;
        case CROWD:
            sequenceObstacle.loadSequence("crowd/Frame-", "png", 1, 4, 2);
            break;
        case WALL:
            sequenceObstacle.loadSequence("wall/Frame-", "png", 1, 13, 2);
            break;
        default:
            break;
    }
    sequenceObstacle.preloadAllFrames();
    sequenceObstacle.setFrameRate(30);
}

//--------------------------------------------------------------
void Obstacle::solution(int newModel){
    if (newModel == currentSolution)
        return;
    
    sequenceSolution.unloadSequence();
    currentSolution = newModel;
    switch (newModel) {
        case DOGCAT:
            sequenceSolution.loadSequence("cat/Frame-", "png", 1, 23, 2);
            break;
        case OLDLADYFLOWER:
            sequenceSolution.loadSequence("oldladyflower/Frame-", "png", 1, 12, 2);
            break;
        case CROWD:
            sequenceSolution.loadSequence("jumpcrown/Frame-", "png", 1, 49, 2);
            break;
        default:
            break;
    }
    sequenceSolution.preloadAllFrames();
    sequenceSolution.setFrameRate(10); 
}