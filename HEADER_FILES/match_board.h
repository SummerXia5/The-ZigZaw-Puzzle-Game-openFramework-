//
//  match_board.hpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 11/13/18.
//
#pragma once
#include "ofMain.h"
#include <stdio.h>

const int INDENT = 80;
const int GRID = 0;
const int PICTURE = 1;
const int BOTH = 2;
const int NONE = 3;

class MatchBoard {
    
    private:
        ofImage frame_;
        vector<pair<int,int> >segments_pos_;
    
        vector<int> segments_;
        vector<int> actual_;
    
        ofImage board_;
        ofImage game_image_;
            
    public:
    
        void reset();
        MatchBoard();
        void Load(ofImage image);
        void LoadSegments(vector<int > segments);
        void SetPosition(int segment, int position);
    
        bool status();
        void Draw(int difficulty);
        ofImage GetBoard();
    
        int FindSubsection(int x, int y);
        pair<int, int> GetPos(int pos);
};


