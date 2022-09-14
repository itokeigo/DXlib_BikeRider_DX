#pragma once
#include <string>

class Button
{
    // �������肬��ɂȂ�Ȃ��悤�ɐݒ肷�镝�̒萔
    static const int BUTTON_WIDTH_SIZE;

private:

    // �{�^���̒��S���W
    VECTOR mButtonPos;

    //�{�^���̕�
    VECTOR mButtonSize;

    //�}�E�X�ŉ����ꂽ��
    bool mIsMouse;

    // �\�����镶��
    std::string mLength;

    // �����̕�
    int mMojiSize;

    int mFontSize;

    int mOverHigh;

public:

    enum BUTTON_STATE :int
    {
        NONE = 0,
        BUTTON_PUSH,
        BUTTON_DOWN,
        BUTTON_RELEASE,
    };

public:
    // �R���X�g���N�^
    Button();

    //�@������
    void CreateButton(std::string moji = "",int x=0,int y=0,int sizeX=100,int sizeY=50,int fontsize=16);

    // �{�^���`�F�b�N
    BUTTON_STATE ChackeButton();

    // �{�^����`��
    void Render(int color,bool Fream,int fontColor= GetColor(0, 0, 0));

    // �I������
    void Finalize();

private:

    // �����̒������擾����֐�
    void MojiLength();
};
