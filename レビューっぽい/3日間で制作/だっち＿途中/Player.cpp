#include "Player.h"

//Player�^�\���̂�player��錾
Player player;

//�������̊֐�
void Init(){
	player.x = -25.0;
	player.y = -300.0;
	player.life = 3;
	player.life = 5;
	player.speed_x = 8.0;
	player.slow_speed_x = 4.0;
}

// ���@�̈ړ������̊֐�
void PlayerMove(AppEnv& env, Player& player){
	// ���@�̈ړ�����
	//���̃V�t�g�L�[�����Ă���Ԃ��E�L�[���������Ă���Ԃ���player.x��350�ȉ��̂Ƃ��Aplayer.x��player.slow_speed_x�𑫂�������
	if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350){
		player.x += player.slow_speed_x;
	}
	//���if����true����������s���Ȃ�
	//�E�L�[��������Ă��邩��player.x��350�ȉ���������player.x��player.speed_x�𑫂�������
	else if (env.isPressKey(GLFW_KEY_RIGHT) && player.x <= 350){
		player.x += player.speed_x;
	}
	//���if����true����������s���Ȃ�
	//���V�t�g�L�[��������Ă��邩���L�[��������Ă��邩��player.x��-400�ȏゾ������player.x��player.slow_speed_x������������
	if (env.isPressKey(GLFW_KEY_LEFT_SHIFT) && env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400){
		player.x -= player.slow_speed_x;
	}
	//���if����true����������s���Ȃ�
	//�E�L�[��������Ă��邩��player.x���[400�ȉ���������player.x��player.speed_x������������
	else if (env.isPressKey(GLFW_KEY_LEFT) && player.x >= -400){
		player.x -= player.speed_x;
	}
	//��ʂ���͂ݏo���Ȃ��悤�ɂ���ȏ㓮���Ȃ��悤�ɂ��Ă���
	if (player.x >= 350){
		player.x = 350;
	}
	//��ʂ���͂ݏo���Ȃ��悤�ɂ���ȏ㓮���Ȃ��悤�ɂ��Ă���
	if (player.x <= -400){
		player.x = -400;
	}
}