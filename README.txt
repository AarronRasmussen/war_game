This program contains three different mains which run different versions of the game of war:

main.cpp is your typicall game of war. it is run  using the following commands
./run.sh
./a.out (the number of games you want to play)

ourmain.cpp is a game where player one play from the top of his deck and player two plays from the bottom of his deck. I made this program to prove to my sister that if this pattern is followed the player who deals from the bottom will consistantly win more than the one who plays from the top. it is run using the following commands
./ourRun.sh
./a.out (the number of games you want to play)

infinmain.cpp is an anomaly that I programmed while making this war game simulation. infinmain.cpp contains almost the same code as main.cpp with one difference. when a player is out of cards their       winpile which becomes their new hand is not shuffled before it becomes their hand. this results in frequent infinate games where no player wins. I can only assume that not shuffling the winpiles before   they become hands maintains a certain order which is repeated continously thereby creating an infinate game. infinmain.cpp is run using the following commands
./infinRun.sh
./a.out (the number of games you want to play)


