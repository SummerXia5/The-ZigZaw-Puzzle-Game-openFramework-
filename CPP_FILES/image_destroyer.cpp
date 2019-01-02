//
//  image_destroyer.cpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 11/6/18.
//

#include "image_destroyer.h"

ImageDestroyer::ImageDestroyer() {
    reset();
}

void ImageDestroyer::reset() {
    sequence_.clear();
    
    for(int i = 0; i< 9; i++) {
        sequence_.push_back(i);
    }
    
    num_of_segments = 9;
    window_width_ = ofGetWindowWidth() / 2;
    window_height_ = ofGetWindowHeight();
    frame_.load("board/819.jpg");
    
    segmented.clear();
    positions_.clear();
    width_ = 0;
    height_ = 0;
}

void ImageDestroyer::Load(ofImage image) {
    image_ = image;
    width_ = image_.getWidth() / 3;
    height_ = image_.getHeight() / 3 ;
    
    dist_x_ = uniform_int_distribution<>(0, window_width_ - width_);
    dist_y_ = uniform_int_distribution<>(0, window_height_ - height_);
    generator_ = mt19937(rand());
}

void ImageDestroyer::Segment() {

    int x = 0;
    int y = 0;
    int step = 0;
    
    for(int i = 0; i < num_of_segments; i++) {
        step++;
        ofImage each_segment;
        each_segment.cropFrom(image_, x, y, width_, height_);
        
        segmented.push_back(each_segment);
        x += width_;
        
        if(step == 3) {
            y += height_;
            x = 0;
            step = 0;
        }
    }
    SetPos();
}

void ImageDestroyer::DrawSelected(int selected, pair<float, float> pos) {
    selected --;
    ofVec2f frame_pos(pos.first - 5,pos.second- 5);
    ofVec2f image_pos(pos.first, pos.second);

    frame_.draw(frame_pos, segmented[selected].getWidth() + 10, segmented[selected].getHeight() + 10);
    segmented[selected].draw(image_pos);
}

void ImageDestroyer::SetPos() {
    for(int i = 0; i < num_of_segments; i++) {
        auto x = dist_x_(generator_);
        auto y = dist_y_(generator_);
        ofVec2f each;
        each.set(x, y);
        positions_.push_back(each);
    }
}

void ImageDestroyer::ScaleUp(int pos) {
    pos--;
    int newWidth = 1.5 * segmented[pos].getWidth();
    int newHeight = 1.5 * segmented[pos].getHeight();
    segmented[pos].resize(newWidth, newHeight);
}

void ImageDestroyer::ScaleDown(int pos) {
    pos--;
    int newWidth = segmented[pos].getWidth() / 1.5;
    int newHeight = segmented[pos].getHeight() / 1.5;
    segmented[pos].resize(newWidth, newHeight);
}

vector<ofImage > ImageDestroyer::GetSegments() {
    srand (unsigned(time(0)));
    random_shuffle(sequence_.begin(), sequence_.end());
    
    shuffleSegment();
    return segmented;
}

void ImageDestroyer::shuffleSegment() {
    vector<ofImage > temp;
    for(int i = 0; i < 9; i++) {
        temp.push_back(segmented[sequence_[i]]);
    }
    segmented = temp;
}

vector<int > ImageDestroyer::GetOrigin() {
    return sequence_;
}

ofVec2f ImageDestroyer::GetPos(int i) {
    return positions_[i];
}

void ImageDestroyer::updatePos(int i, int x_pos, int y_pos) {
    ofVec2f newPos(x_pos, y_pos);
    positions_[i] = newPos;
}

void ImageDestroyer::updatePos(int i, ofVec2f pos) {
    positions_[i] == pos;
}

                       
