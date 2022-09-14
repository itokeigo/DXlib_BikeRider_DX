/*****************************************************************//**
 * \file   PlayScene.h
 * \brief  
 * 
 * \author Ito Keigo
 * \date   2022
 *********************************************************************/
#pragma once

#include "../IScene.h"

class PlayScene : public IScene
{
private:

public:

	PlayScene();

	~PlayScene();

	void Initialize() override;

	GAME_SCENE Update() override;

	void Draw() override;

	void Finalize() override;
};