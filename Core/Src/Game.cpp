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
	//Todo: return to home menu

}
void Game::restart(){
	//Todo: reset ball and score

}
Game::~Game(){

}


