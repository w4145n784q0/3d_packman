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
    float ReturntmpX_;//feed�I�u�W�F�N�g�ЂƂЂƂɍ��W��Ԃ����߂̗̈�
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

    /// <summary>
    ///���������ɍ��W��ۑ�����
    /// </summary>
    /// <param name="_x">�ۑ����������Wx</param>
    void transfeedX(float _x) { ReturntmpX_ = _x; }
    /// <summary>
  ///���������ɍ��W��ۑ�����
  /// </summary>
  /// <param name="_x">�ۑ����������Wy</param>
    void transfeedY(float _y) { ReturntmpY_ = _y; }
    /// <summary>
  ///���������ɍ��W��ۑ�����
  /// </summary>
  /// <param name="_x">�ۑ����������Wz</param>
    void transfeedZ(float _z) { ReturntmpZ_ = _z; }

    float GetReturnTmpX() { return ReturntmpX_; }
    float GetReturnTmpY() { return ReturntmpY_; }
    float GetReturnTmpZ() { return ReturntmpZ_; }
};

