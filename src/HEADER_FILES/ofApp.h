#pragma once
#include "ofxGUI.h"
#include "ofMain.h"
#include "ofxOsc.h"

#include "sound_player.h"
#include "image_folders.h"
#include "image_destroyer.h"
#include "match_board.h"
#include "remote_controller.h"

enum GameState {
    IN_SELECTION = 0,
    IN_GAME,
    SELECTED,
    GAME_RESULT,
    WIN
};


class ofApp : public ofBaseApp {
    private:
    
        //self-created object
        GameState current_state_;
        Controller controller_;
        SoundPlayer player;
        ImagesFolder source_;
        ImageDestroyer destroyer;
        MatchBoard board_;
    
        //variables
        int difficulty_;
        int choice_;
        int current_segment_;
        int frame_count_;
        float time_;
        string save_message_;
        ofImage game_board_;
        ofImage win_image_;
    
        pair<float, float> position_;
        ofVideoPlayer start_;
        ofTrueTypeFont* my_font_;
        ofTrueTypeFont* head_font_;
    
        vector<ofImage > segments;

    public:
        void setup();
    
    //functionality
        void screenShot();
        void restart();
    
    // The Following are for drawing
        void drawHeader();
        void drawLeftImage();
        void drawRightBoard();
        void drawSegment();
        void drawLabel(int i, ofVec2f dim);
        void draw();
        void drawNotification();
        void drawWin();
    
    // Following are for update
        void update();
        void controllerUpdate();
        void updateButtons();
        void updateSegmentOsc(int choice);
        void updateSelection();
        void updateStart();
        void updateDifficulty();
    
    //Interface Interaction
	void dragEvent(ofDragInfo dragInfo);

};
