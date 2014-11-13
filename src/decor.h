#ifndef skater_decor_h
#define skater_decor_h

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxOpenCv.h"

class Decor {
    
    public:
        void setup();
        void draw(vector<ofxCvBlob> blobs, float xValue);
    
    private:
    
        bool bAnimate;
        float animationTime;
        ofxAssimpModelLoader model1, model2;
    
        ofVboMesh mesh1, mesh2;
        ofPoint position1, position2;
        float normScale1, normScale2;
        ofPoint scale1, scale2;
        ofPoint sceneCenter1, sceneCenter2;
        ofMaterial material1, material2;
        ofTexture tex1, tex2, tex3, tex4, tex5, tex6;
};

#endif