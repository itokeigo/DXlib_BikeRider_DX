#pragma once
#include"Utility.h"
class BackGround
{
    static const int BG_NUM = 4;
private:
    int mImageHandle[BG_NUM];

    int mPoint[2];
    
    int mHandl[2];
public:
    void Initialize();

    void Update();

    void Render();

    void Finalize();
};
