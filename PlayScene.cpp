#include "PlayScene.h"
#include"Stage.h"
#include"Player.h"
#include"Gauge.h"
#include"Enemy.h"
#include"Feed.h"
#include"MapFeedSet.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
	Instantiate<Enemy>(this);
	Instantiate<MapFeedSet>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
