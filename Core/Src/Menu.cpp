#include <Menu.h>
#include "lcd.h"
#include "xpt2046.h"
#include <stdio.h>
Menu::Menu() {
	currentMenu = homeScreen;
}
int Menu::getCurrentMenu() {
	return currentMenu;
}
void Menu::displayCurrentMenu() {
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
		LCD_DrawString(70, 40, "Single Player");
		LCD_DrawEmptyRectangle(20, 80, 220, 130, WHITE);
		LCD_DrawString(70, 100, "Vs Bot");
		LCD_DrawEmptyRectangle(20, 160, 220, 210, WHITE);
		LCD_DrawString(70, 180, "Vs Wall");
		LCD_DrawEmptyRectangle(20, 240, 220, 290, WHITE);
		LCD_DrawString(100, 260, "Back");
		break;
	case settingsScreen:
		char resultsDisplay[10];
		LCD_Clear(LCD_DispWindow_Start_COLUMN, LCD_DispWindow_Start_PAGE,
		LCD_DispWindow_COLUMN, LCD_DispWindow_PAGE, BLACK);

		//Victory Condition button
		LCD_DrawEmptyRectangle(20, 10, 220, 60, WHITE);
		LCD_DrawString(30, 30, "Victory Condition:");
		sprintf(resultsDisplay, "%d", settings.getPointsNeeded());
		LCD_DrawString(180, 30, resultsDisplay);

		//Ball Speed Up Rate button
		LCD_DrawEmptyRectangle(20, 80, 220, 130, WHITE);
		LCD_DrawString(30, 100, "Ball Speed Up Rate:");
		sprintf(resultsDisplay, "%d", settings.getBallSpeedIncreaseRate());
		LCD_DrawString(180, 100, resultsDisplay);

		// Knockback button
		LCD_DrawEmptyRectangle(20, 160, 220, 210, WHITE);
		LCD_DrawString(30, 180, "Knockback:");
		if (settings.getKnockback()) {
			LCD_DrawString(180, 180, "ON");
		} else {
			LCD_DrawString(180, 180, "OFF");
		}

		// Back button
		LCD_DrawEmptyRectangle(20, 240, 220, 290, WHITE);
		LCD_DrawString(100, 260, "Back");
		break;
	case vsBotGame:
		LCD_Clear(LCD_DispWindow_Start_COLUMN, LCD_DispWindow_Start_PAGE,
		LCD_DispWindow_COLUMN, LCD_DispWindow_PAGE, BLACK);
		for (int i=0; i <= wallWidith; i++) {
			LCD_DrawLine(LCD_DispWindow_Start_COLUMN + i,
					LCD_DispWindow_Start_PAGE, LCD_DispWindow_Start_COLUMN + i,
					LCD_DispWindow_PAGE, WHITE);
			LCD_DrawLine(LCD_DispWindow_COLUMN - i, LCD_DispWindow_Start_PAGE,
					LCD_DispWindow_COLUMN - i, LCD_DispWindow_PAGE, WHITE);
		}
		LCD_DrawNet();
		break;
	case vsWallGame:
		LCD_Clear(LCD_DispWindow_Start_COLUMN, LCD_DispWindow_Start_PAGE,
		LCD_DispWindow_COLUMN, LCD_DispWindow_PAGE, BLACK);

		for (int i=0; i <= wallWidith; i++) {
			LCD_DrawLine(LCD_DispWindow_Start_COLUMN + i,
					LCD_DispWindow_Start_PAGE, LCD_DispWindow_Start_COLUMN + i,
					LCD_DispWindow_PAGE, WHITE);
			LCD_DrawLine(LCD_DispWindow_COLUMN - i, LCD_DispWindow_Start_PAGE,
					LCD_DispWindow_COLUMN - i, LCD_DispWindow_PAGE, WHITE);
			LCD_DrawLine(LCD_DispWindow_Start_COLUMN,
					LCD_DispWindow_Start_PAGE + i, LCD_DispWindow_COLUMN,
					LCD_DispWindow_Start_PAGE + i, WHITE);
		}
		LCD_DrawNet();
		break;
	case twoPlayersGame:
		LCD_Clear(LCD_DispWindow_Start_COLUMN, LCD_DispWindow_Start_PAGE,
		LCD_DispWindow_COLUMN, LCD_DispWindow_PAGE, BLACK);
		for (int i=0; i <= wallWidith; i++) {
			LCD_DrawLine(LCD_DispWindow_Start_COLUMN + i,
					LCD_DispWindow_Start_PAGE, LCD_DispWindow_Start_COLUMN + i,
					LCD_DispWindow_PAGE, WHITE);
			LCD_DrawLine(LCD_DispWindow_COLUMN - i, LCD_DispWindow_Start_PAGE,
					LCD_DispWindow_COLUMN - i, LCD_DispWindow_PAGE, WHITE);
		}
		LCD_DrawNet();
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
void Menu::onClickListiener() {
	strType_XPT2046_Coordinate strDisplayCoordinate;
	if (!XPT2046_Get_TouchedPoint(&strDisplayCoordinate,
			&strXPT2046_TouchPara)) {
		return;
	}
	switch (currentMenu) {
	case homeScreen:
		if (((strDisplayCoordinate.y > 80) && (strDisplayCoordinate.y < 130))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			setCurrentMenu(singlePlayerOptionsScreen);
		}
		if (((strDisplayCoordinate.y > 160) && (strDisplayCoordinate.y < 210))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			setCurrentMenu(twoPlayersGame);
		}
		if (((strDisplayCoordinate.y > 240) && (strDisplayCoordinate.y < 290))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			setCurrentMenu(settingsScreen);
		}

		break;
	case singlePlayerOptionsScreen:
		if (((strDisplayCoordinate.y > 80) && (strDisplayCoordinate.y < 130))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			setCurrentMenu(vsBotGame);
		}
		if (((strDisplayCoordinate.y > 160) && (strDisplayCoordinate.y < 210))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			setCurrentMenu(vsWallGame);
		}
		if (((strDisplayCoordinate.y > 240) && (strDisplayCoordinate.y < 290))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			setCurrentMenu(homeScreen);
		}
		break;
	case settingsScreen:
		char resultsDisplay[10];

		//Victory Condition button listener
		if (((strDisplayCoordinate.y > 10) && (strDisplayCoordinate.y < 60))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			settings.setPointsNeeded();
			sprintf(resultsDisplay, "%d", settings.getPointsNeeded());
			LCD_DrawString(180, 30, "   ");
			LCD_DrawString(180, 30, resultsDisplay);
		}

		//Ball Speed Up Rate button listener
		if (((strDisplayCoordinate.y > 80) && (strDisplayCoordinate.y < 130))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			settings.setBallSpeedIncreaseRate();
			sprintf(resultsDisplay, "%d",
					settings.getBallSpeedIncreaseRate());
			LCD_DrawString(180, 100, "    ");
			LCD_DrawString(180, 100, resultsDisplay);
		}

		// Knockback button listener
		if (((strDisplayCoordinate.y > 160) && (strDisplayCoordinate.y < 210))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			settings.setKnockback();
			LCD_DrawString(180, 180, "   ");
			if (settings.getKnockback()) {
				LCD_DrawString(180, 180, "ON");
			} else {
				LCD_DrawString(180, 180, "OFF");
			}
		}

		// Back button listener
		if (((strDisplayCoordinate.y > 240) && (strDisplayCoordinate.y < 290))
				&& ((strDisplayCoordinate.x > 20)
						&& (strDisplayCoordinate.x < 220))) {
			setCurrentMenu(homeScreen);
		}
		break;
	default:
		;
	}
}
Menu::~Menu() {
}

