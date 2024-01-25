#pragma once
#include "Engine/GameObject.h"
#include <vector>

//テストシーンを管理するクラス
class Stage : public GameObject
{

	int hFloor_;
	int hWall_;

	std::vector<std::vector<int>> map;

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Stage(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};