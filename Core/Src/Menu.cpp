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
		LCD_Clear(LCD_DispWindow_Start_COLUMN,LCD_DispWindow_Start_PAGE,LCD_DispWindow_COLUMN,LCD_DispWindow_PAGE,BLACK);

		break;
	case singlePlayerOptionsScreen:

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

