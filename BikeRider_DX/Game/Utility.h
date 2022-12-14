#pragma once

struct Float2
{
	float mX;
	float mY;

	Float2(float x = 0.0f, float y = 0.0f)
		: mX(x)
		, mY(y)
	{

	}

	inline Float2 Normalize()
	{
		float length = this->Length();
		this->mX /= length;
		this->mY /= length;

		return Float2(this->mX, this->mY);
	}

	inline float Length()
	{
		float length = this->mX * this->mX + this->mY * this->mY;

		int	i;
		float a, b;
		const float	newtonconst = 0.5F;

		a = length * 0.5F;
		b = length;
		i = *(int*)&b;					//	整数値に変換することで疑似対数変換 
		i = 0x1FBD1E2D + (i >> 1);		//	定数 + 0.5 * i 
		b = *(float*)&i;				//	浮動小数点数に変換することで疑似指数変換 
		b = b * newtonconst + a / b;	//	平方根
		b = b * newtonconst + a / b;	//	平方根
		b = b * newtonconst + a / b;	//	平方根
		b = b * newtonconst + a / b;	//	平方根
		b = b * newtonconst + a / b;	//	平方根

		return b;
	}
};

struct Int2
{
	int mX;
	int mY;
	Int2(int x = 0, int y = 0)
		:mX(x)
		, mY(y)
	{

	}
};