#include "Enemy.h"
#include "Engine/Model.h"
#include "Stage.h"
#include "Engine/Debug.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1), speed_(0.12f), pStage_(nullptr),framecnt(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);


	transform_.position_.x = 5;
	transform_.position_.z = 5;

	movedir = rand() % 4;
	pStage_ = (Stage*)FindObject("Stage");

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.3, 0), 0.3f);
	AddCollider(collision);
}

void Enemy::Update()
{
	framecnt++;

	XMVECTOR vFront = { 0, 0, 1, 0 };
	XMVECTOR move{ 0, 0, 0, 0 };

	float bufferX = 0;
	float bufferZ = 0;

	enum Dir
	{
		up, left, down, right
	};

	switch (movedir)
	{
	case Dir::up:
		move = XMVECTOR{ 0, 0, 1, 0 };
		bufferZ = +0.3;
		break;
	case Dir::left:
		move = XMVECTOR{ -1, 0, 0, 0 };
		bufferX = -0.3;
		break;
	case Dir::down:
		move = XMVECTOR{ 0, 0, -1, 0 };
		bufferZ = -0.3;
		break;
	case Dir::right:
		move = XMVECTOR{ 1, 0, 0, 0 };
		bufferX = +0.3;
		break;
	default:
		move = XMVECTOR{ 0,0,0,0 };
		break;
	}

	//if (movedir=Dir::up)
	//{
	//	move = XMVECTOR{ 0, 0, 1, 0 };
	//	bufferZ = +0.3;
	//}
	//if (movedir = Dir::left)
	//{
	//	move = XMVECTOR{ -1, 0, 0, 0 };
	//	bufferX = -0.3;
	//}
	//if (movedir = Dir::down)
	//{
	//	move = XMVECTOR{ 0, 0, -1, 0 };
	//	bufferZ = -0.3;
	//}
	//if (movedir = Dir::right)
	//{
	//	move = XMVECTOR{ 1, 0, 0, 0 };
	//	bufferX = +0.3;
	//}


	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTmp = XMVectorZero(); //ƒ[ƒƒxƒNƒgƒ‹‚Å‰Šú‰»
	posTmp = pos + speed_ * move;

	int tx, ty;
	tx = (int)(XMVectorGetX(posTmp) + 1.0f + bufferX);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 1.0f + bufferZ);
	if (!(pStage_->IsWall(tx, ty)))
	{
		pos = posTmp;
	}
	else
		movedir = rand() % 4;

	if (framecnt > 350) {
		framecnt = 0;
		movedir = rand() % 4;
	}

	Debug::Log(movedir,TRUE);

	//Debug::Log("(X,Z)=");
	//Debug::Log(XMVectorGetX(pos));
	//Debug::Log(",");
	//Debug::Log(XMVectorGetZ(pos), true);

	//Debug::Log("(iX,iZ)=");
	//Debug::Log(tx);
	//Debug::Log(",");
	//Debug::Log(ty);
	//Debug::Log(" : ");
	//Debug::Log(pStage_->IsWall(tx, ty), true);

	//XMMATRIX tmp;
	//tmp = XMMatrixRotationY(XMConvertToDegrees(rottmp_));
	//move = XMVector3TransformCoord(move, tmp);


	if (!XMVector3Equal(move, XMVectorZero())) {
		XMStoreFloat3(&(transform_.position_), pos);


		float angle = atan2(XMVectorGetX(move), XMVectorGetZ(move));

		transform_.rotate_.y = XMConvertToDegrees(angle);
	}


}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
