# Image Jigsaw Puzzle Proposal

### Game Idea

I'm proposing to create a game that takes a source image from a user by either selecting it from their directory or directly dragging images to the window.  After images are loaded, user would input a number and then the images would be teared apart into that number. Then there would be a sub-window on the right with the exact same size of the original pictures then user would be able to drag those pieces from the left window to the right window and match with the original location. There would be two buttons on the bottom to rotate the selected pieces by rotating left and right. When all the pieces are correctly matched to the corresponding points, the game would end. A leader board would appear and prompt for another round of game.

### Implementation 

With such idea, I consider the following open framework addon would help a lot :

  - [x] ofxGui
  

first of all, the Gui addon is a nessessity. With the GUI, I would be able to build my game based on a window and have some basic interface. Within the Gui addon, ofxPanel and ofxButton would really help to divide my game into subsections and provide some functionality in regards to buttons.
        
        
  - [x] ofImage

 
This would be another important add on as I would need to use it to load user input images. The ofImage addon also provided some really useful functionality allowing me to potentially crop images which is one way to achieve my tearing procedure.
    
  - [x] ofxVectorGraphics
  
 
Consider the possibility of designing the shape of Jigsaw for the puzzle, I put Vector Graphics into an account as the way to design those shapes using the provided lines, triangles methods. 

 - [x] ofFbo &&  ofPath path


[The following comes from of openframworks website : ](https://openframeworks.cc/learning/02_graphics/how_to_maskanimagewithashape/) 
>we can draw a path into an FBO (offscreen image) and then pass the result to the image we want to mask. 
Along with these two adds on, I would be able to shape an images to a ways that I want.

### Other Possible Add-ons  

 - [x] ofxDraggable
 

Such addon would help me implementing my sliced pieces being dragged to match its corresponding positions.

 - [x] ofx2DMapping
 

Such add on could be used to determin the correctness of each slices. I could also be a potential solve for slicing up the image into pieces. 

:sparkles::sparkles::sparkles::sparkles::sparkles::sparkles::sparkles::sparkles::sparkles::sparkles:


