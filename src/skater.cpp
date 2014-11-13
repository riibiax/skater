#include <skater.h>


//--------------------------------------------------------------
void Skater::setup(){
    currentAction = SKATER_RUN;
    sequence.loadSequence("skater_run/Frame-", "png", 1, 10, 2);
    sequence.preloadAllFrames();
    sequence.setFrameRate(10);
    
    /*model = new Model("astroBoy_walk.dae");
    model->position.x = ofGetWidth() / 2;
    model->position.y = ofGetHeight() / 2; */
}

//--------------------------------------------------------------
void Skater::update(int levelStatus){
    
    changeAction(levelStatus);
    
    //model->position = position;
    //model->update();
}

//--------------------------------------------------------------
void Skater::draw(){
    ofPushMatrix();
        ofEnableAlphaBlending();
        ofScale(0.7, 0.7);
        sequence.getFrameForTime(ofGetElapsedTimef())->draw(ofGetWidth()/3,ofGetHeight()/3 *2);
    ofPopMatrix();
    //  model->draw(xValue);
}

//--------------------------------------------------------------
void Skater::changeAction(int newAction){
    if (newAction == currentAction)
        return;
    
    sequence.unloadSequence();
    currentAction = newAction;
    switch (currentAction) {
        case SKATER_DEAD:
            sequence.loadSequence("dead/Frame-", "png", 1, 14, 2);
           // model->changeModel("astroBoy_walk.dae");
            break;
        case SKATER_RUN:
            sequence.loadSequence("skater_run/Frame-", "png", 1, 10, 2);
            break;
        case SKATER_WINS:
            sequence.loadSequence("skater_wins/Frame-", "png", 1, 13, 2);
            break;
        case SKATER_BREAK:
            sequence.loadSequence("break/Frame-", "png", 1, 9, 2);
            break;
        case SKATER_GRAVEL:
            sequence.loadSequence("gravel/Frame-", "png", 1, 9, 2);
            break;
        case SKATER_OIL:
            sequence.loadSequence("oil/Frame-", "png", 1, 10, 2);
            break;
        default:
            break;
    }
    sequence.preloadAllFrames();
    sequence.setFrameRate(10);
}