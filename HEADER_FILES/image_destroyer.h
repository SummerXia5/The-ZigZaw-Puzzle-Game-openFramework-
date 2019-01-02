//
//  image_destroyer.hpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 11/6/18.
//

#include "ofMain.h"
#include <stdio.h>
#include <vector>
#include <random>

using namespace std;


class ImageDestroyer{
    
    private:
        vector<ofImage > segmented;
        vector<ofImage > labels_;
        vector<ofVec2f > positions_;
        vector<int > sequence_;
        int num_of_segments;
        ofImage image_;
        ofImage frame_;
    
        mt19937 generator_;
        uniform_int_distribution<> dist_x_;
        uniform_int_distribution<> dist_y_;
    
        int window_height_;
        int window_width_;
        int width_;
        int height_;
  
    public:
    
        void reset();
        vector<int > GetOrigin();
        void SetPos();
        ImageDestroyer();
        void ScaleUp(int pos);
        void ScaleDown(int pos);
        void DrawSelected(int selected, pair<float, float> pos);
        ofVec2f GetPos(int i);
        void Load(ofImage image);
        void Segment();
        vector<ofImage > GetSegments();
        void RandomDraw();
        void updatePos(int i, int x_pos, int y_pos);
        void updatePos(int i, ofVec2f pos);
        void shuffleSegment();
};
