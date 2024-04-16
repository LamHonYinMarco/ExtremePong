#include <Player.h>
#include "lcd.h"

Player::Player(int playerNumber) :
		score(playerNumber) {
	this->playerNumber = playerNumber;
	resetX();
	if (playerNumber == Player::player1) {
		y = player1YAxis;
	} else {
		y = player2YAxis - playerHeight; // - height to get top left pixel
	}
}
void Player::resetX(){
	x = (LCD_DispWindow_COLUMN/2)-(playerWidith/2); // center position
}
int Player::getPlayerNumber() {
	return playerNumber;
}
void Player::setX(int x) {
	this->x = x;
}
int Player::getX() {
	return x;
}
void Player::setY(int y) {
	this->y = y;
}
int Player::getY() {
	return y;
}

Player::~Player() {
}

