#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOverScene"),hImage_(-1)
{
}

void GameOverScene::Initialize()
{
	hImage_ = Image::Load("GAME-OVER.png");
	assert(hImage_ >= 0);
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->ChangeScene(SCENE_ID_TITLE);
	}

}

void GameOverScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void GameOverScene::Release()
{
}
