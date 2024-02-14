#pragma once
#include "Engine/GameObject.h"

class Gauge : public GameObject
{

    int hGaugeBar_;
    int hGaugeFrame_;

    int gaugeMaxVal_;   //最大値
    int gaugeCrrVal_;   //現在の値

public:
    //コンストラクタ
    Gauge(GameObject* parent);

    //デストラクタ
    ~Gauge();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetGaugeMaxVal(int _max){gaugeMaxVal_ = _max;}
    void SetGaugeCrrVal(int _crr) { gaugeCrrVal_ = _crr; }
};