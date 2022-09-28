#pragma once
#include"../../Game/GameMain.h"
class CountDown
{
    static const int IMAGE_SIZE_X;
    static const int IMAGE_SIZE_Y;

private:
    int mNumbers[4];
    int mTimer;
    int mCountDown;
public:
    CountDown();
    ~CountDown();

    void Initialize();

    void Update();

    void Render();

    void Finalize();
private:


};