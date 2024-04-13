#include <Player.h>

Player::Player(int playerNumber): score(playerNumber){
this->playerNumber=playerNumber;
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
double Player::getLocation(){
	return location;
}
//Score Player::getScore(){
//	return score;
//}
Player::~Player() {}

