#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;
class Stage :
    public GameObject
{
    int hFloor_;//床
    int hBlock_;//ブロック
    int STAGE_X;
    int STAGE_Y;
    vector<int> stageArray_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    Stage(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};

