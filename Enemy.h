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

    float PlayerEnemyLength(float _x, float _y);

   int PlayerEnemyDir(float _x, float _y);

    float GetPositionX(float x) { return x; } 
    float GetPositionY(float y) { return y; } 
    float GetPositionZ(float z) { return z; }
};

