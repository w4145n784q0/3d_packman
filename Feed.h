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

};

