#include <Score.h>

Score::Score(int playerNumber){
	// TODO Auto-generated constructor stub
this->playerNumber=playerNumber;
point=10;
}
int Score::getPoint(){
	return point;
}
void Score::displayPoint(){
	// TODO display point

}
void Score::setPoint(int point){
	this->point=point;
	displayPoint();
}
void Score::endGame(){
	//TODO end game

}
Score::~Score() {}

