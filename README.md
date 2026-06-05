# My connect 4
my_connect4 is a simple project that aims to recreate the [connect 4 game](https://en.wikipedia.org/wiki/Connect_Four) in C language<br>
This project was made during my first year of study in software engineering.<br> 
The goal was pretty simple, recreate one of my favourite games in my own way, with what I knew.<br>
<br>
This project contains two libraries :<br>
|CSFML|Ncurses|
|:-:|:-:|
|Graphical library (GUI)|"Textual" library (TUI)|
<b>Current state :</b><br>
<b>Ncurses:</b> (finished)<br>
![](https://geps.dev/progress/100)<br>
<b>CSFML :</b> (Not usable yet)<br>
![](https://geps.dev/progress/10)<br>
## How to start?
```
make re
```
> \- Compiles and creates the binary file, that can launch the game<br>
```
./connect4 [FLAG]
```
Starts the game 
|<b>FLAGS</b>|Descriptions|
|:-|:-|
|<b>-h</b>|Help menu in english, containing more detailed informations|
|<b>-f</b>|Help menu in french|
|<b>-c</b>|Starts in CSFML|
|<b>-n</b>|Starts in Ncurses|
|<b>-s</b>|Displays the current score for each player|
## How to play?
### Window size menu
![](https://i.imgur.com/IvgOmN6.png)
> The first window will ask you a resolution for your window<br>
> If it doesn't work, try a smaller resolution<br>
> This table shows you each window size's associated resolution, meaning the width and height for one cell
|Number|Resolution|
|:-:|:-:|
|1|7 x 3|
|2|9 x 4|
|3|11 x 5|
|4|13 x 6|
___
### Token menu
![](https://i.imgur.com/fE8UpZ5.png)
> This menu contains two lines, both being sliders<br>
> To interract with a slider, press `Left / Right arrow keys`<br>
> To change between sliders, press `Up / Down arrow keys`<br>

<br>

![](https://i.imgur.com/K6KQTkC.png)
> To add a player with the current token and color, press `Enter`<br>
> Once you add at least 2 players, you can start by pressing `Space`<br>
> You can add up to 4 players<br>
> Each one will play in the order they've been added in<br>
___
### Game 
![](https://i.imgur.com/s0cbFcL.png)
> The game is turn based, where each player can place a token on the lowest spot of the selected column<br>
> The arrow shows you which column is selected, you can move it with `Left / Right arrow keys`<br>
> To play your token, press the `Number key` of the corresponding column, or `Enter` to play in the selected one<br>
> You can see which player will come next on the right<br>

<br>

![](https://i.imgur.com/0wfLmhh.png)
> The game will end when a player [connects 4](https://en.wikipedia.org/wiki/Connect_Four) of their tokens vertically, horizontally or diagonally, or when the board is filled<br>
> You can restart pressing `R` at any point, even while playing
___
### Scores
![](https://i.imgur.com/X9r002Z.png)
> To see the scores of a player (P1-4), you need to play at least one game with said player.<br>
> 
## Notes
> A lot of main variables have been defined by macros in the header file `include/config.h`.<br> 
> If you want to change variables for yourself, like the max number of players, the board's width and height, you can simply change them here.<br>
> Be aware, they can make the program crash, or make it do weird things..<br>

> Some personal choices have been made simply to make the gameplay funnier, and have a lot of things still modifiable by the player (you can choose 4x the same color / pattern).

> Be aware that a 3+ player connect4 isn't your normal connect4 game, theres a lot of diplomacy going on with opponents, but it's really fun nonetheless!
## Credits
> [Benjamin](https://github.com/benjaminmaxo) for helping with testing<br>
> [Alex](https://github.com/Alexnex31) for helping with suggestions, and the last screenshot<br>