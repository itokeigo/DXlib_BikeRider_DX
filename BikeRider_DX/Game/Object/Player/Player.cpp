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
	mJumpVel = 0;
}

void Player::Update()
{
	// 移動方向を取得
	Float2 moveDirection = this->InputPlayer();
	
	// 移動させる
	Movement(moveDirection.mX * MOVE_SPEED);
	
	// ジャンプさせる
	MoveJump();

	// 線との当たり判定
	//this->CheckCollision();

	// 押し出しをするなら処理する
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
	// 方向キーを入力しているかを取得
	//bool isU = CheckHitKey(KEY_INPUT_UP);
	//bool isD = CheckHitKey(KEY_INPUT_DOWN);
	bool isL = CheckHitKey(KEY_INPUT_LEFT);
	bool isR = CheckHitKey(KEY_INPUT_RIGHT);

	// 入力された方向キーから移動方向を計算
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
	static float vel=10;
	if (!mIsJump && key->InputChackKey(CheckHitKey(KEY_INPUT_SPACE)) == eKEY_STATE::PUSH)
	{
		mJumpVel = 20;
		vel = 10;
		mIsJump = true;
	}

	

	if (mJumpVel > 0.01)
	{
		mPosition.mY -= mJumpVel;
		mJumpVel *= 0.85;
	}
	else
	{
		mPosition.mY += vel;
		vel += vel;
		if (mPosition.mY > SCREEN_HEIGHT-100)
		{
			mIsJump = false;
			mPosition.mY = SCREEN_HEIGHT - 100;
		}
	}

	
}
