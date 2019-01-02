#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../match_board.h"
#include "ofMain.h"
#include <vector>
using namespace std;

MatchBoard setUp() {
    ofImage test_image;
    test_image.load("picture/1.jpg");
    MatchBoard test;
    test.Load(test_image);
    
    return test;
}
//return 930217564
vector<int > setSequence() {
    vector<int > seq;
    seq.push_back(9);
    seq.push_back(3);
    seq.push_back(0);
    seq.push_back(2);
    seq.push_back(1);
    seq.push_back(7);
    seq.push_back(5);
    seq.push_back(6);
    seq.push_back(8);
    seq.push_back(4);
}

TEST_CASE("reset clean up everything" ) {
    MatchBoard board = setUp();
    ofImage board_image;
    board_image.load("picture/board.jpg");
    REQUIRE(board_image == board.GetBoard();
    board.reset();
    
    REQUIRE(board.status() == false);
}
        
TEST_CASE("FindSubsection work correctly") {
    MatchBoard board = setUp();

    int actual_1= FindSubsection(150, 800);
    REQUIRE(actual_1 == 6);
    int actual_2 = FindSubsection(300, 800);
    REQUIRE(actual_2 == 7);
    int actual_3 = FindSubsection(500, 800);
    REQUIRE(actual_3 == 8);
    int actual_4 = FindSubsection(160, 600);
    REQUIRE(actual_4 == 3);
    int actual_5 = FindSubsection(480, 550);
    REQUIRE(actual_5 == 5);
    int actual_6 = FindSubsection(150, 300);
    REQUIRE(actual == 0);
}

TEST_CASE("Test status return true when all pieces match") {
    MatchBoard board = setUp();
    vector<int > sequence = setSequence();
    board.LoadSegments(sequence);
    
    for(int i = 0; i <= 9; i++) {
        REQUIRE(board.status() == false);
        board.SetPosition(sequence[i] , i);
    }
    
    REQUIRE(board.status());
}
            
