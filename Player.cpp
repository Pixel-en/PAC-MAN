#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

namespace {
	const float PLAYER_SPEED{ 0.1f };
}

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{

	XMVECTOR move = { 0,0,1,0 };

	XMVECTOR vFront{ 0,0,1,0 };

	if (Input::IsKey(DIK_UP)) {
		move = XMVECTOR{ 0,0,1,0 };
	}
	if (Input::IsKey(DIK_DOWN)) {
		move = XMVECTOR{ 0,0,-1,0 };
	}
	if (Input::IsKey(DIK_LEFT)) {
		move = XMVECTOR{ -1,0,0,0 };
	}
	if (Input::IsKey(DIK_RIGHT)) {
		move = XMVECTOR{ 1,0,0,0 };
	}

	XMVECTOR pos;
	pos = XMLoadFloat3((&transform_.position_));
	pos = pos + move * PLAYER_SPEED;

	XMStoreFloat3(&transform_.position_, pos);

	XMVECTOR vdot = XMVector3Dot(vFront, move);
	float angle = acos(XMVectorGetX(vdot));

	XMVECTOR vCross = XMVector3Cross(vFront, move);
	if (XMVectorGetY(vCross) < 0)
		angle *= -1;

	transform_.position_.y = XMConvertToDegrees(angle);
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
