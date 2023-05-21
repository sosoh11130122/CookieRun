#include "SizeUp.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"
#include "../Collision/ColliderBox.h"
#include "Effect.h"
#include "../Scene/SceneResource.h"

CSizeUp::CSizeUp() :
	m_ColliderBox(NULL)
{
    SetTypeID<CSizeUp>();
}

CSizeUp::~CSizeUp()
{
}

bool CSizeUp::Init()
{
	CGameObject::Init();

	m_ColliderBox = AddCollider<CColliderBox>("SizeUp");

	m_ColliderBox->SetExtent(65.f, 75.f);
	m_ColliderBox->SetOffset(35.f, 37.f);
	m_ColliderBox->SetCollisionProfile("SizeUp");

	m_ColliderBox->SetCollisionBeginFunction<CSizeUp>(this, &CSizeUp::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CSizeUp>(this, &CSizeUp::CollisionEnd);

	CreateAnimation();

	AddAnimation("SizeUpItem", true, 0.5f);

	return true;
}

void CSizeUp::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CSizeUp::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CSizeUp::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CSizeUp::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	m_Scene->GetSceneResource()->LoadSound("BGM", "SizeUp", false, "Item.wav");
	m_Scene->GetSceneResource()->SoundPlay("SizeUp");
	m_Scene->GetSceneResource()->SetVolume(50);

	SetActive(false);
}

void CSizeUp::CollisionEnd(CCollider* Src, CCollider* Dest)
{
}
