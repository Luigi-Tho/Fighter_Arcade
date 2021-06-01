#Devlogs:
###[5/15/2021]
I have decided to start over with Fighter Arcade.
I finished everything I need to finish elsewhere. It's time to start up again.
__Dependencies__: The Cherno and his C++ Series, StackOverFlow, C++ Reference, etc.
__Objectives__: Make sure everything works, and start on the combat system.

###[5/19/2021]
Hello!
I'm back. I'm actually working on this during virtual class... But that's not the point.
I plan to finish the combat system today and test it.
__Dependencies__: Old Fighter Arcade files,
__Objectives__: Finish 1st version of the combat system.

###[5.31.2021]
Hello. This week is my last week of school and I am graduating in 2 weeks.
Anyway, I am not sure what I need to do today (I should add that info into the devlog system).
I think I need to work on the combat system so it looks decent and functions as intended.
Idk. We'll see.
Update: We have a problem:
![problem](error.png "The Problem")
The game isn't loading at all! Yay! (sarcasm). _Help_.
__Dependencies__: Old code and old Trello list. Probably The Cherno's C++ series as well.
__Objectives__: Idk.
__Completed Goals__: Idk.

###[6.1.2021]
Hello. I'm sorry I didn't do anything game-related yesterday...
I am figuring out how to do stuff in markdown right now.
I still don't know how to add images that are on my computer.
I mean, I do, but it isn't working... I'm gonna look at other people's stuff and see what happens.

Update: [This StackOverFlow Question](https://stackoverflow.com/questions/41604263/how-do-i-display-local-image-in-markdown).
It really helped. I got it now. Anyway, back to the game. **_HELP_**.

Update: So... it turns out that everytime the player and enemy classes are constructed, currenthealth is set to 0.
Therefore, the player and enemy just end up winning each turn. I fixed it.
__HOWEVER__, I'm realizing now that the way I implemented it, the currenthealth gets reset every turn.
I need to figure out to get it where it only works the first time combat starts.
I'll figure it out later. I have a thumbnail to start on. Let's commit this thing.

__Objectives__:
- [x] Fix image issue.
- [x] Figure out what's why the game isn't loading. (It's the combat loop)
- [x] Figure out why the combat loop isn't starting.
- [x] Fix combat.
- [ ] Figure out how to get currenthealth to reset only when combat initally starts.
