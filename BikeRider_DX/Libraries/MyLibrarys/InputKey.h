#pragma once

enum eKEY_STATE
{
    NONE,
    PUSH,
    DOWN,
    RELEAS,
};
class InputKey
{
private:

    bool mIsKeyPush;
    bool mIsKeyDown;

public:
    static InputKey* GetInstance()
    {
        static InputKey* m = new InputKey();
        return m;
    }

    inline InputKey()
        :mIsKeyDown(false)
        ,mIsKeyPush(false)
    {

    }
    inline eKEY_STATE InputChackKey(bool key)
    {
        if (!mIsKeyPush && !mIsKeyDown && key)
        {
            mIsKeyPush = true;
            return eKEY_STATE::PUSH;
        }
        else if (mIsKeyPush && !mIsKeyDown && key)
        {
            mIsKeyDown = true;
            return eKEY_STATE::DOWN;
        }
        else if (mIsKeyPush && mIsKeyDown && !key)
        {
            mIsKeyPush = false;
            mIsKeyDown = false;
            return eKEY_STATE::RELEAS;
        }
        return eKEY_STATE::NONE;
    }
};