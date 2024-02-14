#pragma once
#include "Engine/GameObject.h"
#include "Gauge.h"

class Stage;

class Player : public GameObject
{

    int hModel_;
    float speed_;
    Stage* pStage_;

    int hpCrr_;
    int hpMax_;

    Gauge* pGauge_;

    float rottmp_;



public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};