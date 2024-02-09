#include "Enemy.h"
#include"Engine/Model.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy_packman1.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 3,1,5 };
	transform_.scale_ = { 0.5,0.5,0.5 };
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
