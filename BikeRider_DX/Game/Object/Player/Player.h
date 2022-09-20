/*****************************************************************//**
 * \file   Player.h
 * \brief  
 * 
 * \author Ito Keigo
 * \date   2022
 *********************************************************************/
#pragma once
#include"../../Utility.h"
class Player
{
    static const int MOVE_SPEED;
private:

    // ‰æ‘œƒnƒ“ƒhƒ‹
    int mHandle;

    // ˆÊ’u
    Float2 mPosition;
    
    
private:
    int InputPlayer();
    void Movement(int vel);
    void MoveJump();

public:
    Player();
    ~Player();

    void Initialize();

    void Update();

    void Render();

    void Finalize();

};
