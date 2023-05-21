#include "Coin.h"

CCoin::CCoin() :
	m_Point(0)
{
	SetTypeID<CCoin>();
}

CCoin::~CCoin()
{
}

bool CCoin::Init()
{
	CGameObject::Init();

	CColliderBox* Box = AddCollider<CColliderBox>("Coin");

	Box->SetExtent(35.f, 30.f);
	Box->SetOffset(0.5f, 0.5f);
	Box->SetCollisionProfile("Coin");

	Box->SetCollisionBeginFunction<CCoin>(this, &CCoin::CollisionBegin);
	Box->SetCollisionEndFunction<CCoin>(this, &CCoin::CollisionEnd);

	return true;
}

void CCoin::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CCoin::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CCoin::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CCoin::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	SetActive(false);
}

void CCoin::CollisionEnd(CCollider* Src, CCollider* Dest)
{
	Dest->GetOwner()->PlusPoint(m_Point);
	Dest->GetOwner()->PlusCoin(m_Coin);
}
