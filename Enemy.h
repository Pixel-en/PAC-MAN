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