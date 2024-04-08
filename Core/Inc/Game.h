#ifndef INC_GAME_H_
#define INC_GAME_H_

#include <iostream>
class Game{
private:
	bool start;
public:
Game();
void setStart(bool start);
bool getStart();
virtual ~Game();
};



#endif /* INC_GAME_H_ */
