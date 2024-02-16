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
    //コンストラクタ
    Enemy(GameObject* parent);

    //デストラクタ
    ~Enemy();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};