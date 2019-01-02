//
//  image_folders.hpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 11/6/18.
//

#pragma once

#include "ofMain.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class ImagesFolder {
    
    private:
        ofImage background;
        vector<ofImage> numbers;
        vector<ofImage> source_images_;
        vector<float > records_;
        ofTrueTypeFont my_font_;
        ofFile myTextFile;
    
    public:
    
        ImagesFolder();
        void SaveRecord();
        void LoadFromRecord();
        bool SetRecord(int image, float record);
        void AddImage(string path);
        void DrawNumbers(int i, ofVec2f pos);
        void DrawRecord(int index);
        void DrawImage(int choice);
        ofImage GetIndexImage(int index);
        void DrawBackground();
    
        int Size();
};

