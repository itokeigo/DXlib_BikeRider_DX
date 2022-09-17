#include"MojiWave.h"
#include<iostream>
const int MojiWave::INTERVAL_TIME = 4;
const int MojiWave::WAVE_SIZE = 70;

MojiWave::MojiWave(int permutation)
{
    mPermutation = permutation;
}

MojiWave::~MojiWave()
{
}

void MojiWave::Initialize()
{
    mWavesTimer = 0.0f;
    mIntervalTime = 0;
}

void MojiWave::Update()
{
    mIntervalTime++;
    if (mIntervalTime >= (INTERVAL_TIME ) * 60 + mPermutation*15)
    {
        mWavesTimer += 0.2;
        if (sinf(mWavesTimer )* WAVE_SIZE < 0)
        {
            mWavesTimer=0;
            mIntervalTime = INTERVAL_TIME * 60 - ((INTERVAL_TIME * 2) - mPermutation) * 15;// インターバルを文字数分の遅延を含め計算
            
        }
    }
}

void MojiWave::Render(Int2 pos,int image,Int2 mojisize)
{
    int size = (mPermutation * mojisize.mX);
    DrawRectGraph(pos.mX + size, pos.mY - std::sinf(mWavesTimer) * WAVE_SIZE,
                  size, 0,
                  mojisize.mX, mojisize.mY,
                  image,true);
}

void MojiWave::Finalize()
{
}
