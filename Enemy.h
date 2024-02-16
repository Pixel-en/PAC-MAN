#pragma once
#include "Engine/GameObject.h"

class Stage;

class Enemy : public GameObject
{
    int hModel_;
    float speed_;
    Stage* pStage_;

    int movedir;
    int framecnt;

public:
    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};