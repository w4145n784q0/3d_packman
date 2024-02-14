#pragma once
#include "Engine/GameObject.h"
#include<vector>
using std::vector;


class MapFeedSet :
    public GameObject
{
    vector<vector<int>> stageData_;
    int stageWidth_, stageHeight_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    MapFeedSet(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

};

