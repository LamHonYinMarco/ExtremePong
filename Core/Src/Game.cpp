#include <Game.h>
#include "lcd.h"
#include <stdlib.h>
#include <stdio.h>
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
	player[Player::player1].score.setPoint(0);
	player[Player::player2].score.setPoint(0);
	player[Player::player1].score.turnOffDisplay();
	player[Player::player2].score.turnOffDisplay();
	player[Player::player1].resetX();
	player[Player::player2].resetX();
	ball.reset();
	menu.setCurrentMenu(Menu::homeScreen);
}
void Game::restart() {
	start = false;
	player[Player::player1].resetX();
	player[Player::player2].resetX();
	ball.reset();
	menu.setCurrentMenu(menu.getCurrentMenu());
}

void Game::knockback(int playerNumber) {
	//TODO
	int pulse = 100, delay = startingDelay; // TODO change pulse
	pulse *= ball.dy;
	//	MX_TIM4_Init(pulse);
	if (playerNumber == Player::player1) {
		//	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
		if (startingDelay * ball.dy >= maximumDelay) {
			HAL_Delay(maximumDelay);
		} else {
			HAL_Delay(delay * ball.dy);
		}
		//	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1); // no idea if this will work, might need to do pulse stuff
	} else {
		//	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
		if (startingDelay * ball.dy >= maximumDelay) {
			HAL_Delay(maximumDelay);
		} else {
			HAL_Delay(delay * ball.dy);
		}
		//	HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_2);
	}

}

bool Game::checkCollision(int playerNumber) {
	if (playerNumber == Player::player1) {
		if (ball.y + ballWidith < player1YAxis) {
			return false;
		}
	}
	if (playerNumber == Player::player2) {
		if (ball.y > player2YAxis) {
			return false;
		}
	}
	if ((ball.x >= player[playerNumber].getX())
			&& (ball.x <= player[playerNumber].getX() + playerWidith)) {
		return true;
	}
	return false;
}
bool Game::moveBall() {
	// update ball location according to vector
	ball.x += ball.dx;
	ball.y += ball.dy;
	// if vsWall then no need to check for player 2 collision
	if (menu.getCurrentMenu() == Menu::vsWallGame && ball.y <= wallWidith) {
		ball.dy = -ball.dy;
		ball.y = wallWidith + 1;
		return true;
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
				if (menu.getCurrentMenu() != Menu::vsBotGame
						&& menu.settings.getKnockback()) {
					knockback(Player::player2);
				}
				ball.y = player2YAxis + 1;
			} else {
				ball.dy += menu.settings.getBallSpeedIncreaseRate();
				if (menu.settings.getKnockback()) {
					knockback(Player::player1);
				}
				ball.y = player1YAxis - ballWidith - 1;
			}
			// change ball direction
			ball.dy = -ball.dy;

			//change ball angle based on where on the paddle it hit
			int hitPosition = (player[i].getX() + playerWidith) - ball.x;
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
	if (ball.y + ballWidith >= 320) {
		player[Player::player2].score.setPoint(
				player[Player::player2].score.getPoint() + 1);
		ball.reset();
		return false;
	}

	// check if player1 won
	if (ball.y <= 0) {
		player[Player::player1].score.setPoint(
				player[Player::player1].score.getPoint() + 1);
		ball.reset();
		return false;
	}
	return true;
}

void Game::botMovement() {
	int center = player[Player::player2].getX() + (playerWidith / 2);
	int screenCenter = LCD_DispWindow_COLUMN / 2;
	int ballSpeed = abs(ball.dx);

	//ball moving right
	if (ball.dy > 0) {
		//return to center position
		if (center < screenCenter) {
			player[Player::player2].setX(
					player[Player::player2].getX() + ballSpeed);
		} else {
			player[Player::player2].setX(
					player[Player::player2].getX() - ballSpeed);
		}
		//ball moving left
	} else {
		//ball moving down
		if (ball.dx > 0) {
			if (ball.x > center) {
				player[Player::player2].setX(
						player[Player::player2].getX() + ballSpeed);
			} else {
				player[Player::player2].setX(
						player[Player::player2].getX() - ballSpeed);
			}
		}
		//ball moving up
		if (ball.dx < 0) {
			if (ball.x < center) {
				player[Player::player2].setX(
						player[Player::player2].getX() - ballSpeed);
			} else {
				player[Player::player2].setX(
						player[Player::player2].getX() + ballSpeed);
			}
		}
		//ball moving stright across
		if (ball.dx == 0) {
			if (ball.x < center) {
				player[Player::player2].setX(
						player[Player::player2].getX() - 5);
			} else {
				player[Player::player2].setX(
						player[Player::player2].getX() + 5);
			}
		}
	}
	// make sure it is within broad
	if (player[Player::player2].getX() <= wallWidith) {
		player[Player::player2].setX(wallWidith + 1);
	}
	if (player[Player::player2].getX() + playerWidith
			>= LCD_DispWindow_COLUMN - wallWidith) {
		player[Player::player2].setX(
		LCD_DispWindow_COLUMN - wallWidith - playerWidith - 1);
	}

}

