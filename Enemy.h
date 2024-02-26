#pragma once
#include "Engine/GameObject.h"

class Stage;
class Player;

class Enemy : public GameObject
{
    int hModel_;
    float speed_;
    Stage* pStage_;
    Player* pPlayer_;
    bool isside_;
    bool ismove_;

    //int movedir;
    int framecnt_;
    int movesave_;

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