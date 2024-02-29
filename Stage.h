#pragma once
#include "Engine/GameObject.h"
#include <vector>

enum STAGE_OBJ {
	FLOOR,
	WALL,
};

//�e�X�g�V�[�����Ǘ�����N���X
class Stage : public GameObject
{

	int hFloor_;
	int hWall_;
	int stageWidth_, stageHeight_;
	std::vector<std::vector<int>> map;

	int floorval_;

public:

	int GetStageWidth() { return stageWidth_;}
	int GetStageHeight() { return stageHeight_; }
	bool IsWall(int _x, int _y);

	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	int GetFloorValue();
	bool IsFloor(int _x, int _y);
};