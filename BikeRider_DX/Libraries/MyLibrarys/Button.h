#pragma once
#include <string>

class Button
{
    // 文字ぎりぎりにならないように設定する幅の定数
    static const int BUTTON_WIDTH_SIZE;

private:

    // ボタンの中心座標
    VECTOR mButtonPos;

    //ボタンの幅
    VECTOR mButtonSize;

    //マウスで押されたか
    bool mIsMouse;

    // 表示する文字
    std::string mLength;

    // 文字の幅
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
    // コンストラクタ
    Button();

    //　初期化
    void CreateButton(std::string moji = "",int x=0,int y=0,int sizeX=100,int sizeY=50,int fontsize=16);

    // ボタンチェック
    BUTTON_STATE ChackeButton();

    // ボタンを描画
    void Render(int color,bool Fream,int fontColor= GetColor(0, 0, 0));

    // 終了処理
    void Finalize();

private:

    // 文字の長さを取得する関数
    void MojiLength();
};
