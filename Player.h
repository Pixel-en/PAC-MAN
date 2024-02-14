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
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};