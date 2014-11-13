#ifndef skater_vision_h
#define skater_vision_h

//ON IPHONE NOTE INCLUDE THIS BEFORE ANYTHING ELSE
#include "ofxOpenCv.h"

#include "ofMain.h"

#define _USE_LIVE_VIDEO

class Vision {
    
    public:
        
        void setup();
        void update();
        void draw();
        vector<ofxCvBlob> getBlobs();
        int getOrigami(int obstacleNum);
        bool getFinalCard();
    
    private:
        
        void setCamera();
        void computerVision();
        void detection();
        void cardsDetection();
        void colorDetection();
        int origamiDetection();
        void checkHoles();
        int maxDepth(CvSeq * node);
        void countMark(CvSeq *node);
        void cardDetection(CvSeq *current);

        ofxCvContourFinder findColor(int colorDetected);
    
        ofVideoGrabber vidGrabber;
    
        int capW;
        int capH;
        int threshold;
        int colorOrigami;
        bool finalCard;
        int redHue, blueHue, greenHue;
        
        ofxCvColorImage	colorImg, hsb;
        ofxCvGrayscaleImage hue, sat, bri, filtered, gray_Image, grayDiff, grayBg;    
        ofxCvContourFinder contourRed, contourGreen, contourBlue, contourFinder;
    
        ofImage image;
};

#endif
