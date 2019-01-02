#pragma once
#include "ofMain.h"
#include <stdio.h>
#include "ofxOsc.h"
#include "sound_player.h"
#define PORT 12345

using namespace std;

class Controller {
    public:
        bool screen_shot_;
        bool restart_;
        bool quit_;
        bool start_;
        bool select_;
        int difficulty_;
        float pick_;
    
        int currentChoice();
        Controller();
        void update();
        pair<float, float> segmentPosition();
        void reset();
        SoundPlayer player;
    
    private:
    
        int choice_;
        void updateDifficulty(ofxOscMessage m);
        void updateButtons(ofxOscMessage m);
        void updateChoice(ofxOscMessage m);
        void updateSegmentPosition(ofxOscMessage m);
        ofxOscReceiver receive;
        float oscX;
        float oscY;
};
