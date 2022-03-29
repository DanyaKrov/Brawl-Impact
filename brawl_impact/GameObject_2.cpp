#include "GameObject.h"


void GameObject::restart() {
	is_dead = false;
	xpos = 0;
	ypos = 0;
	x_speed = 3;
	y_speed = 5;
	coef = 1;
}