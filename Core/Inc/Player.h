#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_
#include <Score.h>
//#include "stm32f1xx_hal_adc.h"
#include "stm32f1xx_hal.h"
class Player {
private:
	int playerNumber;
	int x;
	int y;
	ADC_HandleTypeDef* hadc;

public:
	enum playerNumbers{player1 = 0, player2 = 1};
	Score score;
	Player(int playerNumber);
	int getPlayerNumber();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void resetX();
	void setADC_HandleTypeDef(ADC_HandleTypeDef *hadc);
	bool playerTouch();
	void findAndSetX();
	virtual ~Player();
};

#endif /* INC_PLAYER_H_ */
