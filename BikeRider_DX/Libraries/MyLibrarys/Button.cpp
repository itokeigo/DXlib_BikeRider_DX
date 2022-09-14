/*****************************************************************//**
 * \file   Button.cpp
 * \brief  ボタンの処理をまとめた関数
 * \author Ito Keigo
 * \date   2022/04/22
 * 
 *********************************************************************/

#include"Button.h"
const int Button::BUTTON_WIDTH_SIZE=10;
Button::Button()
    :mButtonPos()
    , mButtonSize()
    , mIsMouse(false)
    , mMojiSize(0)
{
}

void Button::CreateButton(std::string moji,int x, int y, int sizeX, int sizeY,int fontsize)
{
    // 文字保管変数に代入
    mLength = moji;
    mButtonSize.x = sizeX;
    mButtonSize.y = sizeY;
    mFontSize = fontsize;

    mOverHigh = fontsize - GetFontSize();

    // 文字が入っていた場合
    if (mLength != "")
    {
        MojiLength();
        mButtonSize.x = mMojiSize + BUTTON_WIDTH_SIZE*2;
    }

    // 座標を中心に設定
    mButtonPos.x = x - (mButtonSize.x * 0.5);
    mButtonPos.y = y - (mButtonSize.y * 0.5);
}

Button::BUTTON_STATE Button::ChackeButton()
{
    int x, y;
    //マウスの場所を取得
    GetMousePoint(&x, &y);

    //ボタンの範囲内判定
    bool isX = x > mButtonPos.x && x < mButtonPos.x + mButtonSize.x;
    bool isY = y > mButtonPos.y && y < mButtonPos.y + mButtonSize.y;

    // ボタンの範囲内か
    if (isX&&isY)
    {
        // マウスがクリックされたか
        bool isM = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
        if (isM && !mIsMouse)
        {
            //押されている
            mIsMouse = true;
            return BUTTON_PUSH;
        }
        if (isM && mIsMouse)
        {
            // 押され続けている
            return BUTTON_DOWN;
        }
        if (!isM && mIsMouse)
        {
            // 離された
            mIsMouse = false;
            return BUTTON_RELEASE;
        }
    }
    mIsMouse = false;
    return BUTTON_STATE::NONE;
}

void Button::Render(int color, bool Fream,int fontColor)
{
    int fs = GetFontSize();
    SetFontSize(mFontSize);
    // ボタンを表示
    if (mIsMouse) 
    {
        // 加算表示開始
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 160);
        DrawBox(mButtonPos.x, mButtonPos.y, mButtonPos.x + mButtonSize.x, mButtonPos.y + mButtonSize.y+ mOverHigh, color, Fream);
        DrawString(mButtonPos.x + BUTTON_WIDTH_SIZE, mButtonPos.y + (mButtonSize.y * 0.5) - BUTTON_WIDTH_SIZE, mLength.c_str(), fontColor);
        // 加算表示終了
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    else
    {
        DrawBox(mButtonPos.x, mButtonPos.y, mButtonPos.x + mButtonSize.x, mButtonPos.y + mButtonSize.y+ mOverHigh, color, Fream);
        DrawString(mButtonPos.x + BUTTON_WIDTH_SIZE, mButtonPos.y + (mButtonSize.y * 0.5) - BUTTON_WIDTH_SIZE, mLength.c_str(), fontColor);
    }
    SetFontSize(fs);
}

void Button::Finalize()
{
}

void Button::MojiLength()
{
    // 文字列の長さを取得
   int StrLen = strlen(mLength.c_str());

   int fs = GetFontSize();
   SetFontSize(mFontSize);
    // 描画時の文字列の幅を取得
   mMojiSize = GetDrawStringWidth(mLength.c_str(), StrLen);
   SetFontSize(fs);
}


