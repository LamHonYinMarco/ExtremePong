#include <Ball.h>
#include "lcd.h"
Ball::Ball() {
	reset();
}
void Ball::reset() {
	x = (LCD_DispWindow_COLUMN / 2)-ballWidith;
	y = (LCD_DispWindow_PAGE / 2)-ballWidith;
	dx = 0;
	dy = 1;
}
Ball::~Ball() {}

