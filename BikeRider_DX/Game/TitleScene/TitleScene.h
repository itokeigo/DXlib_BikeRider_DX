/*****************************************************************//**
 * \file   TitleScene.h
 * \brief  
 * 
 * \author Ito Keigo
 * \date   2022
 *********************************************************************/
#pragma once

#include "../IScene.h"

class CountDown;
class Button;
class TitleRogo;
class TitleScene : public IScene
{
	enum eButtonName
	{
		StartButton,
		ExitButton,
		Num,
	};
private:

	Button* mpButton[eButtonName::Num];
	TitleRogo* mpRogo;

	CountDown* mCount;
public:

	TitleScene();

	~TitleScene();

	void Initialize() override;

	GAME_SCENE Update() override;

	void Draw() override;

	void Finalize() override;
};