
#include "PlayScene.h"

#include "../GameMain.h"
#include"../Object/Player/Player.h"
#include"../BackGround.h"
PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	mpPlayer = new Player();
	mpPlayer->Initialize();
	mpBG = new BackGround();
	mpBG->Initialize();
}

GAME_SCENE PlayScene::Update()
{
	mpBG->Update();
	mpPlayer->Update();

	return GAME_SCENE::NONE;
}

void PlayScene::Draw()
{
	mpBG->Render();
	mpPlayer->Render();
	DrawString(0, 0, "PlayScene", GetColor(100, 255, 100));
}

void PlayScene::Finalize()
{
	mpBG->Finalize();
	mpPlayer->Finalize();

	DeletePoint();
}

void PlayScene::DeletePoint()
{
	delete mpPlayer;
	mpPlayer = nullptr;

	delete mpBG;
	mpBG = nullptr;
}
