//
//  sound_player.hpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 12/4/18.
//

#pragma once
#include <stdio.h>
#include "ofMain.h"
#include <map>
class SoundPlayer{
    
    public:
        SoundPlayer();
        void playSound(string type);

    private:
        float background_volumn;
        float effect_volumn;
    
        map<string, ofSoundPlayer> sound_map;
        ofSoundPlayer win_;
        ofSoundPlayer background_;
        ofSoundPlayer screen_shot_;
        ofSoundPlayer match_;
        ofSoundPlayer error_;
        ofSoundPlayer restart_;
};
