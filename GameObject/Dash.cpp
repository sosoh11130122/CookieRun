#include "Dash.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"

CDash::CDash()
{
    SetTypeID<CDash>();
}

CDash::~CDash()
{
}

bool CDash::Init()
{
	m_ColliderBox = AddCollider<CColliderBox>("Dash");

	m_ColliderBox->SetExtent(65.f, 76.f);
	m_ColliderBox->SetOffset(35.f, 37.f);
	m_ColliderBox->SetCollisionProfile("Dash");

	m_ColliderBox->SetCollisionBeginFunction<CDash>(this, &CDash::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CDash>(this, &CDash::CollisionEnd);

	CreateAnimation();

	AddAnimation("DashItem", true, 0.5f);

	return true;
}

void CDash::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CDash::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CDash::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CDash::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	m_Scene->GetSceneResource()->LoadSound("BGM", "Dash", false, "Item.wav");
	m_Scene->GetSceneResource()->SoundPlay("Dash");
	m_Scene->GetSceneResource()->SetVolume(50);

	SetActive(false);
}

void CDash::CollisionEnd(CCollider* Src, CCollider* Dest)
{	
}
