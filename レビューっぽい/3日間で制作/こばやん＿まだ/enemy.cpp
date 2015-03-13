#include "enemy.h"

void enemy_init(Enemy& enemy){
	enemy.start_point = Vec2f(-50, -100);
	enemy.width = 100;
	enemy.height = 200;
	enemy.tex_width = 512;
	enemy.tex_height = 512;
}

void enemy_draw(Enemy& enemy, Texture& texture){

	drawTextureBox(enemy.start_point.x(), enemy.start_point.y(), enemy.width, enemy.height,
		0, 0,enemy.tex_width, enemy.tex_height, texture, Color(1, 1, 1));

}