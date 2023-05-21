#include "Heart.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"

CHeart::CHeart() :
	m_HP(0),
	m_ColliderBox(NULL)
{
	SetTypeID<CHeart>();
}

CHeart::~CHeart()
{
}

bool CHeart::Init()
{
	CGameObject::Init();

	m_ColliderBox = AddCollider<CColliderBox>("Heart");

	m_ColliderBox->SetExtent(65.f, 76.f);
	m_ColliderBox->SetOffset(35.f, 37.f);
	m_ColliderBox->SetCollisionProfile("Heart");

	m_ColliderBox->SetCollisionBeginFunction<CHeart>(this, &CHeart::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CHeart>(this, &CHeart::CollisionEnd);

	CreateAnimation();

	AddAnimation("Heart", true, 0.5f);

	return true;
}

void CHeart::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CHeart::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CHeart::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CHeart::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	m_Scene->GetSceneResource()->LoadSound("BGM", "Heart", false, "Item.wav");
	m_Scene->GetSceneResource()->SoundPlay("Heart");
	m_Scene->GetSceneResource()->SetVolume(50);

	SetActive(false);
	Dest->GetOwner()->PlusHP(m_HP);
}

void CHeart::CollisionEnd(CCollider* Src, CCollider* Dest)
{

}
