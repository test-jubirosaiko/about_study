#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


//�v���C���[�^�̍\���̂�錾
struct Player{
	float x;
	float y;
	float speed_x;
	float slow_speed_x;
	float life;
};

//�������p�֐��̃v���g�^�C�v�錾
void Init();
//�v���C���[�̈ړ������p�֐��̃v���g�^�C�v�錾
void PlayerMove(AppEnv& env, Player& player);