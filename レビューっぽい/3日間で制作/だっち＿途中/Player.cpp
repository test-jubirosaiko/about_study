#include "Player.h"

//Player型構造体のplayerを宣言
Player player;

//初期化の関数
void Init(){
	player.x = -25.0;
	player.y = -300.0;
	player.life = 3;
	player.life = 5;
	player.speed_x = 8.0;
	player.slow_speed_x = 4.0;
}

// 自機の移動処理の関数
void PlayerMove(AppEnv& env, Player& player){
	// 自機の移動処理
	//左のシフトキー押している間かつ右キーをお押している間かつplayer.xが350以下のとき、player.xにplayer.slow_speed_xを足し続ける
	if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350){
		player.x += player.slow_speed_x;
	}
	//上のif文がtrueだったら実行しない
	//右キーが押されているかつplayer.xが350以下だったらplayer.xにplayer.speed_xを足し続ける
	else if (env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350){
		player.x += player.speed_x;
	}
	//上のif文がtrueだったら実行しない
	//左シフトキーが押されているかつ左キーが押されているかつplayer.xが-400以上だったらplayer.xにplayer.slow_speed_xを引き続ける
	if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400){
		player.x -= player.slow_speed_x;
	}
	//上のif文がtrueだったら実行しない
	//右キーが押されているかつplayer.xがー400以下だったらplayer.xにplayer.speed_xを引き続ける
	else if (env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400){
		player.x -= player.speed_x;
	}
	//画面からはみ出さないようにそれ以上動かないようにしている
	if (player.x >= 350){
		player.x = 350;
	}
	//画面からはみ出さないようにそれ以上動かないようにしている
	if (player.x <= -400){
		player.x = -400;
	}
}