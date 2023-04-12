#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime> 
#include "player.h"

const int kMaxentries = 500;
const std::string kleaderboardfile = "../Leaderboard.txt";
static const int print_N_highscores = 10;

class LeaderBoard{
public:
    void Read(void);
    void Write(void);
    void Print(void);
    void Update(std::string playerName, int score);

private:
    std::vector<Player> _playerList;
     
};

bool compare_player_by_score(Player player1, Player player2);


#endif

