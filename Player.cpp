#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 0.1f };
}

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}


void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
}

void Player::Update()
{
	/*enum Dir {
		UP,LEFT,DOWN,RIGHT,NONE
	};
	int moveDir = Dir::NONE;*/

	XMVECTOR vFlont = { 0,0,1,0 };
	XMVECTOR move{ 0,0,1,0 };
	float speed = 0.1;
	

	if (Input::IsKey(DIK_UP))
	{
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKey(DIK_DOWN))
	{
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
	}

	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + speed * move;
	XMStoreFloat3(&(transform_.position_), pos);

	XMVECTOR vdot =  XMVector3Dot(vFlont, move);
	float angle = acos(XMVectorGetX(vdot));//acosはラジアンでかえってくる
	

	XMVECTOR vCross = XMVector3Cross(vFlont, move);
	if (XMVectorGetY(vCross) < 0) {
		angle *= -1;
	}

	transform_.rotate_.y = XMConvertToDegrees(angle);//xmconvert~でラジアンを角度にする
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
