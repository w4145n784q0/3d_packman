#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;
class Stage :
    public GameObject
{
    int hFloor_;//��
    int hBlock_;//�u���b�N
    int STAGE_X;
    int STAGE_Y;
    vector<int> stageArray_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Stage(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};

