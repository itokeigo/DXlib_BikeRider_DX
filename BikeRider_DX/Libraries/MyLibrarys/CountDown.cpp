#include"CountDown.h"
#include"../../Game/Utility.h"
const int CountDown::IMAGE_SIZE_X=16;
const int CountDown::IMAGE_SIZE_Y=21;
CountDown::CountDown()
    :mTimer()
    ,mCountDown()
    , mNumbers{}
{
    
}
CountDown::~CountDown()
{
}
void CountDown::Initialize()
{
   LoadDivGraph("Resources/Textures/Object/Number.png",
                 5, 
                 5, 
                 1, 
                 16, 
                 21, 
                 mNumbers);
   mTimer = 5 * 60;
    
}

void CountDown::Update()
{
    if(mTimer>0)mTimer--;
    mCountDown = (mTimer / 60);

}

void CountDown::Render()
{
    DrawGraph(100,100,mNumbers[mCountDown],true);
}
