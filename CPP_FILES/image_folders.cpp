//
//  image_folders.cpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 11/6/18.
//

#include "image_folders.h"

ImagesFolder::ImagesFolder(){
    my_font_.load("frabk.ttf", 20);
    background.load("pictures/background.jpg");
    for (int i = 1; i < 16; i++) {
        string path = "pictures/" + to_string(i) + ".jpg";
        ofImage each;
        each.load(path);
        source_images_.push_back(each);
        records_.push_back(-1);
    }
    LoadFromRecord();
}

void ImagesFolder::DrawImage(int choice) {
    int width = ofGetWindowWidth();
    int height = ofGetWindowHeight();
    int indent = 80;
    source_images_[choice].draw(indent, indent, width / 3, height * 2 / 3);
    DrawRecord(choice);
}




bool ImagesFolder::SetRecord(int image, float record) {
    if (records_[image] < 0) {
        records_[image] = record;
        return true;
    } else if(records_[image] >= record) {
        records_[image] = record;
        return true;
    }
    return false;
}

void ImagesFolder::DrawBackground() {
    background.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

void ImagesFolder::AddImage(string path) {
    ofImage new_image;
    new_image.load(path);
    source_images_.push_back(new_image);
    records_.push_back(-1);
}

void ImagesFolder::DrawNumbers(int i, ofVec2f pos) {
    pos += 10;
    numbers[i - 1].draw(pos,30,30);
}

void ImagesFolder::DrawRecord(int index) {
    float record =  records_[index];
    float x_pos = ofGetWindowWidth() / 5;
    float y_pos = ofGetWindowHeight()* 4 / 5;
    ofSetColor(0, 0, 0);
    if(record > 0) {
        string record_string = "Best Records: "+ to_string(record) + " seconds";
        my_font_.drawString(record_string , x_pos, y_pos);
    } else {
        my_font_.drawString("Haven't Completed Yet", x_pos, y_pos);
    }
}

void ImagesFolder::SaveRecord() {
    myTextFile.open("record.txt",ofFile::WriteOnly);
    for(int i = 1 ; i < 16 ; i++) {
        myTextFile << records_[i - 1] <<'\n';
    }
}

void ImagesFolder::LoadFromRecord() {
    vector <string > linesOfTheFile;
    ofBuffer buffer = ofBufferFromFile("record.txt");
    int i = 0;
    for (auto line : buffer.getLines()){
        records_[i] = std::stof(line);
        i++;
    }
}

ofImage ImagesFolder::GetIndexImage(int index) {
    return source_images_[index];
}

int ImagesFolder::Size() {
    return source_images_.size();
}
