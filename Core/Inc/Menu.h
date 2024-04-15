#ifndef INC_MENU_H_
#define INC_MENU_H_
#include "Settings.h"
class Menu {
private:
	int currentMenu;

public:
	enum menuNames{homeScreen,singlePlayerOptionsScreen,settingsScreen,vsBotGame,vsWallGame,twoPlayersGame,WinScreen,LoseScreen};
	Settings settings;
	Menu();
	void setCurrentMenu(int menu);
	void displayCurrentMenu();
	int getCurrentMenu();
	void onClickListiener();
	virtual ~Menu();
};

#endif /* INC_MENU_H_ */
