
#include "PlayScene.h"

#include "../GameMain.h"
#include"../Object/Player/Player.h"

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
}

GAME_SCENE PlayScene::Update()
{
	mpPlayer->Update();

	return GAME_SCENE::NONE;
}

void PlayScene::Draw()
{
	mpPlayer->Render();
	DrawString(0, 0, "PlayScene", GetColor(100, 255, 100));
}

void PlayScene::Finalize()
{
	mpPlayer->Finalize();

	DeletePoint();
}

void PlayScene::DeletePoint()
{
	delete mpPlayer;
	mpPlayer = nullptr;
}
