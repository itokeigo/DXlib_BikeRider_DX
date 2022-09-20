/*****************************************************************//**
 * \file   PlayScene.h
 * \brief  
 * 
 * \author Ito Keigo
 * \date   2022
 *********************************************************************/
#pragma once

#include "../IScene.h"
class Player;
class BackGround;
class PlayScene : public IScene
{
private:
	// ÉvÉåÉCÉÑÅ[
	Player* mpPlayer;
	BackGround* mpBG;

public:

	PlayScene();

	~PlayScene();

	void Initialize() override;

	GAME_SCENE Update() override;

	void Draw() override;

	void Finalize() override;
private:

	void DeletePoint();
};