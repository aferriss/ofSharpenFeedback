#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("images/ss.png");
    
    w = img.getWidth();
    h = img.getHeight();
    
    ofSetWindowShape(w, h);
    
    fbo.allocate(w, h, GL_RGB);
    
    sharpenShader.load("shaders/sharpen");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(save){
        ofSaveImage(img.getPixels(), "saved/"+ofGetTimestampString()+".png");
        save = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
        sharpenShader.begin();
            sharpenShader.setUniformTexture("src_tex_unit0", img.getTexture(), 0);
                img.draw(0,0);
        sharpenShader.end();
    fbo.end();
    
    ofPixels fboPix;
    fbo.readToPixels(fboPix);
    img.setFromPixels(fboPix);
    
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        save = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
