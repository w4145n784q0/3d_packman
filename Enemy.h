#pragma once
#include "Engine/GameObject.h"

class Stage;
class Player;

class Enemy :
    public GameObject
{
    int hModel_;
    float speed_;
    Stage* pStage_;
    Player* pPlayer_;
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
    /// <summary>
    /// プレイヤーと敵の距離を測る
    /// </summary>
    /// <param name="_x">プレイヤーのx座標</param>
    /// <param name="_y">プレイヤーのz座標</param>
    /// <returns>プレイヤーと敵の距離</returns>
    float PlayerEnemyLength(float _x, float _y);

   /// <summary>
   /// プレイヤーと敵がどの方向から離れているか測る
   /// </summary>
   /// <param name="_x">プレイヤーのx座標</param>
   /// <param name="_y">プレイヤーのz座標</param>
   /// <returns>離れている場所（数字）</returns>
   int PlayerEnemyDir(float _x, float _y);

    float GetPositionX(float x) { return x; } 
    float GetPositionY(float y) { return y; } 
    float GetPositionZ(float z) { return z; }
};

