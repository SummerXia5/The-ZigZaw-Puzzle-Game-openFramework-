#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../image_folder.h"
#include <vector>
#include "ofMain.h"
using namespace std;

TEST_CASE("Test for LoadRecord Does its job","[weight=1]"){
    ImageFolder test;
    REQUIRE(test.records_[0] == -1);
    REQUIRE(test.records_[5] == 23.5868);
}


TEST_CASE("Test that set record would save after reopen ") {
    ImageFolder test;
    test.SetRecord(0, 3.5);
    test.SaveRecord();
    
    ImageFolder newOne;
    REQUIRE(newOne.records_[0] == 3.5);
}

TEST_CASE("Test get correct image" ) {
    ofImage first;
    first.Load("1.jpg");
    ImageFolder folder;
    ofImage actual = folder.GetIndexImage(0);
    REQUIRE(first == actual);
}
