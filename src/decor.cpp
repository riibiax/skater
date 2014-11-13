#include <decor.h>

//--------------------------------------------------------------
void Decor::setup() {
    // Load models for texture-background
    if(model1.loadModel("bb.dae", true)){ //Model: square top (buildings)
    	model1.setAnimation(0);
    	model1.setPosition(0, 0, 0);
        model1.setRotation(0,0, 0, 0, 0);
    	//model.createLightsFromAiModel();
    	//model.disableTextures();
    	//model.disableMaterials();
        
    	mesh1 = model1.getMesh(0);
    	position1 = model1.getPosition();
    	normScale1 = model1.getNormalizedScale();
    	scale1 = model1.getScale();
    	sceneCenter1 = model1.getSceneCenter();
    	material1 = model1.getMaterialForMesh(0);
        tex1 = model1.getTextureForMesh(0);
    }
    if(model2.loadModel("bl.dae", true)){ //Model : square bottom (park)
    	model2.setAnimation(0);
    	model2.setPosition(0, 0, 0);
        model2.setRotation(0,0, 0, 0, 0);
        model2.setScale(0.5,0.5,0.5);
    	//model.createLightsFromAiModel();
    	//model.disableTextures();
    	//model.disableMaterials();
        
    	mesh2 = model2.getMesh(0);
    	position2 = model2.getPosition();
    	normScale2 = model2.getNormalizedScale();
    	scale2 = model2.getScale();
    	sceneCenter2 = model2.getSceneCenter();
    	material2 = model2.getMaterialForMesh(0);
        tex2 = model2.getTextureForMesh(0);
    }

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    glShadeModel(GL_SMOOTH);
}

//--------------------------------------------------------------
void Decor::draw(vector<ofxCvBlob> blobs, float xValue) {
    vector <ofPoint>    pts;
    int                 nPts;
    float x, y;
    for (int i = 0; i < blobs.size(); i++){
        pts = blobs[i].pts;    // the contour of the blob
        nPts = blobs[i].nPts;   // number of pts;
        for (int t = 0; t < nPts and t<10; t++){
            x = pts[t].x;
            y= pts[t].y;

            if (x<ofGetWidth()/3){
                    ofPushMatrix();
                        model1.setPosition(x-180, y-40, 0);
                        ofTranslate(model1.getPosition().x, model1.getPosition().y, 0);
                        ofRotate(-xValue * 100, 0, 1, 0);
                        ofTranslate(-model1.getPosition().x, -model1.getPosition().y, 0);
                        model1.drawFaces();
                    ofPopMatrix();
                }
                else if (x>ofGetWidth()/3*2) {
                    ofPushMatrix();
                        model2.setPosition(x-70, y-60, 0);
                        ofTranslate(model2.getPosition().x, model2.getPosition().y, 0);
                        ofRotate(-xValue * 100, 0, 1, 0);
                        ofTranslate(-model2.getPosition().x, -model2.getPosition().y, 0);
                        model2.drawFaces();
                    ofPopMatrix();
                }
        }
    }
}

