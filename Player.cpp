#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Stage.h"
#include"Gauge.h"

namespace {
	const float PLAYER_MOVE_SPEED{ 1.0f };
}

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),
	hModel_(-1),speed_(PLAYER_MOVE_SPEED),pStage_(nullptr),
	hpCrr_(100), hpMax_(100)
{
}


void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.25f);
	AddCollider(collision);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage *)FindObject("Stage");
	//map[13][1]が[z][x]が初期位置

}

void Player::Update()
{
	/*enum Dir {
		UP,LEFT,DOWN,RIGHT,NONE
	};
	int moveDir = Dir::NONE;*/

	XMVECTOR vFlont = { 0,0,1,0 };//
	XMVECTOR move{ 0,0,0,0 };//移動ベクトル　移動先
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
	XMVECTOR postmp = XMVectorZero();//zeroベクトル
	postmp = pos + speed * move;

	int tx, ty;
	tx = (int)(XMVectorGetX(postmp) + 1.0f);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(postmp) + 1.0f);
	if (!(pStage_->IsWall(tx, ty)))
	{
		pos = postmp;
	}
	else
	{
		hpCrr_ = hpCrr_ - 2;
		if (hpCrr_ < 0) {
			hpCrr_ = 0;
		}
	}

	//postmp.x,postmp.z => int tx,tz :配列のインデックスに変換
	//仮にmapの配列をmap[][]とする
	//移動先がフロアだったら動く(STAGE_OBJ::FLOOR => 0)
	//if (map[ty][tx] == STAGE_OBJ::floor) {pos = pos + speed * move;}
	//pos = pos + speed * move;

	//Debug::Log("(X,Z)=");
	//Debug::Log(XMVectorGetX(pos));
	//Debug::Log(",");
	//Debug::Log(XMVectorGetZ(pos),true);
	//
	//
	//Debug::Log("(iX,iZ)=");
	//Debug::Log(tx);
	//Debug::Log(",");
	//Debug::Log(ty,true);
	//Debug::Log(":");
	//Debug::Log(pStage_->IsWall(tx, ty));

	


	if (!XMVector3Equal(move, XMVectorZero())){
		XMStoreFloat3(&(transform_.position_), pos);

		XMMATRIX rot = XMMatrixRotationY(XM_PIDIV2);//二分のπ
		XMVECTOR modifiedVec = XMVector3TransformCoord(move, rot);
		Debug::Log(XMVectorGetX(modifiedVec));
		Debug::Log(",");
		Debug::Log(XMVectorGetZ(modifiedVec),true);

		float angle = atan2(XMVectorGetZ(modifiedVec),XMVectorGetX(modifiedVec));
		Debug::Log(" => ");
		Debug::Log(XMConvertToDegrees(angle), true);

			//XMVECTOR vdot = XMVector3Dot(vFlont, move);//XMVector3Dot = ベクトルの内積を求める
			//assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
			//float angle = acos(XMVectorGetX(vdot));//acosはラジアンでかえってくる

			//逆余弦では回転がが＋かーかわからないので
			//XMVECTOR vCross = XMVector3Cross(vFlont, move);//外積求める
			//if (XMVectorGetY(vCross) < 0) {//回転方向が逆だったら-かける
			//	angle *= -1;
			//}

		transform_.rotate_.y = XMConvertToDegrees(-angle);//xmconvert~でラジアンを角度にする

		
	}
	Gauge* gg = (Gauge*)FindObject("Gauge");
	gg->SetGaugeVal(hpCrr_, hpMax_);
}


void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
