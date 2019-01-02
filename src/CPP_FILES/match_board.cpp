//
//  match_board.cpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 11/13/18.
//

#include "match_board.h"

MatchBoard::MatchBoard() {
    frame_.load("board/819.jpg");
    board_.load("board/board.jpg");

    reset();
}

ofImage MatchBoard::GetBoard() {
    return board_;
}

void MatchBoard::LoadSegments(vector<int >segments) {
    segments_ = segments;
}

void MatchBoard::SetPosition(int segment, int position) {
    actual_[segment] = position;
}

bool MatchBoard::status() {
    for(int i = 0; i< 9; i++ ) {
        if(segments_[i] != actual_[i]) {
            return false;
        }
    }
    return true;    
}

void MatchBoard::Load(ofImage image){
    game_image_ = image;
    int x = INDENT+ ofGetWindowWidth() / 2;
    int x_origin = x;
    int y = INDENT;
    int x_increment = ofGetWindowWidth() / 9;
    int y_increment = ofGetWindowHeight() * 2 / 9;
    int step = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            pair<int, int> pos(x, y);
            segments_pos_.push_back(pos);
            x += x_increment;
        }
        x = x_origin;
        y += y_increment;
    }
}

pair<int, int> MatchBoard::GetPos(int pos) {
    return segments_pos_[pos];
}

void MatchBoard::reset() {
    segments_pos_.clear();
    actual_.clear();
    for(int i = 0; i < 9; i++) {
        actual_.push_back(-1);
    }
}

void MatchBoard::Draw(int difficulty) {
    int width = ofGetWindowWidth();
    int height = ofGetWindowHeight();
    frame_.draw(INDENT + width / 2 - 5, INDENT - 5 , width / 3 + 10, height * 2 / 3 + 10);
    if(difficulty != NONE) {
        
        if(difficulty == BOTH || difficulty == GRID) {
            board_.draw(INDENT + width / 2, INDENT, width / 3, height * 2 / 3);
        }
        
        if(difficulty == BOTH || difficulty == PICTURE) {
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,100);
            game_image_.draw(INDENT + width / 2, INDENT);
            ofDisableAlphaBlending();
        }
    }
}

int MatchBoard::FindSubsection(int x, int y) {
    int seg_width_ =(int) game_image_.getWidth() / 3;
    int seg_height = (int) game_image_.getHeight() / 3;
    
    int max_width = segments_pos_[2].first + seg_width_;
    int max_height = segments_pos_[8].second + seg_height;
    if(x > max_width || y > max_height) return -1;
    if(x < segments_pos_[0].first || y < segments_pos_[0].second) return -1;
    
    int real_x = 0;
    int real_y = 0;
    for(int i = 0; i < 3; i++) {
        if(x >= segments_pos_[i].first) {
            real_x = i;
        }
    }
    int h_pos = 0;
    for(int i = 0; i < 3; i++) {
        if(y >= segments_pos_[h_pos].second) {
            real_y = i;
        }
        h_pos += 3;
    }

    return 3 * real_y + real_x;
}

