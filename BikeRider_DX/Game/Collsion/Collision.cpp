/*

�����	�ɓ��c��
������@2020-08-14

*/
#include"Collision.h"
CircleCollider::CircleCollider()
{
}
CircleCollider::~CircleCollider()
{
}
/*
�ق��̉~�Ƃ̓����蔻��
*/
bool CircleCollider::CheckHit(CircleCollider collider)
{
	//2�_�̈ʒu�����_����̃x�N�g���ɂ���
	float x = collider.mPos.mX - mPos.mX;
	float y = collider.mPos.mY - mPos.mY;

	//�x�N�g���̒������v�Z
	float l = (x * x) + (y * y);
	
	//���a�̍��v���擾
	float circleLen = mRadian + collider.mRadian;
	
	//���a�̍��v���悷��(sqrt�͏������d�����ߎg��Ȃ�)
	circleLen *= circleLen;

	//�x�N�g�����ӂ��̉~�̔��a��苷�������瓖�����Ă���
	if (l <= circleLen)
	{
		return true;
	}
	return false;
}