#pragma once
#include"../Utility.h"
class MojiWave
{

    static const int INTERVAL_TIME;
    static const int WAVE_SIZE;
private:

    int mPermutation; // �����̏���

    float mWavesTimer; // �������邽�߂̃^�C�}�[

    int mIntervalTime; // ��������̑ҋ@����
public:
    MojiWave(int permutation);
    ~MojiWave();

    void Initialize();

    void Update();

    void Render(Int2 pos, int image,Int2 mojisize);

    void Finalize();
private:


};
