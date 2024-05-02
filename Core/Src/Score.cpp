#include <Score.h>
#include "main.h"
#include <Player.h>
Score::Score(int playerNumber) {
	// TODO Auto-generated constructor stub
	this->playerNumber = playerNumber;
	point = 0;
}
int Score::getPoint() {
	return point;
}
void Score::displayPoint() {
	if (playerNumber == Player::player1) {
		switch (point) {
		case 0:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
			break;
		default:
			HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_SET);
		}
	} else {
		switch (point) {
		case 0:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		default:
			HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
		}
	}
}
void Score::setPoint(int point) {
	this->point = point;
	displayPoint();
}

void Score::turnOffDisplay() {
	if (playerNumber == Player::player1) {
		HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
	}
}

void Score::endGame() {
	//TODO end game

}
Score::~Score() {
}

