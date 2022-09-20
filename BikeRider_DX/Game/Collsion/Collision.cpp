/*

製作者	伊東慶悟
製作日　2020-08-14

*/
#include"Collision.h"
CircleCollider::CircleCollider()
{
}
CircleCollider::~CircleCollider()
{
}
/*
ほかの円との当たり判定
*/
bool CircleCollider::CheckHit(CircleCollider collider)
{
	//2点の位置を原点からのベクトルにする
	float x = collider.mPos.mX - mPos.mX;
	float y = collider.mPos.mY - mPos.mY;

	//ベクトルの長さを計算
	float l = (x * x) + (y * y);
	
	//半径の合計を取得
	float circleLen = mRadian + collider.mRadian;
	
	//半径の合計を二乗する(sqrtは処理が重いため使わない)
	circleLen *= circleLen;

	//ベクトルがふたつの円の半径より狭かったら当たっている
	if (l <= circleLen)
	{
		return true;
	}
	return false;
}