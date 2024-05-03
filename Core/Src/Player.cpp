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
void Player::setADC_HandleTypeDef(ADC_HandleTypeDef *hadc){
	this->hadc = hadc;
}
void Player::findAndSetX(){
	int ADCValueInt;
		HAL_ADC_Start(hadc);
		HAL_ADC_PollForConversion(hadc, 1000);
		playerNumber;
		ADCValueInt = HAL_ADC_GetValue(hadc);
		ADCValueInt;
		//TODO this->x = ADCValueInt; // Change the value of x to wallWidith to (LCD_DispWindow_COLUMN-wallWidith-playerWidith)
		//In more human language, The x=3 means player is touching the left wall. x=192 means player is touching the right wall.
		//The goal is to translate ADCValueInt into a value between 3 to 192.
}
Player::~Player() {
}

