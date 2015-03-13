//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"

enum Window {
	WIDTH = 512,
	HEIGHT = 512
};

enum { GUN_MAX = 20 };
struct Gun
{
	bool active;
	int direction;
	float x;
	float y;
	float r;
	float speed_x;
	float speed_y;
	Color color;
}gun[GUN_MAX];

struct Point
{
	bool snipe;
	float x;
	float y;
	float r;
}point;


struct Triangle
{
	float x;
	float y;
	float r;
	float angle;
}triangle;

void Init(Random& random)
{
	for (int i = 0; i < GUN_MAX; i++){
		gun[i].active = false;
		gun[i].x = 0;
		gun[i].y = 0;
		gun[i].r = 10;
		gun[i].direction = 4;
		gun[i].speed_x = 4;
		gun[i].speed_y = 4;
		gun[i].color.red() = random.fromFirstToLast(0.0f, 1.0f);
		gun[i].color.green() = random.fromFirstToLast(0.0f, 1.0f);
		gun[i].color.blue() = random.fromFirstToLast(0.0f, 1.0f);
	}
	triangle.x = 0;
	triangle.y = 0;
	triangle.r = 50;
	triangle.angle = 0;
	point.snipe = false;
	point.x = 100;
	point.y = 0;
	point.r = 5;

}

void Gun_Create(AppEnv& env)
{
	if (env.isPushButton(Mouse::LEFT))
	{
		for (int i = 0; i < GUN_MAX; i++){
			point.snipe = true;
			if (!gun[i].active)
			{
				gun[i].active = true;
				break;
			}
		}
	}
}

void Gun_Move(AppEnv& env)
{
	
	for (int i = 0; i < GUN_MAX; i++){
		if (gun[i].active && gun[i].direction == 1)
		{
			gun[i].y += gun[i].speed_y;
		}
		if (gun[i].active && gun[i].direction == 2)
		{
			gun[i].y -= gun[i].speed_y;
		}
		if (gun[i].active && gun[i].direction == 3)
		{
			gun[i].x -= gun[i].speed_x;
		}
		if (gun[i].active && gun[i].direction == 4)
		{
			gun[i].x += gun[i].speed_x;
		}

		if (gun[i].x == 0 && gun[i].y == 220)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == -100 && gun[i].y == 220)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == -220 && gun[i].y == 220)
		{
			gun[i].direction = 2;
		}
		if (gun[i].x == -220 && gun[i].y == 0)
		{
			gun[i].direction = 2;
		}
		if (gun[i].x == -220 && gun[i].y == -220)
		{
			gun[i].direction = 4;
		}
		if (gun[i].x == 220 && gun[i].y == -220)
		{
			gun[i].direction = 1;
		}
		if (gun[i].x == 220 && gun[i].y == 220)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == 100 && gun[i].y == 220)
		{
			gun[i].direction = 2;
		}
		if (gun[i].x == 100 && gun[i].y == -100)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == -100 && gun[i].y == -100)
		{
			gun[i].direction = 1;
		}

	}
}



void Aim(AppEnv& env)
{
	if (!point.snipe)
	{
		for (int i = 0; i < GUN_MAX; i++){
			if (env.isPushKey(GLFW_KEY_UP))
			{
				point.x = 0;
				point.y = 100;
				gun[i].direction = 1;

			}

			if (env.isPushKey(GLFW_KEY_DOWN))
			{
				point.x = 0;
				point.y = -100;
				gun[i].direction = 2;

			}

			if (env.isPushKey(GLFW_KEY_LEFT))
			{
				point.x = -100;
				point.y = 0;
				gun[i].direction = 3;

			}

			if (env.isPushKey(GLFW_KEY_RIGHT))
			{
				point.x = 100;
				point.y = 0;
				gun[i].direction = 4;
			}
			else { gun[i].direction == 4; }
		}
	}
}

void Bound(int sign)
{
	for (int i = 0; i < GUN_MAX; i++){
		if ((gun[i].x >= WIDTH / 2) || (gun[i].x <= -WIDTH / 2))
		{
			gun[i].speed_x *= sign;
		}
		if ((gun[i].y >= HEIGHT / 2) || (gun[i].y <= -HEIGHT / 2))
		{
			gun[i].speed_y *= sign;
		}
	}
}


void Triangle_Move(AppEnv& env)
{
	if (env.isPressKey(GLFW_KEY_LEFT))
	{
		triangle.x -= 4;
	}
	if (env.isPressKey(GLFW_KEY_RIGHT))
	{
		triangle.x += 4;
	}
	if (env.isPressKey(GLFW_KEY_UP))
	{
		triangle.y += 4;
	}
	if (env.isPressKey(GLFW_KEY_DOWN))
	{
		triangle.y -= 4;
	}
	if (env.isPressKey('A'))
	{
		triangle.angle += 0.05f;
	}
	if (env.isPressKey('D'))
	{
		triangle.angle -= 0.05f;
	}
}

void Reset(AppEnv& env)
{
	for (int i = 0; i < GUN_MAX; ++i){
		if (env.isPushKey('R'))
		{
			gun[i].active = false;
			gun[i].x = 0;
			gun[i].y = 0;
			point.snipe = false;

		}
	}
}

void Draw()
{

	int b_point_x[] = { 0, -100, -220, -220, -220, 220, 220, 100, 100, -100 };
	int b_point_y[] = { 220, 220, 220, 0, -220, -220, 220, 220, -100, -100 };
	for (int i = 0; i < GUN_MAX; i++){
		if (gun[i].active){
			drawFillCircle(gun[i].x, gun[i].y, gun[i].r, gun[i].r, 100, gun[i].color);
		}
		drawPoint(b_point_x[i], b_point_y[i], 10, Color(1, 0, 0));
	}
	if (!point.snipe)
	{
		drawPoint(point.x, point.y, point.r, Color(1, 0, 0));
	}

}
// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	Random random;
	Init(random);
	const int sign = -1;
	while (env.isOpen()) {
		//Triangle_Move(env);
		if (env.isPushKey(GLFW_KEY_ESCAPE)) return 0;
		//生成処理
		Gun_Create(env);

		//移動処理
		Gun_Move(env);

		//跳ね返り処理
		Bound(sign);

		//照準処理
		Aim(env);

		//リセット処理
		Reset(env);
		triangle.angle += 0.05f;

		

		env.setupDraw();

		Draw();

		triangle.angle = 3.15f;
		
		

		drawFillCircle(triangle.x + 50, HEIGHT / 2 - 70, triangle.r, triangle.r, 3, Color(1, 1, 1), triangle.angle, Vec2f(2, 1), Vec2f(0, 50));
		env.update();
	}
}
