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
		i = *(int*)&b;					//	�����l�ɕϊ����邱�Ƃŋ^���ΐ��ϊ� 
		i = 0x1FBD1E2D + (i >> 1);		//	�萔 + 0.5 * i 
		b = *(float*)&i;				//	���������_���ɕϊ����邱�Ƃŋ^���w���ϊ� 
		b = b * newtonconst + a / b;	//	������
		b = b * newtonconst + a / b;	//	������
		b = b * newtonconst + a / b;	//	������
		b = b * newtonconst + a / b;	//	������
		b = b * newtonconst + a / b;	//	������

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