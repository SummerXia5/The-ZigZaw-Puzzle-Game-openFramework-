# Image Jigsaw Puzzle Development Log

## Implementation

##### Final Modification
* Checked All white spaces.
* wiped off functions that is unnessasry 
* Rearraged all files created Headers' folder and CPP's folders 
* FInished Development Log.
* Added test cases for those classes that have logic algorithmns including matchboard, soundplayer, destroyer, and image folders. 

##### December 11th 
* Trying to implemented Sound Controller
* Added several sound feature for buttons 
* Removed any potential white spaces.

##### December 9th
* Implemented a different background music and made it constantly playing
* changed naming of variables.
* erased unnessasary functions.


##### December 7th 
* implmented current high score and implented timing for each of round of the game.
* implemnted records saver and loader so that closing the game would not erase the data since it can read from records.txt file and save when exit.
* Implemented Starting Animations.

##### December 6th
* Implemented Match board win status. Each time the player could matched up with the image, it would switch to win state.
* Tried different algorithmn starting with comparing the ofimges segments itself and realize the == operator is not overwritten for that one. 
* using random shuffle for the sequence of position and change the segments vector to corresponding sequence and send the sequence to match board to determine if the player matches correctly. / struggled for fair amount of time / 
* Yeah added images for win.

##### December 5th
* implemented difficulty for the so you can select No grid / No picutre/ Nothing / have both
* added soundplayer class to play sound when match, finish, game over, win and screenshot.
* given screen shot a specific name corresponding to its data, and time.

##### December 4th
###### Today is the day of progress ######
* layout lemur a multiple ( imagined to use that with moving the selected segment)
* implemented number 1- 9 to select corresponding segments. 
* realize that 1 - 9 update would take too much memory and consider give up on that implementation 
* implemented moving segments around with ipad remotely
* implemented restart, screenshot, quit from ipad.
* Found a way to solve the problems of 1-9 selection by giving it a one time boolean and change it back to false so it don't always check the corresponding function constantly.
* implemented 1 - 9 buttons on ipad.

##### December 3rd
* continue working on ofxOsc. Trying to send screenshot to the server and display on html webpage
* It's not possible, since ofxOsc sender could only send parameter data that is less than 1kb
* looking into other possible approaches
* Considering using ofxOsc to receive remote order to procede my game
* implemented controller class, used to receive data from remote device.
* looking into three different osc sender from IOS devices and finally selected Lemur

##### December 2nd
* using built-in shuffle function changed the order of my segments
* implemented screenshot functions
* started looking into different types of networking apis. 
* started to try sending data with ofxOsc 

##### November 30th
* Added label for each of the segment
* Implemented that when segment is dragged to a specific sub section on the right, it would automatically match to the board.
* added vector of correct sequence and actual sequence to MatchBoard class to implement the randomness of the each segments
* right now , its just a sequence from 1 - 9 . 

##### November 29th
* implemented drag corresponding images by change the position of mouse
* updated some corresponding function in the images destroyer.
* created function in Match Board in order to successfully match images and display them when drag to those subsections.
* unsure about which algorithem to determine the corresponding subsection it matches to.

##### November 28th
* trying to implement moving each images by using dragging event.
* faced bug with dragging since it doesnt have enough information for
* altered strategy to use mouse click and mouse released
*Potential Problem* 1. Don't know what happen for those that are stacked up
* Switched Strategy to using draw the images to corresponding mouse position when the corresponding segment was selected.

##### November 26th
* started working on the solve board by giving it a 2d vector

##### November 18th to November 25th

*********************THANKSGIVING BREAK*********************

##### November 17th
* Implemented enum state for game , in selection / in progress and in_game_;
* Implemented auto formatting the images to different size to windows .

##### November 15th
* implemented scale up and scale down when a segmented was selected.
* Added Key pressed event handler when 1-9 was pressed and corresponding segments are selected.
* Added frames to the segments when being selected.

##### November 14th
* implemented destroyer that could tear apart images into 9 segments
* Implemented draw segments randomly on the left side of the window.
* Added image to the match borard and also bluring effect that change to alpha of the chosen image and display on right.

##### November 11th
* Created image_destroyer class and set up what needs to be done for such class.
* Fixed the bug drawing images on the window by installing Xcode 9.2
* Created left - window which included a slider to select images to display
* Added match board to display a board on the right for the user to drag those segments to.

##### November 9th
* Seted up basic structure for my games.
* Created Image_Folder class which store the images that user dragged into the window.
* Added font for the header as well as some images manifulation.
* detected bug trying to draw images on the window.



