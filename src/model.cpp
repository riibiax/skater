#include "model.h"

Model::Model(string modelpath){
    if(modelpath=="")
        return;
    
    ofSetLogLevel(OF_LOG_VERBOSE);
	
    // we need GL_TEXTURE_2D for our models coords.
    ofDisableArbTex();
    
    if(assimpmodel.loadModel(modelpath, true)){
    	assimpmodel.setAnimation(0);
    	assimpmodel.setPosition(ofGetWidth() / 2, ofGetWidth() / 2 , 0);
        assimpmodel.setRotation(0,90, 1, 0, 0);
    	//model.createLightsFromAiModel();
    	//model.disableTextures();
    	//model.disableMaterials();
        
    	mesh = assimpmodel.getMesh(0);
    	position = assimpmodel.getPosition();
    	normScale = assimpmodel.getNormalizedScale();
    	scale = assimpmodel.getScale();
    	sceneCenter = assimpmodel.getSceneCenter();
    	material = assimpmodel.getMaterialForMesh(0);
        tex = assimpmodel.getTextureForMesh(0);
    }
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    //some model / light stuff
    glShadeModel(GL_SMOOTH);
    light.enable();
    ofEnableSeparateSpecularLight();
    
	bAnimate = true;
	animationTime = 0.0;
}

//--------------------------------------------------------------
void Model::update(){
    
	//this is for animation if the model has it.
	if( bAnimate ){
		animationTime += ofGetLastFrameTime();
		if(animationTime >= 1.0){
            animationTime = 0.0;
		}
	    assimpmodel.setNormalizedTime(animationTime);
		mesh = assimpmodel.getCurrentAnimatedMesh(0);
	}
    
    //test
    assimpmodel.setPosition(position.x, position.y, assimpmodel.getPosition().z);
    //test
}

//--------------------------------------------------------------
void Model::draw(float xValue){

    ofTranslate(assimpmodel.getPosition().x, assimpmodel.getPosition().y, 0);
    ofRotate(-xValue*100, 0, 1, 0);
    ofTranslate(-assimpmodel.getPosition().x, -assimpmodel.getPosition().y, 0);
    
    assimpmodel.drawFaces();
    
}

//--------------------------------------------------------------
void Model::changeModel(string modelpath){
    assimpmodel.loadModel(modelpath);
}