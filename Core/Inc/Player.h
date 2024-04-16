#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_
#include <Score.h>
class Player {
private:
	int playerNumber;
	int x;
	int y;

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
	// TODO write a function to find x and make sure x is valid smt like findAndSetX()
	virtual ~Player();
};

#endif /* INC_PLAYER_H_ */
