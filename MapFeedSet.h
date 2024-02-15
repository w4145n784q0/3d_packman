#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;
//

class MapFeedSet :
    public GameObject
{
    vector<vector<int>> stageData_;
    int stageWidth_, stageHeight_;
    Transform Returntmp_;
    float ReturntmpX_;
    float ReturntmpY_;
    float ReturntmpZ_;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    MapFeedSet(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //void transfeed(Transform _pos) { Returntmp_= _pos; }
    void transfeedX(float _x) { ReturntmpX_ = _x; }
    void transfeedY(float _y) { ReturntmpY_ = _y; }
    void transfeedZ(float _z) { ReturntmpZ_ = _z; }

    float GetReturnTmpX() { return ReturntmpX_; }
    float GetReturnTmpY() { return ReturntmpY_; }
    float GetReturnTmpZ() { return ReturntmpZ_; }

    //Transform GetReturnTmp() { return Returntmp_; }
};

