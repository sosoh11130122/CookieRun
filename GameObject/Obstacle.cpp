#include "Obstacle.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"
#include "../Collision/ColliderBox.h"
#include "Effect.h"
#include "../Scene/SceneResource.h"

CObstacle::CObstacle() :
	m_Damage(0.f),
	m_ColliderBox(NULL)
{
	SetTypeID<CObstacle>();
}

CObstacle::~CObstacle()
{
}

bool CObstacle::Init()
{
	CGameObject::Init();

	m_ColliderBox = AddCollider<CColliderBox>("Obstacle");

	m_ColliderBox->SetExtent(45.f, 35.f);
	m_ColliderBox->SetOffset(0.5f, -15.f);
	m_ColliderBox->SetCollisionProfile("Obstacle");

	m_ColliderBox->SetCollisionBeginFunction<CObstacle>(this, &CObstacle::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CObstacle>(this, &CObstacle::CollisionEnd);

    return true;
}

void CObstacle::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CObstacle::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CObstacle::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CObstacle::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	Dest->GetOwner()->InflictDamage(m_Damage);

	m_Scene->GetSceneResource()->LoadSound("BGM", "Obstacle", false, "Obstacle.wav");
	m_Scene->GetSceneResource()->SoundPlay("Obstacle");
	m_Scene->GetSceneResource()->SetVolume(50);
}

void CObstacle::CollisionEnd(CCollider* Src, CCollider* Dest)
{
	SetActive(false);
}
