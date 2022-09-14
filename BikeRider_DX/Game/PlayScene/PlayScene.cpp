
#include "PlayScene.h"

#include "../GameMain.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
}

GAME_SCENE PlayScene::Update()
{
	return GAME_SCENE::NONE;
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PlayScene", GetColor(100, 255, 100));
}

void PlayScene::Finalize()
{
}
