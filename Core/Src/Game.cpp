#include <Game.h>

Game::Game(){
	start = false;
}
void Game::setStart(bool start){
	this->start=start;
}
bool Game::getStart(){
return start;
}
void Game::quit(){
	start = false;
	player[0].score.setPoint(10);
	player[1].score.setPoint(10);
	ball.reset();
	menu.setCurrentMenu(Menu::homeScreen);
}
void Game::restart(){
	player[0].score.setPoint(10);
	player[1].score.setPoint(10);
	ball.reset();
}
Game::~Game(){

}


