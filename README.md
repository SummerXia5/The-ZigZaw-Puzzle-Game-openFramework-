# FinalProject


## Introduction ##

Hello, Players! Welcome to Image Zigsaw Puzzle game developed by Summer Xia and based on OpenFramework. This game would be required to cooperate with a openframework supported Mac OS and a OSC sender on whatever machine you have. The zigsaw puzzle would divide up the image you selected to 9 different segments and you would be the one to resemble them back together using a remote controller that sends osc message to finish the game. Through out the game, you would be able to select the difficulty, take screenshots, move each segments, quit and start. Whenever you quit the game, your records would also be saved to local so it would not disappear next time you opened it back up.

## controller ##
Personally I recommend using Lemur on IOS system. This is a application that allows you to design your own controllers. First, you need to setup your own network from your laptop and connect your other device with such network. As you opened up your osc sender. You would need to set the host as the name of your network and set the portal as 12345. You can create following list of sender based on the given address :

1. #### "/menu/difficulty" given range 1 - 4 
Given your sender such message address would allow you to choose difficulty of this game from 1 - 4 s.t. 1 would represend have only the image, 2 has only the frame, and 3 have both and 4 have none.

2. #### "/slider/1" ####
Using such message address enable you to send a float from 0 - 1 so the game engine would automatically switch the given float to the corresponding selection of images you want to play with.

3. #### "/select/1" ####
Using this message address proceeds the game with select the corresponding image and wait to be segmented later on.

4. ####  "/choice/1" ~~~ "/choice/9" ####
These nine different addresses would give you access to select each of the segment when you tear the origin image apart.

5. #### "/MultiBall/x" and "/MultiBall/y" ####
This two addresses give you access to control the selected segments of the game and you would be able to move the segments around with your x, y send through this message address

6. #### "/start/1" #### 
You would be able to send whatever message through this osc message address, whenever you send anything, if you already selected a specific image, the message sending would tear this apart. 

7. #### "/restart/1" ####
Sending messages through this address would restart this game whenever you need or you want to.

8. #### "/photo/1" ####
Sending messages through this address enable you to take screen shot of current scene you are at.

9. #### "/quit/1" ####
Sending message through this address would quit the existing game you are at and save the record to your local address. 

# THANK YOU FOR PLAYING MY GAME #
