#include "Feed.h"
#include"Engine/Model.h"
#include"Engine/CsvReader.h"

Feed::Feed(GameObject* parent)
	:GameObject(parent,"Feed"),hModel_(-1)
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

void Feed::Initialize()
{
	//hModel_ = Model::Load("");
	//assert(hModel_ >= 0);
}

void Feed::Update()
{
}

void Feed::Draw()
{
	/*Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z < stageHeight_; z++) {
		for (int x = 0; x < stageWidth_; x++) {
			floorTrans.position_ = { (float)x, 0 ,(float)(14 - z) };

			if (stageData_[z][x] == 0) {
				Model::SetTransform(hBlock_, floorTrans);
				Model::Draw(hBlock_);
			}
			else {
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);


			}
		}
	}*/

	/*Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z < 15; z++){
		for (int x = 0; x < 15; x++){

			floorTrans.position_ = { (float)x, 0 ,(float)z };
			if (x == 0 || z == 0 || x == 14 || z == 14) {
				Model::SetTransform(hBlock_, floorTrans);
				Model::Draw(hBlock_);
			}
			else
			{
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_)
			}
		}
	}*/

}

void Feed::Release()
{//配列を消す
	//for (int i = 0; i < stageHeight_; i++)
	//{
	//	stageData_[i].clear();
	//}
	//stageData_.clear();
}
