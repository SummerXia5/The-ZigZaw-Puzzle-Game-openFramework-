#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../sound_player.h"
#include "ofMain.h"
#include <vector>
using namespace std;

TEST_CASE("Check playsound is playing") {
    SoundPlayer test;
    test.playSound("win");
    REQUIRE(test.win_.isPlaying());
    test.playSound("background");
    REQUIRE(test.background_.isPlaying());
    test.playSound("photo");
    REQUIRE(test.screen_shot_.isPlaying());
    test.playSound("match");
    REQUIRE(test.match_.isPlaying());
    test.playSound("error");
    REQUIRE(test.error_.isPlaying());
}



