#pragma once
#include "Engine/GameObject.h"

class Stage;

class Enemy :
    public GameObject
{
    int hModel_;
    float speed_;
    Stage* pStage_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    Enemy(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

   // void OnCollision(GameObject* pTarget) override;
};

