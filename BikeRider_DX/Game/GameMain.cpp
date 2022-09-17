/*****************************************************************//**
 * \file   GameMain.cpp
 * \brief  �Q�[���֘A�̃\�[�X�t�@�C��
 * 
 * \author Ito Keigo
 * \date   2022
 *********************************************************************/


#include "GameMain.h"

#include "TitleScene/TitleScene.h"
#include "PlayScene/PlayScene.h"


// �萔==============================================================



GameMain::GameMain()
	: mNextScene(GAME_SCENE::NONE)
	, mpScene(nullptr)
{
}

GameMain::~GameMain()
{
}

void GameMain::InitializeGame()
{
	// �^�C�g���V�[���̍쐬
	mpScene = new TitleScene();
	mpScene->Initialize();
}


void GameMain::UpdateGame()
{
	if (mNextScene != GAME_SCENE::NONE)
	{
		// �V�[���폜
		DeleteScene();
		
		// �V�[���쐬
		CreateScene();
	}

	// ���݂��Ă���΍X�V
	if (mpScene != nullptr)
	{
		mNextScene = mpScene->Update();
	}
}


void GameMain::RenderGame()
{
	int mFrame = 10;
	//�w�i�̕`��
	DrawBox(0, 0, SCREEN_RIGHT, SCREEN_HEIGHT, GetColor(0, 0, 0), true);
	DrawBox(0 + mFrame, 0 + mFrame, SCREEN_RIGHT - mFrame, SCREEN_HEIGHT - mFrame, GetColor(255, 255, 255), true);

	//�`��
	if (mpScene != nullptr)
	{
		mpScene->Draw();
	}
}


void GameMain::FinalizeGame()
{
	DeleteScene();
}
/**
 * �֐����@�@CreateScene
 * �T�v�@�@�@�V�[������������֐�
 * �����@�@�@����
 * �߂�l�@�@����
 */
void GameMain::CreateScene()
{

	if (mpScene != nullptr)
	{
		return;
	}

	// �V�[���̍쐬
	switch (mNextScene)
	{
		case GAME_SCENE::TITLE:
		{
			mpScene = new TitleScene();
			break;
		}
		case GAME_SCENE::PLAY:
		{
			mpScene = new PlayScene();
			break;
		}
		default:
		{
			// ��O�Ȃ̂ŏ����𒆒f
			return;
		}
	}

	// �V�[����������
	mpScene->Initialize();
}

/**
 * �֐����@�@DeleteScene
 * �T�v�@�@�@�V�[���폜����֐�
 * �����@�@�@����
 * �߂�l�@�@����
 */
void GameMain::DeleteScene()
{
	if (mpScene == nullptr)
	{
		return;
	}

	// �V�[���I������
	mpScene->Finalize();

	// �V�[���폜
	delete mpScene;
	mpScene = nullptr;
}
