#include "Enemy.h"
#include"Engine/Model.h"
#include"Stage.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy_packman1.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
	pStage_ = (Stage*)FindObject("Stage");
	transform_.position_ = { 0.5,0,6.5 };
	transform_.scale_ = { 0.5,0.5,0.5 };
}

void Enemy::Update()
{
	XMVECTOR vFlont = { 0,0,1,0 };//
	XMVECTOR move{ 0,0,0,0 };//移動ベクトル　移動先
	speed_ = 0.2;
	transform_.position_.x += speed_;
	if(transform_.position_.x >= 13)
		transform_.position_.x -= speed_;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}