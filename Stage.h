#pragma once
#include "Engine/GameObject.h"
#include <vector>

//�e�X�g�V�[�����Ǘ�����N���X
class Stage : public GameObject
{

	int hFloor_;
	int hWall_;

	std::vector<std::vector<int>> map;

public:
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
};