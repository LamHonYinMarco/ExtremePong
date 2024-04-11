#include <Settings.h>

Settings::Settings() {
	pointsNeeded = 2;
	ballSpeedIncreaseRate = 10;
	knockback = true;
}
void Settings::displayValues(){
	//TODO
}
void Settings::setPointsNeeded(){
	if(pointsNeeded<9){
		pointsNeeded++;
	}else{
		pointsNeeded = 2;
	}
	displayValues();
}
int Settings::getPointsNeeded(){
	return pointsNeeded;
}
void Settings::setBallSpeedIncreaseRate(){
	if(ballSpeedIncreaseRate < 100){
		ballSpeedIncreaseRate += 10;
	}else{
		ballSpeedIncreaseRate = 10;
	}
	displayValues();
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

