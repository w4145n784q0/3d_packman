#include "Feed.h"
#include"Engine/Model.h"
#include"Engine/CsvReader.h"
#include"Engine/SphereCollider.h"
#include"Engine/Debug.h"

Feed::Feed(GameObject* parent)
	:GameObject(parent,"Feed"),hModel_(-1),pMapFeedSet_(nullptr)
{
	
}

void Feed::Initialize()
{
	hModel_ = Model::Load("feed.fbx");
	assert(hModel_ >= 0);
	pMapFeedSet_ = (MapFeedSet*)FindObject("MapFeedSet");
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
	transform_.position_.x = GetFeedX(pMapFeedSet_->GetReturnTmpX());//餌の設置クラスから設置する座標を取ってくる
	transform_.position_.y = GetFeedY(pMapFeedSet_->GetReturnTmpY());
	transform_.position_.z = GetFeedZ(pMapFeedSet_->GetReturnTmpZ());
}

void Feed::Update()
{
	
}

void Feed::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

void Feed::Release()
{
}

void Feed::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Player")
	{
		this->KillMe();
	}
}
