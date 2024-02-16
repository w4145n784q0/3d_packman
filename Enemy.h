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
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Enemy(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    float PlayerEnemyLength(float _x, float _y);

   int PlayerEnemyDir(float _x, float _y);

    float GetPositionX(float x) { return x; } 
    float GetPositionY(float y) { return y; } 
    float GetPositionZ(float z) { return z; }
};

