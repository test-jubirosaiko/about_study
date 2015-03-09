//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "macro.h"
#include <iostream>



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
	bool Hit_player;
	bool Hit_block;

}ball;


struct Block
{
	float x;
	float y;
	float size_x;
	float size_y;
	Color color;
	bool Live;

}block[BLOCK_MAX];

struct Box
{
	float x;
	float y;
	float size_x;
	float size_y;
	Color color;
	bool Live;
}box;


//初期化関数
void Init()
{
	//自機
	player.x = -50;
	player.y = -HEIGHT / 2 + 50;
	player.size_x = 100;
	player.size_y = 15;
	player.color = Color(1, 1, 1);
	player.speed_x = 3;

	//弾
	ball.x = player.x + player.size_x / 2;
	ball.y = player.y + player.size_y + ball.r;
	ball.r = 10;
	ball.p = 100;
	ball.color = Color(1, 1, 1);
	ball.Start_ball = false;
	ball.speed_x = 5;
	ball.speed_y = 5;

	box.x = (-WIDTH / 2 + 30);
	box.y = (-HEIGHT / 2 + 250);
	box.size_x = 100;
	box.size_y = 30;
	box.Live = true;
	box.color = Color(1, 1, 1);
}

//自機移動
void Move_player(AppEnv &env)
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

//ボールの動き(途中)
void Move_ball(AppEnv &env)
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
	//死亡時
	if (ball.y < player.y)
	{
		ball.Start_ball = false;
	}
	if (ball.Hit_player)
	{
		ball.y += ball.r;
		ball.speed_y *= -1;
		ball.Hit_player = false;
	}
}

//ボールとプレイヤーの当たり判定
bool isHit_player()
{
	if (ball.x < player.x + player.size_x)
	{
		if (ball.x + ball.r > player.x)
		{
			if (ball.y < player.y + player.size_y)
			{
				return ball.Hit_player = true;
			}
		}
	}
	return ball.Hit_player = false;
}

//ボールとブロックの当たり判定
/*
bool isHit_block(Ball ball, Block block[BLOCK_MAX])
{
	if (ball.x <= block[BLOCK_MAX].x + block[BLOCK_MAX].size_x)
	{
		if (ball.x + ball.r >= block[BLOCK_MAX].x)
		{
			if (ball.y <= block[BLOCK_MAX].y + block[BLOCK_MAX].size_y)
			{
				return  false;
				drawFillBox(0, 0, 100, 100,Color(1, 1, 1));
			}
		}
	}
	return  true;
}*/

//自機描画
void Draw_player()
{
	//自機
	drawFillBox(player.x, player.y,
		player.size_x, player.size_y,
		player.color);
}

//ボール描画
void Draw_ball()
{
	//ボール
	drawFillCircle(ball.x, ball.y,
		ball.r, ball.r, ball.p,
		ball.color);
}

void Draw_Block1(){
	//ブロック1
	for (int i = 0; i < BLOCK_MAX; ++i)
	{
		block[i].x = (-WIDTH / 2 + 30);
		block[i].y = (-HEIGHT / 2 + 250) + (i * 55);
		block[i].size_x = 100;
		block[i].size_y = 30;
		block[i].Live = true;
		block[i].color = Color(1, 1, 1);

			if (block[i].Live)
			{
				drawFillBox(block[i].x, block[i].y,
					block[i].size_x, block[i].size_y,
					block[i].color);
			}
		
		//	std::cout << isHit_block << std::endl;
	}
}

// 
// メインプログラム
// 
int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	int Scene_mode = 0;

	Init();


	while (env.isOpen()) {

		//自機移動
		Move_player(env);
		Move_ball(env);
		isHit_player();
		

		env.setupDraw();

		
		//isHit_block(ball, block);
		/*
		デバッグ確認用コマンド①
		std::cout << ball.Start_ball << std::endl;
		*/


		//ブロック左から1～5
		Draw_Block1( );
		/*
		//ブロック2
		for (int i = 0; i < BLOCK_MAX; ++i)
		{
		block[i].x = (-WIDTH / 2 + 30) + 130;
		block[i].y = (-HEIGHT / 2 + 250) + (i * 55);
		block[i].size_x = 100;
		block[i].size_y = 30;
		block[i].Live = true;
		block[i].color = Color(1, 1, 1);

		if (block[i].Live)
		{
		drawFillBox(block[i].x, block[i].y,
		block[i].size_x, block[i].size_y,
		block[i].color);
		}
		}

		//ブロック3
		for (int i = 0; i < BLOCK_MAX; ++i)
		{
		block[i].x = (-WIDTH / 2 + 30) + 260;
		block[i].y = (-HEIGHT / 2 + 250) + (i * 55);
		block[i].size_x = 100;
		block[i].size_y = 30;
		block[i].Live = true;
		block[i].color = Color(1, 1, 1);

		if (block[i].Live)
		{
		drawFillBox(block[i].x, block[i].y,
		block[i].size_x, block[i].size_y,
		block[i].color);
		}
		}
		//ブロック4
		for (int i = 0; i < BLOCK_MAX; ++i)
		{
		block[i].x = (-WIDTH / 2 + 30) + 390;
		block[i].y = (-HEIGHT / 2 + 250) + (i * 55);
		block[i].size_x = 100;
		block[i].size_y = 30;
		block[i].Live = true;
		block[i].color = Color(1, 1, 1);

		if (!block[i].Live)
		{
		drawFillBox(block[i].x, block[i].y,
		block[i].size_x, block[i].size_y,
		block[i].color);
		}
		}
		//ブロック5
		for (int i = 0; i < BLOCK_MAX; ++i)
		{
		block[i].x = (-WIDTH / 2 + 30) + 520;
		block[i].y = (-HEIGHT / 2 + 250) + (i * 55);
		block[i].size_x = 100;
		block[i].size_y = 30;
		block[i].Live = true;
		block[i].color = Color(1, 1, 1);

		if (block[i].Live)
		{
		drawFillBox(block[i].x, block[i].y,
		block[i].size_x, block[i].size_y,
		block[i].color);
		}
		}

		//ブロック6
		for (int i = 0; i < BLOCK_MAX; ++i)
		{
		block[i].x = (-WIDTH / 2 + 30) + 650;
		block[i].y = (-HEIGHT / 2 + 250) + (i * 55);
		block[i].size_x = 100;
		block[i].size_y = 30;
		block[i].Live = true;
		block[i].color = Color(1, 1, 1);

		if (block[i].Live)
		{
		drawFillBox(block[i].x, block[i].y,
		block[i].size_x, block[i].size_y,
		block[i].color);
		}
		}
		*/
		Draw_ball();
		Draw_player();

		env.update();
	}
}