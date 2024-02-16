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
    float ReturntmpX_;//feedオブジェクトひとつひとつに座標を返すための領域
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

    /// <summary>
    ///初期化時に座標を保存する
    /// </summary>
    /// <param name="_x">保存したい座標x</param>
    void transfeedX(float _x) { ReturntmpX_ = _x; }
    /// <summary>
  ///初期化時に座標を保存する
  /// </summary>
  /// <param name="_x">保存したい座標y</param>
    void transfeedY(float _y) { ReturntmpY_ = _y; }
    /// <summary>
  ///初期化時に座標を保存する
  /// </summary>
  /// <param name="_x">保存したい座標z</param>
    void transfeedZ(float _z) { ReturntmpZ_ = _z; }

    float GetReturnTmpX() { return ReturntmpX_; }
    float GetReturnTmpY() { return ReturntmpY_; }
    float GetReturnTmpZ() { return ReturntmpZ_; }
};

