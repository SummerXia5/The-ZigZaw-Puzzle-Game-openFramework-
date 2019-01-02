//
//  socialmediasharing.cpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 11/30/18.
//

#include "remote_controller.h"

Controller::Controller() {
    receive.setup(PORT);
    reset();
}

int Controller::currentChoice() {
    return choice_;
}

void Controller::updateButtons(ofxOscMessage m) {
    if(m.getAddress() == "/restart/1") {
        if(m.getArgAsInt(0) == 1) {
            restart_ = true;
        }
    }
    
    if(m.getAddress() == "/end/1") {
        if(m.getArgAsInt(0) == 1) {
            quit_ = true;
        }
    }
    
    if(m.getAddress() == "/photo/1") {
        if(m.getArgAsInt(0) == 1) {
            screen_shot_ = true;
        }
    }
  
    if(m.getAddress() == "/start/1") {
        if(m.getArgAsInt(0) == 1) {
            start_ = true;
        }
    }
    
    if(m.getAddress() == "/slider/1") {
        pick_ = m.getArgAsDouble(0);
    }
    
    if(m.getAddress() == "/select/1") {
       if(m.getArgAsInt(0) == 1) {
           select_ = true;
       }
    }
}

void Controller::updateSegmentPosition(ofxOscMessage m) {
    if(m.getAddress() == "/drag/x") {
        float x = m.getArgAsFloat(0);
        oscX = x * ofGetWindowWidth();
    }
    
    if(m.getAddress() == "/drag/y") {
        float y = m.getArgAsFloat(0);
        oscY = - y * ofGetWindowHeight() + ofGetWindowHeight();
    }
}

void Controller::updateDifficulty(ofxOscMessage m) {
    if(m.getAddress() == "/menu/difficulty") {
        difficulty_ = m.getArgAsInt(0);
    }
}

void Controller::updateChoice(ofxOscMessage m) {
    for(int i = 1 ; i < 10; i++) {
        string address = "/choice/" + to_string(i);
        if(m.getAddress() == address) {
            if(choice_ != i) {
                choice_ = i;
            }
        }
    }
    if(m.getAddress() == "/choice/place") {
        choice_ = -1;
    }
}

pair<float, float> Controller::segmentPosition() {
    return pair<float,float>(oscX, oscY);
}

void Controller::update(){
    while (receive.hasWaitingMessages()) {
        ofxOscMessage m;
        receive.getNextMessage(&m);
       
        updateSegmentPosition(m);
        updateChoice(m);
        updateButtons(m);
        updateDifficulty(m);
    }
}

void Controller::reset() {
    choice_ = -1;
    restart_ = false;
    screen_shot_ = false;
    quit_ = false;
    difficulty_ = 1;
    select_ = false;
}


