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
	//map[13][1]��[z][x]�������ʒu

}

void Player::Update()
{
	//hp���Ȃ��Ȃ����Ƃ��̏���
	if (hpCrr_ < 0) {
		hpCrr_ = 0;
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
	/*enum Dir {
		UP,LEFT,DOWN,RIGHT,NONE
	};
	int moveDir = Dir::NONE;*/
	//��������ړ�����
	XMVECTOR vFlont = { 0,0,1,0 };//
	XMVECTOR move{ 0,0,0,0 };//�ړ��x�N�g���@�ړ���
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

	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));//���@�̈ʒu���Q�Ɠn��
	XMVECTOR postmp = XMVectorZero();//zero�x�N�g��
	postmp = pos + speed * move;//��Ɨ̈�@�����ǂ��ǂ����̔��f�Ɏg��

	int tx, ty;
	tx = (int)(XMVectorGetX(postmp) + 1.0f);//x���W�̐i�ވ��
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(postmp) + 1.0f);//y���W(���ۂɂ�z)�̐i�ވ��
	if (!(pStage_->IsWall(tx, ty)))//���ɐi�ސ悪�ǂ���Ȃ��Ȃ�
	{
		pos = postmp;//��Ɨ̈�ɓ���Ă��������ۂɎ��@�̈ʒu������ϐ��֑��
	}
	else
	{
		hpCrr_ = hpCrr_ - 2;//�ǂȂ�ϐ��ɑ�������A�������炷
	}
	//�����܂ňړ�����
	
	//postmp.x,postmp.z => int tx,tz :�z��̃C���f�b�N�X�ɕϊ�
	//����map�̔z���map[][]�Ƃ���
	//�ړ��悪�t���A�������瓮��(STAGE_OBJ::FLOOR => 0)
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
		//���������]�̏���
		XMStoreFloat3(&(transform_.position_), pos);

		XMMATRIX rot = XMMatrixRotationY(XM_PIDIV2);//�񕪂̃�
		XMVECTOR modifiedVec = XMVector3TransformCoord(move, rot);
		Debug::Log(XMVectorGetX(modifiedVec));
		Debug::Log(",");
		Debug::Log(XMVectorGetZ(modifiedVec),true);

		float angle = atan2(XMVectorGetZ(modifiedVec),XMVectorGetX(modifiedVec));
		Debug::Log(" => ");
		Debug::Log(XMConvertToDegrees(angle), true);

			//XMVECTOR vdot = XMVector3Dot(vFlont, move);//XMVector3Dot = �x�N�g���̓��ς����߂�
			//assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
			//float angle = acos(XMVectorGetX(vdot));//acos�̓��W�A���ł������Ă���

			//�t�]���ł͉�]���{���[���킩��Ȃ��̂�
			//XMVECTOR vCross = XMVector3Cross(vFlont, move);//�O�ϋ��߂�
			//if (XMVectorGetY(vCross) < 0) {//��]�������t��������-������
			//	angle *= -1;
			//}

		transform_.rotate_.y = XMConvertToDegrees(-angle);//xmconvert~�Ń��W�A�����p�x�ɂ���

		//�����܂ŉ�]�̏���
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