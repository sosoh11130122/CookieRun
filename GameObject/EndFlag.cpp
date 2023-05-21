#include "EndFlag.h"

CEndFlag::CEndFlag()
{
	SetTypeID<CEndFlag>();
}

CEndFlag::~CEndFlag()
{
}

bool CEndFlag::Init()
{
	m_ColliderBox = AddCollider<CColliderBox>("EndFlag");

	m_ColliderBox->SetExtent(259.875f, 520.f);
	m_ColliderBox->SetOffset(0.5f, 0.5f);
	m_ColliderBox->SetCollisionProfile("Flag");

	m_ColliderBox->SetCollisionBeginFunction<CEndFlag>(this, &CEndFlag::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CEndFlag>(this, &CEndFlag::CollisionEnd);

	CreateAnimation();

	AddAnimation("FlagOn", false, 0.8f);

	return true;
}

void CEndFlag::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CEndFlag::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CEndFlag::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CEndFlag::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	ChangeAnimation("FlagOn");
}

void CEndFlag::CollisionEnd(CCollider* Src, CCollider* Dest)
{
}
