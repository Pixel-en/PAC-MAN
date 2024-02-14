#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Stage.h"

namespace {
	const float PLAYER_SPEED{ 0.1f };
}

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), speed_(PLAYER_SPEED), pStage_(nullptr)
	, hpCrr_(100), hpMax_(100)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage*)FindObject("Stage");
	rottmp_ = 0.0;
}

void Player::Update()
{
	XMVECTOR vFront = { 0, 0, 1, 0 };
	XMVECTOR move{ 0, 0, 0, 0 };

	float bufferX = 0;
	float bufferZ = 0;

	if (Input::IsKey(DIK_UP))
	{
		move = XMVECTOR{ 0, 0, 1, 0 };
		//moveDir = Dir::UP;
		bufferZ = +0.3;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		move = XMVECTOR{ -1, 0, 0, 0 };
		//moveDir = Dir::LEFT;
		bufferX = -0.3;
	}
	if (Input::IsKey(DIK_DOWN))
	{
		move = XMVECTOR{ 0, 0, -1, 0 };
		//moveDir = Dir::DOWN;
		bufferZ = -0.3;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		move = XMVECTOR{ 1, 0, 0, 0 };
		//moveDir = Dir::RIGHT;
		bufferX = +0.3;
	}


	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTmp = XMVectorZero(); //ƒ[ƒƒxƒNƒgƒ‹‚Å‰Šú‰»
	posTmp = pos + speed_ * move;

	int tx, ty;
	tx = (int)(XMVectorGetX(posTmp)+1.0f+bufferX);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 1.0f+bufferZ);
	if (!(pStage_->IsWall(tx, ty)))
	{
		pos = posTmp;
	}
	else {

		hpCrr_ = hpCrr_ - 2;
		if (hpCrr_ < 0)
			hpCrr_ = 0;
	}
	pGauge_ = (Gauge*)FindObject("Gauge");
	pGauge_->SetGaugeCrrVal(hpCrr_);
	pGauge_->SetGaugeMaxVal(hpMax_);
	


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

	rottmp_ += 10.0;

	//XMMATRIX tmp;
	//tmp = XMMatrixRotationY(XMConvertToDegrees(rottmp_));
	//move = XMVector3TransformCoord(move, tmp);


	if (!XMVector3Equal(move, XMVectorZero())) {
		XMStoreFloat3(&(transform_.position_), pos);
		
		Debug::Log("X=");
		Debug::Log(XMVectorGetX(move),true);
		Debug::Log("Y=");
		Debug::Log(XMVectorGetY(move), true);
		Debug::Log("Z=");
		Debug::Log(XMVectorGetZ(move), true);

		//XMMATRIX rot = XMMatrixRotationY(XM_PIDIV2);
		//XMVECTOR modifiedVec = XMPlaneTransform(move, rot);

		//Debug::Log(XMVectorGetX(modifiedVec));
		//Debug::Log(",");
		//Debug::Log(XMVectorGetZ(modifiedVec), TRUE);


		float angle = atan2(XMVectorGetX(move), XMVectorGetZ(move));

		//Debug::Log("=>");
		//Debug::Log(XMConvertToDegrees(angle), true);

		//XMVECTOR vdot = XMVector3Dot(vFront, move);
		//assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
		//float angle = acos(XMVectorGetX(vdot));

		//XMVECTOR vCross = XMVector3Cross(vFront, move);
		//if (XMVectorGetY(vCross) < 0)
		//{
		//	angle *= -1;
		//}


		transform_.rotate_.y = XMConvertToDegrees(angle);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
