#ifndef INC_SETTINGS_H_
#define INC_SETTINGS_H_
//#include <iostream>
class Settings {
private:
int pointsNeeded;
int ballSpeedIncreaseRate;
bool knockback;
public:
	Settings();
void setPointsNeeded();
int getPointsNeeded();
void setBallSpeedIncreaseRate();
int getBallSpeedIncreaseRate();
void setKnockback();
bool getKnockback();
void displayValues();
	virtual ~Settings();
};

#endif /* INC_SETTINGS_H_ */
