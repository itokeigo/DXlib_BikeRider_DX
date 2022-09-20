/*

»ìÒ	ˆÉ“ŒŒcŒå
»ì“ú@2020-11-29

*/
#pragma once

#include"../Utility.h"

class CircleCollider
{
public:
	CircleCollider();
	
	~CircleCollider();

	bool CheckHit(CircleCollider collider);

	static CircleCollider* GetInstans()
	{
		static CircleCollider mpCollider;

		return &mpCollider;
	}

private:
	float mRadian;

	Float2 mPos;
};