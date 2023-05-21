#include "ObstacleE.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"
#include "../Collision/ColliderBox.h"
#include "Effect.h"
#include "../Scene/SceneResource.h"

CObstacleE::CObstacleE() :
	m_Damage(0.f),
	m_ColliderBox(NULL)
{
	SetTypeID<CObstacleE>();
}

CObstacleE::~CObstacleE()
{
}

bool CObstacleE::Init()
{
	CGameObject::Init();

	m_ColliderBox = AddCollider<CColliderBox>("ObstacleE");

	m_ColliderBox->SetExtent(80.f, 330.f);
	m_ColliderBox->SetOffset(0.5f, 0.5f);
	m_ColliderBox->SetCollisionProfile("ObstacleE");

	m_ColliderBox->SetCollisionBeginFunction<CObstacleE>(this, &CObstacleE::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CObstacleE>(this, &CObstacleE::CollisionEnd);

	return true;
}

void CObstacleE::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CObstacleE::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CObstacleE::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CObstacleE::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	Dest->GetOwner()->InflictDamage(m_Damage);

	m_Scene->GetSceneResource()->LoadSound("BGM", "Obstacle", false, "Obstacle.wav");
	m_Scene->GetSceneResource()->SoundPlay("Obstacle");
	m_Scene->GetSceneResource()->SetVolume(50);
}

void CObstacleE::CollisionEnd(CCollider* Src, CCollider* Dest)
{
	SetActive(false);
}
