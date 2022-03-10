#include "game.h"

class Hero
{
public:
	int x_coord;
	int y_coord;
	string direction = "N";
	int speed = 0;
	void walking() {
		speed = 2.0;
	}
	void running() {
		speed = 3.5;
	}
	void step() {

	}
};