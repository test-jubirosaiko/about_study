#pragma once

#include "lib\appEnv.hpp"

struct Enemy{
	Vec2f start_point;
	int width, height;
	int tex_width, tex_height;
};


void enemy_init(Enemy& enemy);

void enemy_draw(Enemy& enemy, Texture& texture);
