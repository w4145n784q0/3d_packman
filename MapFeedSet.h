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

    //void transfeed(Transform _pos) { Returntmp_= _pos; }
    void transfeedX(float _x) { ReturntmpX_ = _x; }
    void transfeedY(float _y) { ReturntmpY_ = _y; }
    void transfeedZ(float _z) { ReturntmpZ_ = _z; }

    float GetReturnTmpX() { return ReturntmpX_; }
    float GetReturnTmpY() { return ReturntmpY_; }
    float GetReturnTmpZ() { return ReturntmpZ_; }

    //Transform GetReturnTmp() { return Returntmp_; }
};

