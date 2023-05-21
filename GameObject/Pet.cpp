#include "Pet.h"
#include "../Scene/MainScene.h"
#include "../Widget/CharacterHUD.h"
#include "../GameManager.h"
#include "../Scene/SceneResource.h"

CPet::CPet() :
	m_ColliderBox(NULL)
{
	SetTypeID<CPet>();
}

CPet::~CPet()
{
}

bool CPet::Init()
{
	SetPivot(0.5f, 0.5f);

	m_ColliderBox = AddCollider<CColliderBox>("Pet");

	m_ColliderBox->SetExtent(50.f, 50.f);
	m_ColliderBox->SetOffset(0.5f, 0.5f);
	m_ColliderBox->SetCollisionProfile("Pet");

	m_ColliderBox->SetCollisionBeginFunction<CPet>(this, &CPet::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CPet>(this, &CPet::CollisionEnd);

	CreateAnimation();

	AddAnimation("PetIdle", true, 0.3f);
	AddAnimation("PetMagnet", true, 0.3f);

	return true;
}

void CPet::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	//Vector2	Pos;
	//Pos.x = m_Pos.x + cosf(DegreeToRadian(m_PetAngle)) * m_PetDistance + 330.f;
	//Pos.y = m_Pos.y + sinf(DegreeToRadian(m_PetAngle)) * m_PetDistance;

	//SetPos(Pos);
}

void CPet::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

void CPet::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	CGameManager::GetInst()->SetScore(m_Point);
	CGameManager::GetInst()->SetCoinScore(m_Coin);

	if (Dest->GetName() == "JellyBean")
	{
		m_Point += 720;

		m_Scene->FindWidget<CCharacterHUD>("CharacterHUD")->SetPoint(m_Point);
	}

	if (Dest->GetName() == "Coin")
	{
		m_Scene->GetSceneResource()->LoadSound("BGM", "Coin", false, "coin.wav");
		m_Scene->GetSceneResource()->SoundPlay("Coin");
		m_Scene->GetSceneResource()->SetVolume(50);

		m_Point += 204;

		m_Coin += 1;

		m_Scene->FindWidget<CCharacterHUD>("CharacterHUD")->SetPoint(m_Point);
		m_Scene->FindWidget<CCharacterHUD>("CharacterHUD")->SetCoin(m_Coin);
	}
}

void CPet::CollisionEnd(CCollider* Src, CCollider* Dest)
{
}
