#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;

class Feed :
    public GameObject
{
    int hModel_;//
    vector<vector<int>> stageData_;
    int stageWidth_, stageHeight_;
    int feedcount_;
    int clearcount_;
    
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    Feed(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;
};

