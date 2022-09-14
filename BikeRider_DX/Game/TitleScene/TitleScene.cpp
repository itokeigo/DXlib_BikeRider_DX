
#include "TitleScene.h"

#include "../GameMain.h"
#include"../Libraries/MyLibrarys/Button.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	mpButton[eButtonName::StartButton] = new Button();
	mpButton[eButtonName::StartButton]->CreateButton("�Q�[���X�^�[�g", SCREEN_CENTER_X, SCREEN_CENTER_Y,0,50,50);
	mpButton[eButtonName::ExitButton] = new Button();
	mpButton[eButtonName::ExitButton]->CreateButton("�Q�[���I��", SCREEN_CENTER_X, SCREEN_CENTER_Y + 200);
}

GAME_SCENE TitleScene::Update()
{
	if (mpButton[eButtonName::StartButton]->ChackeButton() == Button::BUTTON_STATE::BUTTON_RELEASE)
	{
		// �Q�[���V�[���ֈڍs
		return GAME_SCENE::PLAY;

	}

	if (mpButton[eButtonName::ExitButton]->ChackeButton() == Button::BUTTON_STATE::BUTTON_RELEASE)
	{
		// �Q�[���I���{�^�����������ۂ̏���
		DxLib_End();
	}
	return GAME_SCENE::NONE;
}

void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(100, 255, 100));
	mpButton[eButtonName::StartButton]->Render(GetColor(255, 0, 0), true, GetColor(255, 255, 255));

	mpButton[eButtonName::ExitButton]->Render(GetColor(255, 0, 0), true, GetColor(255, 255, 255));
}

void TitleScene::Finalize()
{
}