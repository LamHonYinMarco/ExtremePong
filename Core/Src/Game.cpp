#include <Game.h>
#include "lcd.h"
#include <stdlib.h>
Game::Game() {
	start = false;
}
void Game::setStart(bool start) {
	this->start = start;
}
bool Game::getStart() {
	return start;
}
void Game::quit() {
	start = false;
	player[0].score.setPoint(0);
	player[1].score.setPoint(0);
	player[0].setLocation(98);
	player[1].setLocation(98);
	ball.reset();
	menu.setCurrentMenu(Menu::homeScreen);
}
void Game::restart() {
	player[0].score.setPoint(0);
	player[1].score.setPoint(0);
	ball.reset();
}

void Game::knockback() {
	//TODO

}

bool Game::checkCollision(int playerNumber) {
	if (playerNumber == Player::player1) {
		if (ball.y + ballWidith < 300) {
			return false;
		}
	}
	if (playerNumber == Player::player2) {
		if (ball.y > 20) {
			return false;
		}
	}
	if ((ball.x >= player[playerNumber].getLocation())
			&& (ball.x <= player[playerNumber].getLocation() + playerWidith)) {
		return true;
	}
	return false;
}
void Game::moveBall() {
	// update ball location according to vector
	ball.x += ball.dx;
	ball.y += ball.dy;
	// if vsWall then no need to check for player 2 collision
	if (menu.getCurrentMenu() == Menu::vsWallGame && ball.y <= wallWidith) {
		ball.dy = -ball.dy;
		ball.y = wallWidith + 1;
		return;
	}

	// check if ball hit wall
	if (ball.x <= wallWidith
			|| ball.x + ballWidith >= LCD_DispWindow_COLUMN - wallWidith) {
		ball.dx = -ball.dx;

		// move back within broad
		if (ball.x <= wallWidith) {
			ball.x = wallWidith + 1;
		}
		if (ball.x + ballWidith >= LCD_DispWindow_COLUMN - wallWidith) {
			ball.x = LCD_DispWindow_COLUMN - ballWidith - wallWidith - 1;
		}
	}

	// check for collision on both players
	for (int i = 0; i < 2; i++) {
		if (checkCollision(i)) {
			// increase ball speed and move back within broad
			if (ball.dy < 0) {
				ball.dy -= menu.settings.getBallSpeedIncreaseRate();
				ball.y = 20 + 1;
			} else {
				ball.dy += menu.settings.getBallSpeedIncreaseRate();
				ball.y = 300 - ballWidith - 1;
			}
			// change ball direction
			ball.dy = -ball.dy;

			//change ball angle based on where on the paddle it hit
			int hitPosition = (player[i].getLocation() + playerWidith) - ball.x;
			double paddlePosition = playerWidith / 9;
			int direction = 4;
			for (int i = 0; i < 9; i++) {
				if (hitPosition >= paddlePosition * i
						&& hitPosition < paddlePosition * (i + 1)) {
					ball.dx = direction;
					break;
				}
				direction--;
			}
		}
	}

	// check if player2 / bot won
	if (ball.y + ballWidith >= 319) {
		player[Player::player2].score.setPoint(
				player[Player::player2].score.getPoint() + 1);
		ball.reset();
	}

	// check if player1 won
	if (ball.y <= 0) {
		player[Player::player1].score.setPoint(
				player[Player::player1].score.getPoint() + 1);
		ball.reset();
	}
}

void Game::botMovement() {
	int center = player[Player::player2].getLocation() + (playerWidith / 2);
	int screenCenter = LCD_DispWindow_COLUMN / 2;
	int ballSpeed = abs(ball.dx);

	//ball moving right
	if (ball.dy > 0) {
		//return to center position
		if (center < screenCenter) {
			player[Player::player2].setLocation(
					player[Player::player2].getLocation() + ballSpeed);
		} else {
			player[Player::player2].setLocation(
					player[Player::player2].getLocation() - ballSpeed);
		}
		//ball moving left
	} else {
		//ball moving down
		if (ball.dx > 0) {
			if (ball.x > center) {
				player[Player::player2].setLocation(
						player[Player::player2].getLocation() + ballSpeed);
			} else {
				player[Player::player2].setLocation(
						player[Player::player2].getLocation() - ballSpeed);
			}
		}
		//ball moving up
		if (ball.dx < 0) {
			if (ball.x < center) {
				player[Player::player2].setLocation(
						player[Player::player2].getLocation() - ballSpeed);
			} else {
				player[Player::player2].setLocation(
						player[Player::player2].getLocation() + ballSpeed);
			}
		}
		//ball moving stright across
		if (ball.dx == 0) {
			if (ball.x < center) {
				player[Player::player2].setLocation(
						player[Player::player2].getLocation() - 5);
			} else {
				player[Player::player2].setLocation(
						player[Player::player2].getLocation() + 5);
			}
		}
	}
	// make sure it is within broad
	if (player[Player::player2].getLocation() <= wallWidith) {
		player[Player::player2].setLocation(wallWidith + 1);
	}
	if (player[Player::player2].getLocation() + playerWidith
			>= LCD_DispWindow_COLUMN - wallWidith) {
		player[Player::player2].setLocation(
		LCD_DispWindow_COLUMN - wallWidith - playerWidith - 1);
	}

}

void Game::displayBallMovement() {
	Ball tempBall;
	tempBall = ball;
	moveBall();
	LCD_MoveBall(tempBall.x, tempBall.y, ball.x, ball.y);
}

void Game::displayPlayerMovement(int playerNumber) {
	int tempPlayerLocation;
	tempPlayerLocation = player[playerNumber].getLocation();
	if (menu.getCurrentMenu() == Menu::vsBotGame
			&& playerNumber == Player::player2) {
		botMovement();
		LCD_MovePlayer(tempPlayerLocation, 20 - playerHeight,
				player[Player::player2].getLocation(), 20 - playerHeight);
		return;
	}
	// player[playerNumber].setLocation(); // TODO set location
	if (playerNumber == Player::player1) {
		LCD_MovePlayer(tempPlayerLocation, 300,
				player[Player::player1].getLocation(), 300);
	} else {
		LCD_MovePlayer(tempPlayerLocation, 20 - playerHeight,
				player[Player::player2].getLocation(), 20 - playerHeight);
	}
}

void Game::gaming() {

	switch (menu.getCurrentMenu()) {
	case Menu::vsWallGame:
		setStart(true);
		displayPlayerMovement(Player::player1);
		displayBallMovement();
		LCD_DrawNet();
		break;
	case Menu::vsBotGame:
		setStart(true);
		displayPlayerMovement(Player::player1);
		displayPlayerMovement(Player::player2);
		displayBallMovement();
		LCD_DrawNet();
		break;
	case Menu::twoPlayersGame:
		setStart(true);
		displayPlayerMovement(Player::player1);
		displayPlayerMovement(Player::player2);
		displayBallMovement();
		LCD_DrawNet();
		break;
	default:
		;
	}
}
Game::~Game() {
}

