#include "GameClearScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

GameClearScene::GameClearScene(GameObject* parent)
	:GameObject(parent,"GameClearScene"),hImage_(-1)
{
}

void GameClearScene::Initialize()
{
	hImage_ = Image::Load("GameClear.png");
	assert(hImage_ >= 0);
}

void GameClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameClearScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void GameClearScene::Release()
{
}
