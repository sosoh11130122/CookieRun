#include "ObstacleC.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"
#include "../Collision/ColliderBox.h"
#include "Effect.h"
#include "../Scene/SceneResource.h"

CObstacleC::CObstacleC() :
	m_Damage(0.f),
	m_ColliderBox(NULL)
{
	SetTypeID<CObstacleC>();
}

CObstacleC::~CObstacleC()
{
}

bool CObstacleC::Init()
{
	CGameObject::Init();

	m_ColliderBox = AddCollider<CColliderBox>("ObstacleC");

	m_ColliderBox->SetExtent(70.f, 70.f);
	m_ColliderBox->SetOffset(0.5f, -35.f);
	m_ColliderBox->SetCollisionProfile("ObstacleC");

	m_ColliderBox->SetCollisionBeginFunction<CObstacleC>(this, &CObstacleC::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CObstacleC>(this, &CObstacleC::CollisionEnd);

	return true;
}

void CObstacleC::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CObstacleC::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CObstacleC::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CObstacleC::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	Dest->GetOwner()->InflictDamage(m_Damage);

	m_Scene->GetSceneResource()->LoadSound("BGM", "Obstacle", false, "Obstacle.wav");
	m_Scene->GetSceneResource()->SoundPlay("Obstacle");
	m_Scene->GetSceneResource()->SetVolume(50);
}

void CObstacleC::CollisionEnd(CCollider* Src, CCollider* Dest)
{
	SetActive(false);
}
