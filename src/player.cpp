#include "player.h"
#include <iostream>

// Sets the player name
void Player::setName(std::string playerName) {

    _playerName = playerName;

}

// Sets the player score
void Player::setScore(int score) {

    _score = score;
}

void Player::setDate(std::string date) 
{
    _date = date;
}

std::string Player::getName() 
{
        return _playerName;
}

int Player::getScore() 
{
    return _score;
}

std::string Player::getDate() 
{
    return _date;
}

void Player::enter_name(){
    
    std::cout << "Enter the players name: ";
    std::string name;
    std::cin >> name;

    setName(name);
}