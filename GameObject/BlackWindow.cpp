#include "BlackWindow.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Stage2Scene.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"
#include "../Collision/ColliderBox.h"
#include "Effect.h"
#include "../Collision/Collider.h"

CBlackWindow::CBlackWindow()
{
}

CBlackWindow::~CBlackWindow()
{
}

bool CBlackWindow::Init()
{
	CGameObject::Init();

	m_ColliderBox = AddCollider<CColliderBox>("BlackWindow");

	m_ColliderBox->SetExtent(800.f, 520.f);
	m_ColliderBox->SetOffset(0.5f, 0.5f);
	m_ColliderBox->SetCollisionProfile("BlackWindow");

	m_ColliderBox->SetCollisionBeginFunction<CBlackWindow>(this, &CBlackWindow::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CBlackWindow>(this, &CBlackWindow::CollisionEnd);

	return true;
}

void CBlackWindow::Update(float DeltaTime)
{
    CGameObject::Update(DeltaTime);
}

void CBlackWindow::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CBlackWindow::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CBlackWindow::CollisionBegin(CCollider* Src, CCollider* Dest)
{
}

void CBlackWindow::CollisionEnd(CCollider* Src, CCollider* Dest)
{
}
