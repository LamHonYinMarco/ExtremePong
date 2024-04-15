#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_
#include <Score.h>
class Player {
private:
	int playerNumber;
	int location;


public:
	enum playerNumbers{player1 = 0, player2 = 1};
	Score score;
	Player(int playerNumber);
//	void setPlayerNumber(int playerNumber);
	int getPlayerNumber();
	void setLocation(double location);
	int getLocation();
	void displayPlayerLocation();
//	Score getScore();
	virtual ~Player();
};

#endif /* INC_PLAYER_H_ */
