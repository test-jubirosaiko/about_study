//
// アプリ雛形
//


#include "lib/appEnv.hpp"
#include "lib/defines.hpp"
#include "mouse.h"
#include "enemy.h"
#include "collision.h"
#include "map.h"

MOUSE mouse;
Enemy enemy;

// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	Texture cursor("res/cursor.png");
	Texture QB("res/enemy_QB.png");
	Texture QB_hit("res/enemy_QB_HIT.png");
	std::ifstream map("res/map01.txt");

	env.bgColor(Color(1, 1, 1));

	mouse_init(mouse);
	enemy_init(enemy);
	
	while (env.isOpen()) {
		mouse.pos = env.mousePosition();

		env.setupDraw();

		map_draw(map, enemy, QB);


		if (mouse_on_enemy(mouse, enemy) && env.isPushButton(Mouse::LEFT)){
			enemy_draw(enemy, QB_hit);
		}
		else{ enemy_draw(enemy, QB); }

		
		mouse_draw(mouse, cursor);

		env.update();
	}
}
