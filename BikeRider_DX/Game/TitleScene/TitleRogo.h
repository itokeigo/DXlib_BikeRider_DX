#pragma once
#include<vector>
#include"../Utility.h"

class MojiWave;
class TitleRogo
{

    static const Int2 MOJI_SIZE;
    static const int MOJI_NUM = 5;
    static const Int2 POS_CONST;
private:

    Int2 mPosition;
    int mImageGrahe;

    std::vector<MojiWave*> mMojiWave;

public:
    TitleRogo(char* filename);
    ~TitleRogo();

    void Initialize();

    bool Update();

    void Render();

    void Finalize();
private:


};