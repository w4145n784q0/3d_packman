#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	if (Input::IsKey(DIK_UP))
	{

	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
