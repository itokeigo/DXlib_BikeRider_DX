#include"BackGround.h"
#include"GameMain.h"

void BackGround::Initialize()
{
    mPoint[0] = 0;
    mPoint[1] = SCREEN_RIGHT;
    mImageHandle[0] = LoadGraph("Resources//Textures//Object//BG_001.png");
    mImageHandle[1] = LoadGraph("Resources//Textures//Object//BG_002.png");
    mImageHandle[2] = LoadGraph("Resources//Textures//Object//BG_003.png");
    mImageHandle[3] = LoadGraph("Resources//Textures//Object//BG_004.png");

    mHandl[0] = mImageHandle[0];
    mHandl[1] = mImageHandle[1];

}

void BackGround::Update()
{
    mPoint[0]--;
    mPoint[1]--;
    for (int i=0; i < 2; i++)
    {
        mPoint[i]-=4;
        if (mPoint[i] < -SCREEN_RIGHT)
        {
            mPoint[i] = SCREEN_RIGHT;
            mHandl[i] = mImageHandle[GetRand(BG_NUM)];
        }
    }
}

void BackGround::Render()
{
    DrawGraph(mPoint[0], 0, mHandl[0], true);
    DrawGraph(mPoint[1], 0, mHandl[1], true);
}

void BackGround::Finalize()
{
}
