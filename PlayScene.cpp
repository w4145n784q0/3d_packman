#include "PlayScene.h"
#include"Stage.h"
#include"Player.h"
#include"Gauge.h"
#include"Enemy.h"
#include"Feed.h"
#include"MapFeedSet.h"
#include"Engine/SceneManager.h"

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
	if (FindObject("Feed") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
