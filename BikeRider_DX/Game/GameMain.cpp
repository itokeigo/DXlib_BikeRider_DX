/*****************************************************************//**
 * \file   GameMain.cpp
 * \brief  ゲーム関連のソースファイル
 * 
 * \author Ito Keigo
 * \date   2022
 *********************************************************************/


#include "GameMain.h"

#include "TitleScene/TitleScene.h"
#include "PlayScene/PlayScene.h"


// 定数==============================================================



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
	// タイトルシーンの作成
	mpScene = new TitleScene();
	mpScene->Initialize();
}


void GameMain::UpdateGame()
{
	if (mNextScene != GAME_SCENE::NONE)
	{
		// シーン削除
		DeleteScene();
		
		// シーン作成
		CreateScene();
	}

	// 存在していれば更新
	if (mpScene != nullptr)
	{
		mNextScene = mpScene->Update();
	}
}


void GameMain::RenderGame()
{
	int mFrame = 10;
	//背景の描画
	DrawBox(0, 0, SCREEN_RIGHT, SCREEN_HEIGHT, GetColor(0, 0, 0), true);
	DrawBox(0 + mFrame, 0 + mFrame, SCREEN_RIGHT - mFrame, SCREEN_HEIGHT - mFrame, GetColor(255, 255, 255), true);

	//描画
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
 * 関数名　　CreateScene
 * 概要　　　シーン生成をする関数
 * 引数　　　無し
 * 戻り値　　無し
 */
void GameMain::CreateScene()
{

	if (mpScene != nullptr)
	{
		return;
	}

	// シーンの作成
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
			// 例外なので処理を中断
			return;
		}
	}

	// シーンを初期化
	mpScene->Initialize();
}

/**
 * 関数名　　DeleteScene
 * 概要　　　シーン削除する関数
 * 引数　　　無し
 * 戻り値　　無し
 */
void GameMain::DeleteScene()
{
	if (mpScene == nullptr)
	{
		return;
	}

	// シーン終了処理
	mpScene->Finalize();

	// シーン削除
	delete mpScene;
	mpScene = nullptr;
}