void Game::displayBallMovement() {
	Ball tempBall;
	tempBall = ball;
	if (moveBall()) { // ball moved
		LCD_MoveBall(tempBall.x, tempBall.y, ball.x, ball.y);
	} else { // ball position reset
		LCD_DrawBall(tempBall.x, tempBall.y, BLACK);
		LCD_DrawBall(ball.x, ball.y, WHITE);
	}
}

void Game::displayPlayerMovement(int playerNumber) {
	int tempPlayerX;
	tempPlayerX = player[playerNumber].getX();
	if (menu.getCurrentMenu() == Menu::vsBotGame
			&& playerNumber == Player::player2) {
		botMovement();
	} else {
		player[playerNumber].findAndSetX(); // TODO set location
	}

	LCD_MovePlayer(tempPlayerX, player[playerNumber].getY(),
			player[playerNumber].getX(), player[playerNumber].getY());
}

void Game::displayWinner(int playerNumber) {

	LCD_Clear(LCD_DispWindow_Start_COLUMN, LCD_DispWindow_Start_PAGE,
	LCD_DispWindow_COLUMN, LCD_DispWindow_PAGE, BLACK);
	if (menu.getCurrentMenu() == Menu::vsBotGame
			&& playerNumber == Player::player2) {
		LCD_DrawString(90, LCD_DispWindow_PAGE / 2, "YOU LOSE");
		return;
	}
	char displayText[20];
	sprintf(displayText, "PLAYER %d WINS", playerNumber + 1);
	LCD_DrawString(70, LCD_DispWindow_PAGE / 2, displayText);
}

void Game::gaming() {

	switch (menu.getCurrentMenu()) {
	case Menu::vsWallGame:
		if (!start) {
			LCD_DrawPlayer(player[Player::player1].getX(),
					player[Player::player1].getY(), WHITE);
			LCD_DrawBall(ball.x, ball.y, WHITE);
			player[Player::player1].score.setPoint(10);
			player[Player::player2].score.setPoint(10);
			player[Player::player2].setX(playerNotTouching);
		}
		setStart(true);
		displayPlayerMovement(Player::player1);
		displayBallMovement();
		LCD_DrawNet();
		break;
	case Menu::vsBotGame:
		if (!start) {
			LCD_DrawPlayer(player[Player::player1].getX(),
					player[Player::player1].getY(), WHITE);
			LCD_DrawPlayer(player[Player::player2].getX(),
					player[Player::player2].getY(), WHITE);
			LCD_DrawBall(ball.x, ball.y, WHITE);
			player[Player::player1].score.setPoint(0);
			player[Player::player2].score.setPoint(0);
		}
		setStart(true);
		displayPlayerMovement(Player::player1);
		displayPlayerMovement(Player::player2);
		displayBallMovement();
		LCD_DrawNet();
		break;
	case Menu::twoPlayersGame:
		if (!start) {
			LCD_DrawPlayer(player[Player::player1].getX(),
					player[Player::player1].getY(), WHITE);
			LCD_DrawPlayer(player[Player::player2].getX(),
					player[Player::player2].getY(), WHITE);
			LCD_DrawBall(ball.x, ball.y, WHITE);
			player[Player::player1].score.setPoint(0);
			player[Player::player2].score.setPoint(0);
		}
		setStart(true);
		displayPlayerMovement(Player::player1);
		displayPlayerMovement(Player::player2);
		displayBallMovement();
		LCD_DrawNet();
		break;
	default:
		;
	}
	if (player[Player::player1].score.getPoint()
			== menu.settings.getPointsNeeded()) {
		displayWinner(Player::player1);
		HAL_Delay(5000);
		quit();
	}
	if (player[Player::player2].score.getPoint()
			== menu.settings.getPointsNeeded()) {
		displayWinner(Player::player2);
		HAL_Delay(5000);
		quit();
	}
}
Game::~Game() {
}

