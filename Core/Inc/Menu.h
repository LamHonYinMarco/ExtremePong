#ifndef INC_MENU_H_
#define INC_MENU_H_
#include "Settings.h"
class Menu {
private:
	int currentMenu;
	Settings settings;
public:
	enum menuNames{homeScreen,singlePlayerOptionsScreen,settingsScreen,vsBotGame,vsWallGame,twoPlayersGame};
	Menu();
	//TODO onClickListener
	void setCurrentMenu(int menu);
	void displayCurrentMenu();
	int getCurrentMenu();
	void onClickListiener();
	virtual ~Menu();
};

#endif /* INC_MENU_H_ */
