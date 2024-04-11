#include <Ball.h>
#include "lcd.h"
Ball::Ball() {
	x = LCD_DispWindow_COLUMN / 2;
	y = LCD_DispWindow_PAGE / 2;
	dx = 1;
	dy = 1;
}
void Ball::reset() {
	x = LCD_DispWindow_COLUMN / 2;
	y = LCD_DispWindow_PAGE / 2;
	dx = 1;
	dy = 1;
}
Ball::~Ball() {}

