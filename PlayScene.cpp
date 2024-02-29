#include "PlayScene.h"
#include "Stage.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Gauge.h"
#include "Enemy.h"
#include "Cookie.h"
#include "Engine/SceneManager.h"

class Stage;

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Stage temp(this);
	for (int i = 0; i < temp.GetStageHeight(); i++) {
		for (int j = 0; j < temp.GetStageWidth(); j++) {
			if (temp.IsFloor(j, i)) {
				Cookie* c = Instantiate<Cookie>(this);
				c->SetPosition(j, c->GetPosition().y, i);
			}
		}
	}


	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	Instantiate<Gauge>(this);



	//Camera::SetPosition({ 0, 15, -11 });
	//Camera::SetTarget({ 0,0,3 });
}

void PlayScene::Update()
{
	if (FindObject("Cookie") == nullptr) {
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->ChangeScene(SCENE_ID_GAMECLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
