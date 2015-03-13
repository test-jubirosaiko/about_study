#include "map.h"

int map[MAP_WIDTH][MAP_HEIGHT];

void map_draw(std::ifstream& maps, Enemy& enemy, Texture& texture){
	for (int y = 0; y < MAP_WIDTH; ++y){
		for (int x = 0; x < MAP_HEIGHT; ++x){
			maps >> map[y][x];

			if (map[y][x] == 0){
				drawFillBox(-WIDTH / 2 + WIDTH / 10 * x, 
					(HEIGHT / 2 - HEIGHT / 10) - HEIGHT / 10 * y,
					WIDTH / 5, HEIGHT / 5, Color(1, 0, 1));
			}
			if (map[y][x] == 1){
				drawTextureBox(-WIDTH / 2 + WIDTH / 10 * x,
					(HEIGHT / 2 - HEIGHT / 10) - HEIGHT / 10 * y,
					WIDTH / 5, HEIGHT / 5,
					0, 0, enemy.tex_width*2, enemy.tex_height*2, // Ç±Ç±Ç™ìÒî{Ç…ÇµÇ»Ç¢Ç∆ï\é¶Ç≥ÇÍÇ»Ç¢
					texture, Color(1, 1, 1));					 // âΩÇ≈Ç©ÇÕÇÌÇ©ÇÁÇ»Ç¢(ÅLÅEÉ÷ÅE`)
			}
		}
	}
}