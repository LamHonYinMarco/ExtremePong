#ifndef INC_GAME_H_
#define INC_GAME_H_


#include "Player.h"
#include "Menu.h"
#include "Ball.h"

class Game{
private:
	bool start;
	Player player[2] = {Player(1),Player(2)};
	Menu menu;
	Ball ball;

public:
Game();
void setStart(bool start);
bool getStart();
void quit();
void restart();
virtual ~Game();
};



#endif /* INC_GAME_H_ */
