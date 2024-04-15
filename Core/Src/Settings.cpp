#include <Settings.h>

Settings::Settings() {
	pointsNeeded = 2;
	ballSpeedIncreaseRate = 1;
	knockback = true;
}

void Settings::setPointsNeeded(){
	if(pointsNeeded<9){
		pointsNeeded++;
	}else{
		pointsNeeded = 2;
	}
}
int Settings::getPointsNeeded(){
	return pointsNeeded;
}
void Settings::setBallSpeedIncreaseRate(){
	if(ballSpeedIncreaseRate < 10){
		ballSpeedIncreaseRate++;
	}else{
		ballSpeedIncreaseRate =1;
	}
}
int Settings::getBallSpeedIncreaseRate(){
	return ballSpeedIncreaseRate;
}
void Settings::setKnockback(){
	knockback = !knockback;
}
bool Settings::getKnockback(){
	return knockback;
}
Settings::~Settings() {}

