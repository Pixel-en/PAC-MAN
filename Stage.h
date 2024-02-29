#pragma once
#include "Engine/GameObject.h"
#include <vector>

enum STAGE_OBJ {
	FLOOR,
	WALL,
};

//テストシーンを管理するクラス
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

	int GetFloorValue();
	bool IsFloor(int _x, int _y);
};