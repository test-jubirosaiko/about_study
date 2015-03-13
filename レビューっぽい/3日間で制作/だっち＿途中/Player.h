#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


//プレイヤー型の構造体を宣言
struct Player{
	float x;
	float y;
	float speed_x;
	float slow_speed_x;
	float life;
};

//初期化用関数のプロトタイプ宣言
void Init();
//プレイヤーの移動処理用関数のプロトタイプ宣言
void PlayerMove(AppEnv& env, Player& player);