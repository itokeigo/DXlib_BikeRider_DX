#include"TitleRogo.h"
#include"../Utility.h"
#include"MojiWave.h"

#include"../GameMain.h"
const Int2 TitleRogo::MOJI_SIZE = Int2(80,120);
const Int2 TitleRogo::POS_CONST=Int2(SCREEN_CENTER_X-200,SCREEN_CENTER_Y-150);
TitleRogo::TitleRogo(char* filename)
{
    mImageGrahe = LoadGraph(filename);
}

TitleRogo::~TitleRogo()
{
}

void TitleRogo::Initialize()
{
    mPosition = Int2(POS_CONST.mX, -100);

    for (int i = 0; i < MOJI_NUM; i++)
    {
        mMojiWave.push_back(new MojiWave(i));
        mMojiWave[i]->Initialize();
    }
}

bool TitleRogo::Update()
{
    if (mPosition.mY >= POS_CONST.mY)
    {
        for (int i = 0; i < mMojiWave.size(); i++)
        {
            mMojiWave[i]->Update();
        }
    }
    else
    {
        mPosition.mY += 10;
        return false;
    }
    return true;
}

void TitleRogo::Render()
{
    for (int i = 0; i < mMojiWave.size(); i++)
    {
        mMojiWave[i]->Render(mPosition,mImageGrahe, MOJI_SIZE);
    }
}

void TitleRogo::Finalize()
{
    for (int i = 0; i < mMojiWave.size(); i++)
    {
        mMojiWave[i]->Finalize();
    }
    mMojiWave.clear();
}
