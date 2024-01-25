#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"
#include"Engine/CsvReader.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"),hFloor_(-1),hBlock_(-1)
{
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("floor.fbx");
	assert(hFloor_ >= 0);
	hFloor_ = Model::Load("Wall.fbx");
	assert(hFloor_ >= 0);
	/*CsvReader csv;
	csv.Load("Stage.csv");*/

	Camera::SetPosition({ 6.5,10,-5 });
	Camera::SetTarget({ 6.5,0,5.5 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };
	int x = 0;
	int z = 0;


	/*for (int z = 0; z < 15; z++)
	{
		for (int x = 0; x < 15; x++)
		{
			floorTrans.position_ = { (float)x, 0 ,(float)z };
			if(x == 0 || z == 0 || x == 14 || z == 14)
			{
				Model::SetTransform(hBlock_, floorTrans);
				Model::Draw(hBlock_);
			}
			Model::SetTransform(hFloor_, floorTrans);
			Model::Draw(hFloor_);

		}
	}*/


}

void Stage::Release()
{
}