#ifndef INC_SCORE_H_
#define INC_SCORE_H_



class Score{
private:
	int point;
	int playerNumber;
public:
	Score(int playerNumber);
	int getPoint();
	void setPoint(int point);
	void displayPoint();
	void turnOffDisplay();
	virtual ~Score();
};

#endif /* INC_SCORE_H_ */
