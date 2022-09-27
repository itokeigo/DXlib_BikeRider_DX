#pragma once
class GameData
{
private:

public:

    static GameData* GetInstance()
    {
        static GameData* pgd = new GameData();
        return pgd;
    }

    int mScore;


public:
    
    inline int GetScore() { return mScore; }

    inline void SetScore(int score) { mScore = score; }

};