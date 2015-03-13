//
// アプリ雛形
//

#include "Player.h"


enum Window {
  WIDTH  = 800,
  HEIGHT = 950
};
//列挙型で弾の最大数を定義(?)
enum Bullet{
	MAX = 50
};

//Enemy型構造体を宣言(?)と定義(?)
struct Enemy{
	float x;
	float y;
	bool isDead;
}enemy;

//自機の撃った弾を構造体で宣言(?)と定義(?)
struct PlayerShot{
	float x;
	float y;
	float speed;
	bool judge;
	bool isDead;
}P_shot;

//敵の撃った弾を構造体で宣言(?)と定義(?)
struct EnemyShot{
	float x;
	float y;
	float speed;
	bool judge;
	bool isDead;
}E_shot;

//PlayerShot型のcreateShot関数を定義?
//引数ととしてplayerのx,yを渡してプレイヤーの表示位置を見てる
PlayerShot createShot(float player_x, float player_y ){
	//PlayerShot P_shot
	PlayerShot P_shot;
	P_shot.isDead = false;
	P_shot.x = player_x + 25;
	P_shot.y = player_y + 85;

	//46行で宣言しているPlayerShot P_shotに値を返している(P_shotを戻り値にしている?)
	return P_shot;
}
//外部参照でどっかにPlayer構造体のplayerがあると宣言?
extern Player player;

// 
// メインプログラム
// 
int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

  //初期化関数
  Init();

  //プレイヤーの弾の移動速度
  P_shot.speed = 15;
  
  unsigned int i = 0;
  unsigned int e = 0;
  int counter = 0;

  enemy.x = -350;
  enemy.y = 400;
  enemy.isDead = false;
  float enemy_x = 0;
  float enemy_y = 0;

  //PlayerShot型のvectorであるP_shotsを宣言?
  std::vector<PlayerShot>P_shots;
  //PlayerShot型のいてれーたーitを宣言?
  std::vector<PlayerShot>::iterator it;
  //itを先頭を指さすいてれーたーにしている?
  it = P_shots.begin();

  while (env.isOpen()) {

	  // 自機の移動処理
	  PlayerMove(env, player);

	  // 弾の生成
	  if (counter >0)
		counter--;
	  if (env.isPressKey(GLFW_KEY_SPACE) && P_shots.size() != Bullet::MAX){
		  if (counter <= 0){
			  P_shots.push_back(createShot(player.x, player.y));
			  counter = 3;
		  }
	  }

    env.setupDraw();
	// 弾の移動
	for ( i = 0; i < P_shots.size(); ++i){
		P_shots[i].y += P_shot.speed;
		drawFillCircle(P_shots[i].x, P_shots[i].y, 5, 5, 10,
			Color(1, 1, 1));
		
		// 弾の消滅条件 
		if (P_shots[i].y > 1200){
			P_shots[i].isDead = true;
		}
	}

	for (i = 0; i < P_shots.size(); ++i){
		if (!P_shots[i].isDead){
			break;
		}
	}
	if (i == P_shots.size()){
		P_shots.clear();
	}

	// 敵の処理
	for (e = 0; e < 10; ++e){
		enemy_x = enemy.x + 70 * e;
		drawFillBox(enemy_x, enemy.y, 60, 60,
			Color(1, 1, 1));
	}

	drawFillBox(player.x, player.y, 50, 80,
		Color(1, 1, 1));

    env.update();
  }
}
