#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ofMain.h"
#include "../image_destroyer.h"
#include <vector>
using namespace std;



ImageDestroyer setup() {
    ofImage testImage;
    testImage.load("picuture/1.jpg");
    ImageDestroyer test;
    test.Load(testImage);
    
    return test;
}

TEST_CASE("Test for Segment has correct size ","[weight=1]"){
    ImageDestroyer test = setup();
    test.Segment();
    vector<ofImage > origin = test.GetSegments();
    REQUIRE(origin.size() == 9);
}


TEST_CASE("Test for shuffle change the position ","[weight=1]"){
    ImageDestroyer test = setup();
    test.Segment();
    vector<ofImage > origin = test.GetSegments();
    test.shuffleSegment();
    REQUIRE(test.GetSegments() != origin);
    REQUIRE(test.GetSegments().size() == 9);
    
}

TEST_CASE("Test for reset cleans everything ","[weight=1]"){
    ImageDestroyer test = setup();
    test.Segment();
    vector<ofImage > origin = test.GetSegments();
    test.shuffleSegment();
    test.reset();
    REQUIRE(test.GetSegments.size() == 0);
}

TEST_CASE("Test for Update Pos Get its position") {
    ImageDestroyer test = setup();
    test.Segment();
    test.updatePos(0, 10, 10);
    ofVec2f actual(10, 10);
    REQUIRE(test.GetPos(0) == actual);
}
