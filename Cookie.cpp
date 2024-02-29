#include "Cookie.h"
#include "Engine/Model.h"
#include "Player.h"
#include "Engine/SphereCollider.h"

Cookie::Cookie(GameObject* parent)
	:GameObject(parent, "Cookie"), hModel_(-1)
{
}

Cookie::~Cookie()
{
}

void Cookie::Initialize()
{
	hModel_ = Model::Load("Model\\Cookie.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 0;
	transform_.position_.z = 0;
	transform_.position_.y = 0.2;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(-0.5, 0, 0.5), 0.25f);
	AddCollider(collision);
}

void Cookie::Update()
{
}

void Cookie::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Cookie::Release()
{
}

void Cookie::OnCollision(GameObject* pTarget)
{
	//’e‚É“–‚½‚Á‚½‚Æ‚«
	if (pTarget->GetObjectName() == "Player")
	{
		KillMe();
	}

}
