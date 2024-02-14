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
};

