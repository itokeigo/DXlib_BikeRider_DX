/*****************************************************************//**
 * \file   Button.cpp
 * \brief  �{�^���̏������܂Ƃ߂��֐�
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
    // �����ۊǕϐ��ɑ��
    mLength = moji;
    mButtonSize.x = sizeX;
    mButtonSize.y = sizeY;
    mFontSize = fontsize;

    mOverHigh = fontsize - GetFontSize();

    // �����������Ă����ꍇ
    if (mLength != "")
    {
        MojiLength();
        mButtonSize.x = mMojiSize + BUTTON_WIDTH_SIZE*2;
    }

    // ���W�𒆐S�ɐݒ�
    mButtonPos.x = x - (mButtonSize.x * 0.5);
    mButtonPos.y = y - (mButtonSize.y * 0.5);
}

Button::BUTTON_STATE Button::ChackeButton()
{
    int x, y;
    //�}�E�X�̏ꏊ���擾
    GetMousePoint(&x, &y);

    //�{�^���͈͓̔�����
    bool isX = x > mButtonPos.x && x < mButtonPos.x + mButtonSize.x;
    bool isY = y > mButtonPos.y && y < mButtonPos.y + mButtonSize.y;

    // �{�^���͈͓̔���
    if (isX&&isY)
    {
        // �}�E�X���N���b�N���ꂽ��
        bool isM = (GetMouseInput() & MOUSE_INPUT_LEFT) != 0;
        if (isM && !mIsMouse)
        {
            //������Ă���
            mIsMouse = true;
            return BUTTON_PUSH;
        }
        if (isM && mIsMouse)
        {
            // �����ꑱ���Ă���
            return BUTTON_DOWN;
        }
        if (!isM && mIsMouse)
        {
            // �����ꂽ
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
    // �{�^����\��
    if (mIsMouse) 
    {
        // ���Z�\���J�n
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 160);
        DrawBox(mButtonPos.x, mButtonPos.y, mButtonPos.x + mButtonSize.x, mButtonPos.y + mButtonSize.y+ mOverHigh, color, Fream);
        DrawString(mButtonPos.x + BUTTON_WIDTH_SIZE, mButtonPos.y + (mButtonSize.y * 0.5) - BUTTON_WIDTH_SIZE, mLength.c_str(), fontColor);
        // ���Z�\���I��
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
    // ������̒������擾
   int StrLen = strlen(mLength.c_str());

   int fs = GetFontSize();
   SetFontSize(mFontSize);
    // �`�掞�̕�����̕����擾
   mMojiSize = GetDrawStringWidth(mLength.c_str(), StrLen);
   SetFontSize(fs);
}


