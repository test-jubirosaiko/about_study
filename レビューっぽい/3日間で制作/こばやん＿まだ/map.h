#pragma once

#include "lib\appEnv.hpp"
#include <fstream>
#include "enemy.h"

enum Window {
	WIDTH = 400,
	HEIGHT = 400
};

enum {
	MAP_WIDTH = 10,
	MAP_HEIGHT = 10
};

void map_draw(std::ifstream& maps, Enemy& enemy, Texture& texture);