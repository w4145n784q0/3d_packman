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
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Feed(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;

    float GetFeedX(float _x) { return _x; }
    float GetFeedY(float _y) { return _y; }
    float GetFeedZ(float _z) { return _z; }
};

