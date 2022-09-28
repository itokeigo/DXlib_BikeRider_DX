/*
	画像を描画するための構造体
*/

#pragma once

struct SpriteData
{

	// メンバ変数----------------------------------------------------------

	struct float2
	{
		float2(float sx = 0, float sy = 0)
		{
			x = sx;
			y = sy;
		}
		float x;
		float y;
	};

	struct int2
	{
		int2(int sx = 0, int sy = 0)
		{
			x = sx;
			y = sy;
		}
		int x;
		int y;
	};

	// 座標
	float2 pos;

	// 切り取りの開始位置
	int2 src;

	// 切り取りの終了位置
	int2 size;

	// 画像の中心位置
	float2 center;

	// 拡大率
	float2 scale;

	// 角度（radian）
	double rot;

	// 透明度
	float alpha;

	// 画像ハンドル
	int textureHandle;

	// メンバ関数----------------------------------------------------------

	// コンストラクタ
	SpriteData();

	// デストラクタ
	~SpriteData();

	// 画像ハンドルの設定
	void SetTexture(int handle);

	// 描画
	void Draw();
};