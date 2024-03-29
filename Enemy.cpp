#include "Enemy.h"
#include"Engine/Model.h"
#include"Stage.h"
#include"Engine/Debug.h"
#include"Player.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1),speed_(0.1),pStage_(nullptr), pPlayer_(nullptr)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy_packman1.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
	pStage_ = (Stage*)FindObject("Stage");
	pPlayer_ = (Player*)FindObject("Player");
	transform_.position_ = { 0.5,0,6.5 };
	transform_.scale_ = { 0.5,0.5,0.5 };
}

void Enemy::Update()
{
	float lng = PlayerEnemyLength(pPlayer_->SetTransX(), pPlayer_->SetTransZ());
	if (lng < 6)
	{
		switch (PlayerEnemyDir(pPlayer_->SetTransX(), pPlayer_->SetTransZ()))
		{
		case 1:
			transform_.position_.x += 0.1;
			break;
		case 2:
			transform_.position_.x -= 0.1;
			break;
		case 3:
			transform_.position_.z += 0.1;
			break;
		case 4:
			transform_.position_.z -= 0.1;
			break;
		default:
			break;
		}
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

float Enemy::PlayerEnemyLength(float _x, float _y)
{
	float myx = transform_.position_.x;
	float myy = transform_.position_.z;
	float xlen = myx - _x;
	float ylen = myy - _y;

	float re = sqrt((xlen * xlen) + (ylen * ylen));
	return re;
}

int Enemy::PlayerEnemyDir(float _x, float _y)
{
	float myx = transform_.position_.x;
	float myy = transform_.position_.z;

	if (myx < _x)//playerが敵より右にいるなら
		return 1;
	else if (myx > _x)//playerが敵より左にいるなら
		return 2;
	else if (myy < _y)//playerが敵より上にいるなら
		return 3;
	else if (myy > _y)//playerが敵より下にいるなら
		return 4;
	else
		return 0;
}