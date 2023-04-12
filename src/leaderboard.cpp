#include "leaderboard.h"

// Reads the lines from leaderboard text file
void LeaderBoard::Read(void) {

    std::string line;
    std::string name;
    std::string score;
    std::string date; 
    Player player;

    std::ifstream stream(kleaderboardfile);
    if (stream.is_open()){
        while (std::getline(stream, line)){
            std::istringstream linestream(line);
            while (linestream >> name >> score >> date){ 
                player.setName(name);
                player.setScore(std::stoi(score));
                player.setDate(date); 
                
                _playerList.emplace_back(player);
            }
        }
    }
}

// Write new score to file 
void LeaderBoard::Write(void) {

    // open leaderboard file as stream and put players in
    std::ofstream file;
    file.open (kleaderboardfile);
    for (std::vector<Player>::iterator iter = _playerList.begin(); iter != _playerList.end(); ++iter){
        file << iter->getName() << " " << iter->getScore() << " "<< iter->getDate() <<"\n"; 
    }
    file.close();
}

// After finishing the game print first print_N_highscores highscores
void LeaderBoard::Print(void) {
    int i = 0;
    std::cout << "Leaderboard:  \n \n";
    
    // loop through list of players
    for (std::vector<Player>::iterator iter = _playerList.begin(); iter < _playerList.end(); ++iter) {
        i++;
        std::cout << "Rank " << i << ":\t" << iter->getName() << "\t" << iter->getScore() << "\t" << iter->getDate() << "\n"; 
        if (i >= print_N_highscores)
        {
            break;
        }
    }
    std::cout << "\n";
}

// Update leaderboard
void LeaderBoard::Update(std::string playerName, int score) {
    Player player;
    player.setName(playerName);
    player.setScore(score);

    // get current time
    time_t now = time(0);
    std::tm *ltm = localtime(&now);

    std::string year = std::to_string(1900 + ltm->tm_year) ;
    std::string month =  std::to_string(1 + ltm->tm_mon);
    std::string day =   std::to_string(ltm->tm_mday);

    std::string date = day + "." + month + "." + year;
    player.setDate(date);

    // Insert new highscore 
    if (score > _playerList.back().getScore()){
        std::cout << "Congratulations! You got in the top "<< print_N_highscores << "!!" << "\n";
	    _playerList.emplace_back(player);
	    std::sort(_playerList.begin(), _playerList.end(), compare_player_by_score);
    }
    
}

bool compare_player_by_score(Player player1, Player player2){	
    return player1.getScore() > player2.getScore();
}
