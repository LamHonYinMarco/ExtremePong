#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_
#include <Score.h>
class Player {
private:
	int playerNumber;
	double location;


public:
	Score score;
	Player(int playerNumber);
//	void setPlayerNumber(int playerNumber);
	int getPlayerNumber();
	void setLocation(double location);
	double getLocation();
	void displayPlayerLocation();
//	Score getScore();
	virtual ~Player();
};

#endif /* INC_PLAYER_H_ */
