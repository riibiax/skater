#include "vision.h"

//--------------------------------------------------------------
void Vision::setup(){    
    // Hue of some colors 
    redHue = 33;
    blueHue = 95;
    greenHue = 50;
    
    setCamera();
    
    finalCard =false;
}

//--------------------------------------------------------------
void Vision::setCamera(){
    
    threshold = 50;
    
    vidGrabber.initGrabber(320, 240);
    capW = vidGrabber.getWidth();
    capH = vidGrabber.getHeight();
    
    colorImg.allocate(capW,capH);
    gray_Image.allocate(capW,capH);
    hsb.allocate(capW, capH);
    hue.allocate(capW, capH);
    sat.allocate(capW, capH);
    bri.allocate(capW, capH);
    filtered.allocate(capW, capH);
    
    ofSetFrameRate(20);
    
    image.loadImage("white.png");
}

//--------------------------------------------------------------
vector<ofxCvBlob> Vision::getBlobs(){    
    return contourFinder.blobs;
}

//--------------------------------------------------------------
void Vision::update(){
    computerVision();
}

//--------------------------------------------------------------
void Vision::computerVision(){
    
    bool bNewFrame = false;
    
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    
	if (bNewFrame){
        
        if( vidGrabber.getPixels() != NULL ){
            
            colorImg.setFromPixels(vidGrabber.getPixels(), capW, capH);
            
            detection();
            
		}
	} 
}

//--------------------------------------------------------------
int Vision::getOrigami(int obstacleNum){	
    hsb = colorImg;               //now we stuff the colorImg into our HSB image
    hsb.convertRgbToHsv();        //now we convert the colorImg inside colorImgHSV into HSV
    
    hsb.convertToGrayscalePlanarImages(hue, sat, bri); //distribute the hue, saturation and brightness to hueImg, satImg,
    
    colorOrigami = obstacleNum;
    
    switch (colorOrigami) {
        case 1:
            contourBlue = findColor(blueHue);
            break;
        case 2:
            contourRed = findColor(redHue);
            break;
        case 3:
            contourGreen = findColor(greenHue);
            break;
        default:
            break;
    }
    
    return origamiDetection();
}

//--------------------------------------------------------------
ofxCvContourFinder Vision::findColor(int colorDetected){	
    ofxCvContourFinder contours;
    //filter image based on the hue value were looking for
    for (int i=0; i<capW*capH; i++) {
        filtered.getPixels()[i] = ofInRange(hue.getPixels()[i], colorDetected-7, colorDetected+7) ? 255 : 0;
    }
    
    filtered.flagImageChanged();
    //run the contour finder on the filtered image to find blobs with a certain hue
    contours.findContours(filtered,  (capW*capH)/20, (capW*capH), 1, false);
    
    return contours;
}

//--------------------------------------------------------------
int Vision::origamiDetection(){
    if(contourBlue.nBlobs > 0) {       
        // Reset
        contourBlue.nBlobs = 0;
        return 1;
    }
    else if(contourRed.nBlobs > 0) { 
        // Reset
        contourRed.nBlobs = 0;
        return 2;
    }
    else if(contourGreen.nBlobs > 0) {       
        // Reset
        contourGreen.nBlobs = 0;
        return 3;
    }
    else{
        return 0;
    }
} 

//--------------------------------------------------------------
void Vision::detection(){
	
    gray_Image = colorImg;
    grayBg.setFromPixels(image.getPixels(), capW, capH);
    gray_Image.threshold(90);
    grayDiff.absDiff(grayBg, gray_Image);
    grayDiff.threshold(threshold);
    
    cardsDetection(); 
}

//--------------------------------------------------------------
void Vision::cardsDetection(){
        
    contourFinder.findContours(grayDiff, 10, (capW*capH)/10, 7, true);	// find holes
    
    checkHoles();
}

//--------------------------------------------------------------
void Vision::checkHoles(){ //Duplicate the 1st part of findContour in ofxCvContourFinder Class
    // get width/height disregarding ROI
    ofxCvGrayscaleImage input = grayDiff;
    IplImage* ipltemp = input.getCvImage();
    
    int  _width;
    int  _height;
    
    _width = ipltemp->width;
    _height = ipltemp->height;
    
    ofxCvGrayscaleImage     inputCopy;
    inputCopy.setUseTexture(false);
	if( inputCopy.getWidth() == 0 ) {
		inputCopy.allocate( _width, _height );
	} else if( inputCopy.getWidth() != _width || inputCopy.getHeight() != _height ) {
        // reallocate to new size
        inputCopy.clear();
        inputCopy.allocate( _width, _height );
	}
    
    inputCopy.setROI( input.getROI() );
    inputCopy = input;
    
	CvSeq* contour_list = NULL;
	CvMemStorage* contour_storage = cvCreateMemStorage(1000);
    
	cvFindContours( inputCopy.getCvImage(), contour_storage, &contour_list,
                   sizeof(CvContour), CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
    
    
    //-----------------------------------//
    cardDetection(contour_list);
    //-----------------------------------//
    
	// Free the storage memory.
	// Warning: do this inside this function otherwise a strange memory leak
	if( contour_storage != NULL ) { cvReleaseMemStorage(&contour_storage); }    
}

//--------------------------------------------------------------
void Vision::cardDetection(CvSeq *current){

    finalCard = false;

    while (current) {
        countMark(current);
        current = current->h_next;
    }
}

//--------------------------------------------------------------
void Vision::countMark(CvSeq * node){
    
    int fivecounter = 0;
    
    if(node && node->v_next){
        node = node->v_next;
        
        while (node) {
            if (maxDepth(node) > 4) 
                fivecounter++;
            node = node->h_next;
        }
    }
    if (fivecounter >0) 
        finalCard = true;
}

//--------------------------------------------------------------
int Vision::maxDepth(CvSeq * node){
    int maxlocal = 0;
    CvSeq * current = node->v_next;
    if(current){
        while (current) {
            
            int m = maxDepth(current);
            if(m > maxlocal)
                maxlocal = m;
            current = current->h_next;
        }
        return maxlocal+1;
    }
    else return 0;
}

//--------------------------------------------------------------
bool Vision::getFinalCard(){
    return finalCard;
}

//--------------------------------------------------------------
void Vision::draw(){	
    
    colorImg.draw(0, 0);
    
    /*ofSetHexColor(0xffffff);
    for (int i = 0; i < contourFinder.nBlobs; i++){
        contourFinder.blobs[i].draw(0, 0);
     }    
    char reportStr[1024];
    sprintf(reportStr, "Status %d\n Obstacle%i\n", level.getStatus(), level.getCurrentObstacle());
    ofDrawBitmapString(reportStr, 4, 380); */
} 
