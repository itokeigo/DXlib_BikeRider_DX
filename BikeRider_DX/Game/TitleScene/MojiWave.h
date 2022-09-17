#pragma once
#include"../Utility.h"
class MojiWave
{

    static const int INTERVAL_TIME;
    static const int WAVE_SIZE;
private:

    int mPermutation; // 文字の順列

    float mWavesTimer; // 躍動するためのタイマー

    int mIntervalTime; // 動いた後の待機時間
public:
    MojiWave(int permutation);
    ~MojiWave();

    void Initialize();

    void Update();

    void Render(Int2 pos, int image,Int2 mojisize);

    void Finalize();
private:


};
