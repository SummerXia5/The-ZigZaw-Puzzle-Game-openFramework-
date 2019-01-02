//
//  sound_player.cpp
//  finalproject-SummerXia5
//
//  Created by tianrui xia on 12/4/18.
//

#include "sound_player.h"

SoundPlayer::SoundPlayer() {
    win_.load("sound/win.mp3");
    screen_shot_.load("sound/photo.mp3");
    match_.load("sound/match.mp3");
    error_.load("sound/error.mp3");
    restart_.load("sound/restart.mp3");
    background_.load("sound/background.mp3");
    
    sound_map["background"] = background_;
    sound_map["win"] = win_;
    sound_map["screen"] = screen_shot_;
    sound_map["match"] = match_;
    sound_map["error"] = error_;
    sound_map["restart"] = restart_;
}

void SoundPlayer::playSound(string type) {
    if(!sound_map[type].isPlaying()) {
        sound_map[type].play();
    }
}

