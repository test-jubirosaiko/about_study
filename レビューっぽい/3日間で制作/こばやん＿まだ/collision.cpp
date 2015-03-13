#include "collision.h"

bool mouse_on_enemy(MOUSE& mouse, Enemy& enemy){
	if (mouse.pos.x() >= enemy.start_point.x() &&
		mouse.pos.x() <= enemy.start_point.x() + enemy.width){
		if (mouse.pos.y() >= enemy.start_point.y() &&
			mouse.pos.y() <= enemy.start_point.y() + enemy.height){
			return true;
		}
	}return false;
}