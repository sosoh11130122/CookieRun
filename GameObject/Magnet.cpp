#include "Magnet.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"

CMagnet::CMagnet() :
	m_ColliderBox(NULL)
{
	SetTypeID<CMagnet>();
}

CMagnet::~CMagnet()
{
}

bool CMagnet::Init()
{
	CGameObject::Init();

	m_ColliderBox = AddCollider<CColliderBox>("Magnet");

	m_ColliderBox->SetExtent(65.f, 76.f);
	m_ColliderBox->SetOffset(35.f, 37.f);
	m_ColliderBox->SetCollisionProfile("Magnet");

	m_ColliderBox->SetCollisionBeginFunction<CMagnet>(this, &CMagnet::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CMagnet>(this, &CMagnet::CollisionEnd);

	CreateAnimation();

	AddAnimation("Magnet", true, 0.5f);

	return true;
}

void CMagnet::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CMagnet::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CMagnet::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	m_Scene->GetSceneResource()->LoadSound("BGM", "Magnet", false, "Item.wav");
	m_Scene->GetSceneResource()->SoundPlay("Magnet");
	m_Scene->GetSceneResource()->SetVolume(50);

	SetActive(false);
}

void CMagnet::CollisionEnd(CCollider* Src, CCollider* Dest)
{
}
