#include <Player.h>
#include "lcd.h"
#include "main.h"

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
void Player::resetX() {
	x = (LCD_DispWindow_COLUMN / 2) - (playerWidith / 2); // center position
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
void Player::setADC_HandleTypeDef(ADC_HandleTypeDef *hadc) {
	this->hadc = hadc;
}
bool Player::playerTouch() {
	int inputPin;
	if (playerNumber == player1) { // check if player is touching the rheostat
		inputPin = HAL_GPIO_ReadPin(player1Touch_GPIO_Port, player1Touch_Pin);
	} else {
		inputPin = HAL_GPIO_ReadPin(player2Touch_GPIO_Port, player2Touch_Pin);
	}
	if (inputPin == 0) {
		this->x = playerNotTouching;
		return false;
	}
	return true;
}
void Player::findAndSetX() {
	int ADCValueInt, inputPin, x;
	if (playerNumber == player1) { // check if player is touching the rheostat
		inputPin = HAL_GPIO_ReadPin(player1Touch_GPIO_Port, player1Touch_Pin);
	} else {
		inputPin = HAL_GPIO_ReadPin(player2Touch_GPIO_Port, player2Touch_Pin);
	}
	if (inputPin == 0) {
		this->x = playerNotTouching;
		return;
	}

	// ask ADC to get value
	HAL_ADC_Start(hadc);
	HAL_ADC_PollForConversion(hadc, 1000);
	ADCValueInt = HAL_ADC_GetValue(hadc);

	x = (ADCValueInt * (LCD_DispWindow_COLUMN - wallWidith - playerWidith))
			/ rheostatMaximumValue; // translate ADC value to x position

	// make sure x is within broad and set its value
	if (x <= wallWidith) {
		this->x = wallWidith + 1;
		return;
	}
	if (x + playerWidith >= LCD_DispWindow_COLUMN - wallWidith) {
		this->x = LCD_DispWindow_COLUMN - wallWidith - playerWidith - 1;
		return;
	}
	this->x = x;
}
Player::~Player() {
}

