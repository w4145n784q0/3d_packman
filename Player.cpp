#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 1.0f };
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
	//map[13][1]が[z][x]が初期位置

}

void Player::Update()
{
	/*enum Dir {
		UP,LEFT,DOWN,RIGHT,NONE
	};
	int moveDir = Dir::NONE;*/

	XMVECTOR vFlont = { 0,0,1,0 };//
	XMVECTOR move{ 0,0,0,0 };//移動ベクトル
	float speed = 1.0;


	if (Input::IsKeyDown(DIK_UP))
	{
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
	}
	if (Input::IsKeyDown(DIK_LEFT))
	{
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKeyDown(DIK_DOWN))
	{
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	if (Input::IsKeyDown(DIK_RIGHT))
	{
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
	}

	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + speed * move;

	Debug::Log("(X,Z)=");
	Debug::Log(XMVectorGetX(pos));
	Debug::Log(",");
	Debug::Log(XMVectorGetZ(pos),true);
	for (int y = 13; y < 0; y--)
	{
		for (int x = 0;  x < 13; x++)
		{

		}
	}


	if (!XMVector3Equal(move, XMVectorZero())){
		XMStoreFloat3(&(transform_.position_), pos);

			XMVECTOR vdot = XMVector3Dot(vFlont, move);//XMVector3Dot = ベクトル野菜遺跡を求める
			assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
			float angle = acos(XMVectorGetX(vdot));//acosはラジアンでかえってくる

			//逆余弦では回転がが＋かーかわからないので
			XMVECTOR vCross = XMVector3Cross(vFlont, move);//外積求める
			if (XMVectorGetY(vCross) < 0) {//回転方向が逆だったら-かける
				angle *= -1;
			}

		transform_.rotate_.y = XMConvertToDegrees(angle);//xmconvert~でラジアンを角度にする
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
