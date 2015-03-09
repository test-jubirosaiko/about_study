//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include <iostream>


enum Window {
	WIDTH = 640,
	HEIGHT = 880
};


struct Player
{
	float x;
	float y;
	float size_x;
	float size_y;
	/*
	float tx_x;
	float tx_y;
	float tx_width_x;
	float tx_height_y;
	*/
	Color color;
	float speed_x;
}player;

struct Ball
{
	float x;
	float y;
	float r;
	float p;
	Color color;
	bool Start_ball;
	float speed_x;
	float speed_y;

}ball;

//初期化関数
void Init()
{


	player.x = -50;
	player.y = -HEIGHT / 2 + 50;
	player.size_x = 100;
	player.size_y = 15;
	player.color = Color(1, 1, 1);
	player.speed_x = 3;


	ball.x = player.x + player.size_x / 2;
	ball.y = player.y + player.size_y + ball.r;
	ball.r = 10;
	ball.p = 100;
	ball.color = Color(1, 1, 1);
	ball.Start_ball = false;
	ball.speed_x = 5;
	ball.speed_y = 5;
}

//自機移動
void Player_move(AppEnv &env)
{

	//自機左右移動
	if (env.isPressKey(GLFW_KEY_LEFT))
	{
		if (player.x >= -WIDTH / 2)
		{
			player.x -= player.speed_x;
		}
	}
	if (env.isPressKey(GLFW_KEY_RIGHT))
	{
		if (player.x + player.size_x <= WIDTH / 2)
		{
			player.x += player.speed_x;
		}
	}

}

//ボールの動き
void Ball_move(AppEnv &env)
{
	//ゲーム開始時
	if (!ball.Start_ball)
	{
		ball.x = player.x + 50;
		
		//ボールを動かす
		if (env.isPushKey(GLFW_KEY_SPACE))
		{
			ball.Start_ball = true;
		}
	}
	//ゲームスタート
	if (ball.Start_ball)
	{
		ball.x += ball.speed_x;
		ball.y += ball.speed_y;
	}
	//ボールの方向転換
	//左右
	if (ball.x <= -WIDTH / 2)
	{
		ball.speed_x *= -1;
	}
	if (ball.x + ball.r >= WIDTH / 2)
	{
		ball.speed_x *= -1;
	}
	//上
	if (ball.y + ball.r >= HEIGHT / 2)
	{
		ball.speed_y *= -1;
	}
}


// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);



	Init();


	while (env.isOpen()) {

		//自機移動
		Player_move(env);
		Ball_move(env);

		env.setupDraw();

		/*
		デバッグ確認用コマンド①
		std::cout << ball.Start_ball << std::endl;
		*/


		//ボール
		drawFillCircle(ball.x, ball.y, ball.r, ball.r, ball.p, ball.color);

		//自機
		drawFillBox(player.x, player.y, player.size_x, player.size_y, player.color);

		env.update();
	}
}