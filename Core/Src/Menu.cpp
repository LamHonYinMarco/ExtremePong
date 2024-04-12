#include <Menu.h>
#include "lcd.h"

Menu::Menu() {
	currentMenu = homeScreen;
}
int Menu::getCurrentMenu() {
	return currentMenu;
}
void Menu::displayCurrentMenu() {
	//TODO
	switch (currentMenu) {
	case homeScreen:
		LCD_Clear(LCD_DispWindow_Start_COLUMN, LCD_DispWindow_Start_PAGE,
				LCD_DispWindow_COLUMN, LCD_DispWindow_PAGE, BLACK);
		LCD_DrawString(70, 40, "Extreme Pong");
		LCD_DrawEmptyRectangle(20, 80, 220, 130, WHITE);
		LCD_DrawString(70, 100, "Single Player");
		LCD_DrawEmptyRectangle(20, 160, 220, 210, WHITE);
		LCD_DrawString(70, 180, "Two Player");
		LCD_DrawEmptyRectangle(20, 240, 220, 290, WHITE);
		LCD_DrawString(70, 260, "Settings");
		break;
	case singlePlayerOptionsScreen:
		LCD_Clear(LCD_DispWindow_Start_COLUMN, LCD_DispWindow_Start_PAGE,
				LCD_DispWindow_COLUMN, LCD_DispWindow_PAGE, BLACK);
		LCD_DrawString(70, 40, "Extreme Pong");
		LCD_DrawEmptyRectangle(20, 80, 220, 130, WHITE);
		LCD_DrawString(70, 100, "Vs Bot");
		LCD_DrawEmptyRectangle(20, 160, 220, 210, WHITE);
		LCD_DrawString(70, 180, "Vs Wall");
		LCD_DrawEmptyRectangle(20, 240, 220, 290, WHITE);
		LCD_DrawString(70, 260, "Back");
		break;
	case settingsScreen:

		break;
	case vsBotGame:

		break;
	case vsWallGame:

		break;
	case twoPlayersGame:

		break;
	default:
		;
	}
}
void Menu::setCurrentMenu(int menu) {
	currentMenu = menu;
	displayCurrentMenu();
}
// TODO onClickListiener
Menu::~Menu() {
}

