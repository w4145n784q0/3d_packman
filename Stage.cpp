﻿#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include"Engine/CsvReader.h"

namespace
{
	/*const int STAGE_X{ 15 };
	const int STAGE_Y{ 15 };
	const int sArray[STAGE_Y][STAGE_X]{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}*/
};


bool Stage::IsWall(int _x, int _y)
{
	assert(_x >= 0 && _x <= 14);
	assert(_y >= 0 && _y <= 14);
	if (stageData_[_y][_x] == STAGE_OBJ::WALL)
		return true;
	else
		return false;
}

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"),hFloor_(-1),hBlock_(-1)
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

void Stage::Initialize()
{
	hFloor_ = Model::Load("floor.fbx");
	assert(hFloor_ >= 0);
	hBlock_ = Model::Load("wall.fbx");
	assert(hBlock_ >= 0);
	Camera::SetPosition({ 6.5, 12, -5 });
	Camera::SetTarget({ 6.5, 0, 5.5 });
	
}

void Stage::Update()
{
}

void Stage::Draw()
{
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

	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z < stageHeight_; z++) {
		for (int x = 0; x < stageWidth_; x++) {
			floorTrans.position_ = { (float)x, 0 ,(float)(14-z) };

			if (stageData_[z][x] == 1) {
				Model::SetTransform(hBlock_, floorTrans);
				Model::Draw(hBlock_);
			}
			else {
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}

	}
}

void Stage::Release()
{
	//配列を消す
	for (int i = 0; i < stageHeight_; i++)
	{
		stageData_[i].clear();
	}
	stageData_.clear();
}
