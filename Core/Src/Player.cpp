#include <Player.h>

Player::Player(int playerNumber): score(playerNumber){
this->playerNumber=playerNumber;
location = 98;
}

int Player::getPlayerNumber(){
	return playerNumber;
}
void Player::displayPlayerLocation(){
	//Todo::display location
}
void Player::setLocation(double location){
	this->location=location;
	displayPlayerLocation();
}
int Player::getLocation(){
	return location;
}
//Score Player::getScore(){
//	return score;
//}
Player::~Player() {}

