#include "Jelly.h"
#include "../Collision/ColliderBox.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"

CJelly::CJelly() :
	m_Point(0)
{
	SetTypeID<CJelly>();
}

CJelly::~CJelly()
{
}

bool CJelly::Init()
{
	CGameObject::Init();

	CColliderBox* Box = AddCollider<CColliderBox>("JellyBean");

	Box->SetExtent(35.f, 30.f);
	Box->SetOffset(0.5f, 0.5f);
	Box->SetCollisionProfile("JellyBean");

	Box->SetCollisionBeginFunction<CJelly>(this, &CJelly::CollisionBegin);
	Box->SetCollisionEndFunction<CJelly>(this, &CJelly::CollisionEnd);

	return true;
}

void CJelly::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CJelly::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CJelly::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CJelly::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	SetActive(false);

	m_Scene->GetSceneResource()->LoadSound("BGM", "Jelly", false, "Jelly.wav");
	m_Scene->GetSceneResource()->SoundPlay("Jelly");
	m_Scene->GetSceneResource()->SetVolume(40);
}

void CJelly::CollisionEnd(CCollider* Src, CCollider* Dest)
{
	Dest->GetOwner()->PlusPoint(m_Point);
}
