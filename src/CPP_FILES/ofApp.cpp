#include "ofApp.h"

void ofApp::setup() {
    my_font_ = new ofTrueTypeFont();
    my_font_->load("frabk.ttf", 15);
    head_font_ = new ofTrueTypeFont();
    head_font_ ->load("snow.ttf", 30);
 
    win_image_.load("pictures/win_background.png");
    
    current_segment_ = -1;
    current_state_ = IN_SELECTION;
    frame_count_ = 0;
    save_message_ = "Screenshot is saved as ";
    choice_ = 1;
    
    start_.load("start.mp4");
    start_.play();
}

void ofApp::update() {
    controller_.update();
    if(ofGetFrameNum() <= 360) {
        start_.update();
    }
    if(current_state_==IN_GAME) {
        if(current_segment_!= -1) {
            position_ = controller_.segmentPosition();
        }
        int new_choice = controller_.currentChoice();
        if(new_choice != current_segment_) {
            updateSegmentOsc(new_choice);
        }
    }
    player.playSound("background");
    updateButtons();
    updateSelection();
    updateStart();
}

void ofApp::updateStart() {
    if(controller_.start_) {
        if(current_state_ == SELECTED) {
            ofResetElapsedTimeCounter();
            current_state_ = IN_GAME;
            destroyer.Load(game_board_);
            destroyer.Segment();
            segments = destroyer.GetSegments();
            vector<int > original = destroyer.GetOrigin();
            board_.LoadSegments(original);
        }
        
        controller_.start_ = false;
    }
}

void ofApp::updateSelection() {
    if(current_state_!= IN_GAME) {
        if(controller_.select_) {
            controller_.select_ = false;
        
            if(current_state_ == SELECTED){
                current_state_ = IN_SELECTION;
            } else if(current_state_ == IN_SELECTION) {
                
                current_state_ = SELECTED;
                game_board_ = source_.GetIndexImage(choice_ - 1);
                game_board_.resize(ofGetWindowWidth() / 3, ofGetWindowHeight() * 2 / 3);
                board_.Load(game_board_);
            }
        }
    }
}

void ofApp::updateButtons() {
    if(current_state_ == IN_SELECTION) {
        choice_ = (int)(controller_.pick_ * source_.Size());
        choice_ = (choice_ == 0)? 1 : choice_;
    }
    if(controller_.restart_) {
        controller_.restart_ = false;
        restart();
    }
    if(controller_.screen_shot_) {
        controller_.screen_shot_ = false;
        screenShot();
    }
    if(controller_.quit_) {
        source_.SaveRecord();
        ofExit();
    }
    
    difficulty_ =  controller_.difficulty_;
}

void ofApp::screenShot() {
    string time = to_string(ofGetMonth()) + '-' + to_string(ofGetDay());
    time += '-'+to_string(ofGetHours()) + "." + to_string(ofGetMinutes()) + ".jpg";
    ofImage screen;
    
    screen.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    player.playSound("screen");
    save_message_ += time;
    frame_count_ = 100;
    screen.save(time);
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(255, 255, 255);
    source_.DrawBackground();
    if((int)ofGetFrameNum() <= 360) {
        start_.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    } else {
        drawHeader();
        drawLeftImage();
        
        if(current_state_ == IN_GAME || current_state_ == WIN) {
            drawSegment();
        }
        drawNotification();
        if (current_state_ == WIN) {
            drawWin();
        }
    }
}

void ofApp::drawWin() {
    ofEnableAlphaBlending();
    win_image_.draw(ofGetWindowWidth() / 18, ofGetWindowHeight() / 7);
    ofSetColor(0, 0, 0);
    
    head_font_ ->drawString("You Win!", ofGetWindowWidth() / 5, ofGetWindowHeight() / 3);
    my_font_ -> drawString("You finished in " + to_string(time_) + " second!", ofGetWindowWidth() / 5, ofGetWindowHeight()* 3 / 5 );
    ofSetColor(255, 255, 255);
}

void ofApp::drawNotification() {
    if(frame_count_ > 0) {
        if(frame_count_ != 1) {
            ofSetColor(150, 150, 150, 150);
            ofDrawRectangle(ofGetWindowWidth() / 2 - 160, ofGetWindowHeight() * 2 / 3 - 30, 380, 50);
            ofSetColor(0, 0, 0);
            my_font_->drawString(save_message_, ofGetWindowWidth() / 2 - 130, ofGetWindowHeight() * 2 / 3);
            ofSetColor(255, 255, 255);
        } else {
            save_message_ = "Screenshot is saved as ";
        }
        frame_count_--;
    }
}

void ofApp::drawHeader() {
    int width = ofGetWindowWidth();
    int height = ofGetWindowHeight();
    string head = "Image Zigsaw Puzzle";
    
    ofSetColor(0,0,0);
    head_font_->drawString(head, width / 2 - 210, 50);
    ofSetColor(255, 255, 255);
}

void ofApp::drawLeftImage() {
    
    if (current_state_ == IN_SELECTION) {
        source_.DrawImage(choice_ - 1);
    } else {
        board_.Draw(difficulty_);
    }
}

void ofApp::drawSegment() {
    ofSetColor(ofColor::white);
    
    for(int i = 0; i < segments.size(); i++) {
        if(i + 1 != current_segment_) {
            ofVec2f dim = destroyer.GetPos(i);
            segments[i].draw(dim);
            drawLabel(i + 1, dim);
        }
    }
    if(current_segment_ != -1) {
        destroyer.DrawSelected(current_segment_, position_);
    }
}

void ofApp::drawLabel(int i, ofVec2f dim) {
    int x_increment = segments[0].getWidth() / 2;
    ofEnableAlphaBlending();
    dim += (x_increment);
    ofDrawCircle(dim, 20);

    ofSetColor(0, 0, 0, 100);
    dim -= 4;
    ofDrawBitmapString(to_string(i), dim);
    ofSetColor(255, 255, 255, 100);

    ofDisableAlphaBlending();
}

void ofApp::restart() {
    current_segment_ = -1;
    current_state_ = IN_SELECTION;

    frame_count_ = 0;
    destroyer.reset();
    board_.reset();
    controller_.reset();
}

void ofApp::updateSegmentOsc(int choice) {
    if(current_segment_ != -1) {
        int new_x = position_.first;
        int new_y = position_.second;
        destroyer.updatePos(choice - 1, new_x, new_y);
        int i = board_.FindSubsection(new_x, new_y);
       
        if(i != -1) {
            pair<int, int> position = board_.GetPos(i);
            destroyer.updatePos(current_segment_ - 1, position.first, position.second);
            // match board need update as well
            board_.SetPosition(current_segment_ - 1, i);
           
            if(board_.status()) {
                float time = ofGetElapsedTimef();
                current_state_ = WIN;
                player.playSound("win");
                time_ = time;
                source_.SetRecord(choice_ - 1, time_);
            } else {
                player.playSound("match");
            }
        }
    }
    if(current_segment_ != choice && choice != -1) {
        if(current_segment_ != -1) destroyer.ScaleDown(current_segment_);
        destroyer.ScaleUp(choice);
        current_segment_ = choice;
    } else {
        destroyer.ScaleDown(current_segment_);
        current_segment_ = -1;
    }
}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    if(!dragInfo.files.empty()) {
        source_.AddImage(dragInfo.files[0]);
        choice_ = 1;
    }
}
