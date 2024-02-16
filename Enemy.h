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
    /// <summary>
    /// �v���C���[�ƓG�̋����𑪂�
    /// </summary>
    /// <param name="_x">�v���C���[��x���W</param>
    /// <param name="_y">�v���C���[��z���W</param>
    /// <returns>�v���C���[�ƓG�̋���</returns>
    float PlayerEnemyLength(float _x, float _y);

   /// <summary>
   /// �v���C���[�ƓG���ǂ̕������痣��Ă��邩����
   /// </summary>
   /// <param name="_x">�v���C���[��x���W</param>
   /// <param name="_y">�v���C���[��z���W</param>
   /// <returns>����Ă���ꏊ�i�����j</returns>
   int PlayerEnemyDir(float _x, float _y);

    float GetPositionX(float x) { return x; } 
    float GetPositionY(float y) { return y; } 
    float GetPositionZ(float z) { return z; }
};

