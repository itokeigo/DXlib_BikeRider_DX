
#include "TitleScene.h"

#include "../GameMain.h"


#include"../Libraries/MyLibrarys/Button.h"
#include"../../Libraries/MyLibrarys/CountDown.h"
#include"TitleRogo.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	mpButton[eButtonName::StartButton] = new Button();
	mpButton[eButtonName::StartButton]->CreateButton("ゲームスタート", SCREEN_CENTER_X, SCREEN_CENTER_Y,0,50,50);
	mpButton[eButtonName::ExitButton] = new Button();
	mpButton[eButtonName::ExitButton]->CreateButton("ゲーム終了", SCREEN_CENTER_X, SCREEN_CENTER_Y + 200);

	mpRogo = new TitleRogo("Resources//Textures//TITLE//TitleRogo.png");
	mpRogo->Initialize();
	mCount = new CountDown();
	mCount->Initialize();
}

GAME_SCENE TitleScene::Update()
{
	if (mpRogo->Update())
	{
		if (mpButton[eButtonName::StartButton]->ChackeButton() == Button::BUTTON_STATE::BUTTON_RELEASE)
		{
			// ゲームシーンへ移行
			return GAME_SCENE::PLAY;
		}

		if (mpButton[eButtonName::ExitButton]->ChackeButton() == Button::BUTTON_STATE::BUTTON_RELEASE)
		{
			// ゲーム終了ボタンを押した際の処理
			DxLib_End();
		}

		mCount->Update();
	}
	return GAME_SCENE::NONE;
}

void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(100, 255, 100));
	mpButton[eButtonName::StartButton]->Render(GetColor(255, 0, 0), true, GetColor(255, 255, 255));

	mpButton[eButtonName::ExitButton]->Render(GetColor(255, 0, 0), true, GetColor(255, 255, 255));
	mpRogo->Render();
	mCount->Render();
}

void TitleScene::Finalize()
{
	mpRogo->Finalize();
}
