#pragma once
#include "Engine/GameObject.h"
#include<vector>
#include"MapFeedSet.h"

using std::vector;

class Feed :
    public GameObject
{
    MapFeedSet* pMapFeedSet_;
    int hModel_;//
   // int stageWidth_, stageHeight_;
   /* int feedcount_;*/
    //int clearcount_;
    
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

    float GetFeedX(float _x) { return _x; }
    float GetFeedY(float _y) { return _y; }
    float GetFeedZ(float _z) { return _z; }
};

