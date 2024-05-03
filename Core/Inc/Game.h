#ifndef INC_GAME_H_
#define INC_GAME_H_

#include "Player.h"
#include "Menu.h"
#include "Ball.h"

class Game {
private:
	bool start;
public:
	Player player[2] = { Player(Player::player1), Player(Player::player2) };
	Menu menu;
	Ball ball;
	Game();

	void setStart(bool start);
	bool getStart();
	void quit();
	void restart();
	bool checkCollision(int playerNumber);
	bool moveBall();
	void knockback(int playerNumber);
	void botMovement();
	void gaming();
	void displayWinner(int playerNumber);
	void displayBallMovement();
	void displayPlayerMovement(int playerNumber);
	virtual ~Game();
};

#endif /* INC_GAME_H_ */
