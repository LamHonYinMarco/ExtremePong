#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_
#include <Score.h>
class Player {
private:
	int playerNumber;
	double location;
	Score score;

public:
	Player(int playerNumber);
//	void setPlayerNumber(int playerNumber);
	int getPlayerNumber();
	void setLocation(double location);
	double getLocation();
	void displayPlayerLocation();
	virtual ~Player();
};

#endif /* INC_PLAYER_H_ */
