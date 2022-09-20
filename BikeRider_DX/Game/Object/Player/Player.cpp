#include"Player.h"
#include"../../GameMain.h"
#include"../../../Libraries/MyLibrarys/InputKey.h"

const int Player::MOVE_SPEED = 4;

Player::Player()
{
	mHandle = LoadGraph("Resources//Textures//Object//Player.png");
}

Player::~Player()
{

}

void Player::Initialize()
{
	mPosition = Float2(200, 100);
}

void Player::Update()
{
	// �ړ��������擾
	Float2 moveDirection = this->InputPlayer();
	
	// �ړ�������
	Movement(moveDirection.mX * MOVE_SPEED);
	
	// �W�����v������
	MoveJump();

	// ���Ƃ̓����蔻��
	//this->CheckCollision();

	// �����o��������Ȃ珈������
	//if (m_isPush) { this->PushCollision(); }
}

void Player::Render()
{
	DrawGraph(mPosition.mX, mPosition.mY, mHandle, true);
}

void Player::Finalize()
{
}

int Player::InputPlayer()
{
	// �����L�[����͂��Ă��邩���擾
	//bool isU = CheckHitKey(KEY_INPUT_UP);
	//bool isD = CheckHitKey(KEY_INPUT_DOWN);
	bool isL = CheckHitKey(KEY_INPUT_LEFT);
	bool isR = CheckHitKey(KEY_INPUT_RIGHT);

	// ���͂��ꂽ�����L�[����ړ��������v�Z
	int x = isR - isL;
	return x;
}

void Player::Movement(int vel)
{
	mPosition.mX += vel;
}

void Player::MoveJump()
{
	auto key = InputKey::GetInstance();
	mPosition.mY += 10;
	if(key->InputChackKey(CheckHitKey(KEY_INPUT_SPACE))==eKEY_STATE::PUSH)
		mPosition.mY -= 50;

	if (mPosition.mY > SCREEN_HEIGHT-100)
		mPosition.mY = SCREEN_HEIGHT - 100;
}
