#pragma once
#include "Engine/GameObject.h"

class Gauge : public GameObject
{

    int hGaugeBar_;
    int hGaugeFrame_;

    int gaugeMaxVal_;   //�ő�l
    int gaugeCrrVal_;   //���݂̒l

public:
    //�R���X�g���N�^
    Gauge(GameObject* parent);

    //�f�X�g���N�^
    ~Gauge();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetGaugeMaxVal(int _max){gaugeMaxVal_ = _max;}
    void SetGaugeCrrVal(int _crr) { gaugeCrrVal_ = _crr; }
};