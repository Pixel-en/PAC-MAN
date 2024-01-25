#include "Stage.h"
#include "Engine/Model.h"

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Model\\Floor.fbx");
	assert(hFloor_ >= 0);

	hWall_ = Model::Load("Model\\Wall.fbx");
	assert(hWall_ >= 0);
}

void Stage::Update()
{
}

void Stage::Draw()
{

	for (int i = -7; i <= 7; i++) {
		for (int j = -7; j <= 7; j++) {
			//•Ç‚Ì•\Ž¦
			if (i == -7 || i == 7 || j == -7 || j == 7) {
				Transform wallTrans;
				wallTrans.position_ = { (float)i,0,(float)j };
				Model::SetTransform(hWall_, wallTrans);
				Model::Draw(hWall_);
			}
			//°‚Ì•\Ž¦
			else {
				Transform floorTrans;
				floorTrans.position_ = { (float)i,0,(float)j };
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}


}

void Stage::Release()
{
}
