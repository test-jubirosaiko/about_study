#include "mouse.h"

void mouse_init(MOUSE& mouse){
	mouse.width = 100;
	mouse.height = 100;
	mouse.tex_width = 256;
	mouse.tex_height = 256;
}

void mouse_draw(MOUSE& mouse, Texture& texture){
	float draw_x = mouse.pos.x() - mouse.width / 2;
	float draw_y = mouse.pos.y() - mouse.height / 2;

	drawTextureBox(draw_x, draw_y, mouse.width, mouse.height,
		0, 0, mouse.tex_width, mouse.tex_height, texture, Color(1, 1, 1));
}