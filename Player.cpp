#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Stage.h"
#include"Gauge.h"
#include"Engine/SceneManager.h"

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
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.1f);
	AddCollider(collision);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage *)FindObject("Stage");
	//map[13][1]が[z][x]が初期位置

}

void Player::Update()
{
	//hpがなくなったときの処理
	if (hpCrr_ < 0) {
		hpCrr_ = 0;
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
	/*enum Dir {
		UP,LEFT,DOWN,RIGHT,NONE
	};
	int moveDir = Dir::NONE;*/
	//ここから移動処理
	XMVECTOR vFlont = { 0,0,1,0 };//
	XMVECTOR move{ 0,0,0,0 };//移動ベクトル　移動先
	float speed = 0.20;

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

	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//自機の位置を参照渡し
	XMVECTOR postmp = XMVectorZero();//zeroベクトル
	postmp = pos + speed * move;//作業領域　次が壁かどうかの判断に使う

	int tx, ty;
	tx = (int)(XMVectorGetX(postmp) + 1.0f);//x座標の進む一個先
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(postmp) + 1.0f);//y座標(実際にはz)の進む一個先
	if (!(pStage_->IsWall(tx, ty)))//次に進む先が壁じゃないなら
	{
		pos = postmp;//作業領域に入れてた分を実際に自機の位置を入れる変数へ代入
	}
	else
	{
		hpCrr_ = hpCrr_ - 2;//壁なら変数に代入せず、ｈｐ減らす
	}
	//ここまで移動処理
	
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
		//ここから回転の処理
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

			//逆余弦では回転が＋かーかわからないので
			//XMVECTOR vCross = XMVector3Cross(vFlont, move);//外積求める
			//if (XMVectorGetY(vCross) < 0) {//回転方向が逆だったら-かける
			//	angle *= -1;
			//}

		transform_.rotate_.y = XMConvertToDegrees(-angle);//xmconvert~でラジアンを角度にする

		//ここまで回転の処理
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

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		hpCrr_ = hpCrr_ - 100;
	}
}