#include "PlayScene.h"
#include "Stage.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);

	Camera::SetPosition({ 0, 10, -12 });
	//Camera::SetTarget({ 0,0,3 });
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
