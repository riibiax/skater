#ifndef skater_model_h
#define skater_model_h

#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"

class Model{
    
    public:
    
        Model(string);
    //void setup();
        void update();
        void draw(float xValue);
        void changeModel(string);
    
        bool bAnimate;
        float animationTime;
        ofxAssimpModelLoader assimpmodel;
    
        ofVboMesh mesh;
        ofPoint position;
        float normScale;
        ofPoint scale;
        ofPoint sceneCenter;
        ofMaterial material;
        ofTexture tex;
        ofLight	light;
};

#endif
