#ifndef INC_BALL_H_
#define INC_BALL_H_

class Ball {
private:

public:
	int x,y;
	int dx,dy;
	Ball();
	void reset();
	virtual ~Ball();
};

#endif /* INC_BALL_H_ */
