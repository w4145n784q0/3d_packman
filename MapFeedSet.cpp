#include "MapFeedSet.h"
#include"Feed.h"
#include"Engine/CsvReader.h"

MapFeedSet::MapFeedSet(GameObject* parent)
	:GameObject(parent, "MapFeedSet"), stageWidth_(0), stageHeight_(0),
	ReturntmpX_(0),ReturntmpY_(0), ReturntmpZ_(0)
{
	CsvReader csv;
	csv.Load("map2_.csv");//csv（コンマ区切り）で保存

	stageWidth_ = csv.GetWidth();    //１行に何個データがあるか
	stageHeight_ = csv.GetHeight();   //データが何行あるか


	for (int i = 0; i < stageHeight_; i++)
	{
		vector<int> sdata(stageWidth_, 0);
		stageData_.push_back(sdata);
	}


	for (int j = 0; j < stageHeight_; j++)
	{
		for (int i = 0; i < stageWidth_; i++)
		{
			stageData_[j][i] = csv.GetValue(i, j);
		}
	}
}

void MapFeedSet::Initialize()
{
	Transform floorTrans;
	floorTrans.position_ = { 0.5,0,0 };

	for (int z = 1; z < stageHeight_ - 1; z++) {
		for (int x = 1; x < stageWidth_ - 1; x++) {
			floorTrans.position_ = { (float)x - (float)0.5, 0.2 ,(float)(14 - z) + (float)0.5 };

			if (stageData_[z][x] == 0) {
			
				transfeedX(floorTrans.position_.x);//ここで餌を置く度に座標を保管しておく
				transfeedY(floorTrans.position_.y);//保管した座標はfeedの初期化に使う
				transfeedZ(floorTrans.position_.z);//保管が終わってからクラスの初期化
				Instantiate<Feed>(this);
			}
		}
	}
}

void MapFeedSet::Update()
{
}

void MapFeedSet::Draw()
{
	

}

void MapFeedSet::Release()
{//配列を消す
	for (int i = 0; i < stageHeight_; i++)
	{
		stageData_[i].clear();
	}
	stageData_.clear();
}
