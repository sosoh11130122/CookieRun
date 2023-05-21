
#include "Player.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneManager.h"
#include "Bullet.h"
#include "Tornado.h"
#include "AurelionSol.h"
#include "../Input.h"
#include "../GameManager.h"
#include "../Scene/Camera.h"
#include "../Collision/ColliderBox.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"
#include "../Widget/CharacterHUD.h"
#include "../Widget/WidgetComponent.h"
#include "../Widget/Text.h"
#include "../Widget/ProgressBar.h"
#include "../Widget/ImageWidget.h"
#include "../Collision/Collider.h"
#include "../Scene/EndScene.h"
#include "../Widget/EndWindow.h"
#include "../GameObject/Pet.h"
#include "../GameObject/Obstacle.h"
#include "../GameObject/ObstacleC.h"
#include "../GameObject/ObstacleE.h"


CPlayer::CPlayer() :
	m_HP(70),
	m_GamePlayTime(0.f),
	m_ItemTime(0.f),
	m_ColliderBox(NULL),
	m_Collision(false),
	m_Dash(false),
	m_Dead(false),
	m_GameOverTime(0.f),
	m_HPMax(100),
	m_Magnet(false),
	m_MoveTime(0.f),
	m_PetAngle(0.f),
	m_PetDistance(0.f),
	m_PlayerDir(0),
	m_Slide(false),
	m_MagnetCollider(NULL),
	m_SizeUp(false)
{
	SetTypeID<CPlayer>();
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	CGameObject::Init();

	m_JumpCount = 0;
	m_PlayerDir = 1;
	m_MoveSpeed = 350.f;

	SetPos(100.f, 100.f);
	SetSize(240.f, 240.f);
	SetPivot(0.5f, 1.f);


	SetTexture("Player", TEXT("Player/Run/idle.bmp"));
	SetColorKey(0, 0, 0);

	


	CreateAnimation();

	AddAnimation("PlayerIdle", true, 0.3f);
	AddAnimation("PlayerJump", false, 0.15f); 
	AddAnimation("PlayerJump2", false, 0.8f);
	AddAnimation("PlayerSlide", true, 0.15f);
	AddAnimation("PlayerDash", true, 0.2f);
	AddAnimation("PlayerCollision", false, 0.3f);
	AddAnimation("PlayerDead", false, 0.8f);

	AddAnimation("SizeUpIdle", true, 0.3f);
	AddAnimation("SizeUpJump", false, 0.15f);
	AddAnimation("SizeUpJump2", false, 0.3f);
	//AddAnimation("SizeUpSlide", true, 0.15f);

	//SetEndFunction<CPlayer>("PlayerRightAttack", this, &CPlayer::AttackEnd);
	////SetEndFunction<CPlayer>("PlayerLeftAttack", this, &CPlayer::AttackEnd);

	//AddNotify<CPlayer>("PlayerRightAttack", 2, this, &CPlayer::Attack);
	////AddNotify<CPlayer>("PlayerLeftAttack", 2, this, &CPlayer::Attack);

	//m_vecSequenceKey[0].push_back("PlayerIdle");
	//m_vecSequenceKey[0].push_back("PlayerJump");
	//m_vecSequenceKey[0].push_back("PlayerJump2");
	//m_vecSequenceKey[0].push_back("PlayerSlide");
	//m_vecSequenceKey[0].push_back("PlayerDash");
	//m_vecSequenceKey[0].push_back("PlayerCollision");
	//m_vecSequenceKey[0].push_back("PlayerDead");


	//m_vecSequenceKey[0].push_back("SizeUpIdle");
	//m_vecSequenceKey[0].push_back("SizeUpJump");
	//m_vecSequenceKey[0].push_back("SizeUpJump2");
	//m_vecSequenceKey[0].push_back("SizeUpSlide");
	//m_vecSequenceKey[0].push_back("SizeUpDead");
	//m_vecSequenceKey[0].push_back("SizeUpDash");

	// 오른쪽 보고 있음.
	m_PlayerDir = 1;

	m_ColliderBox = AddCollider<CColliderBox>("Player");

	m_ColliderBox->SetExtent(55.f, 78.f);
	m_ColliderBox->SetOffset(20.f, -65.f);
	m_ColliderBox->SetCollisionProfile("Player");
	m_ColliderBox->SetCollisionBeginFunction<CPlayer>(this, &CPlayer::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CPlayer>(this, &CPlayer::CollisionEnd);

	m_MagnetCollider = AddCollider<CColliderBox>("PlayerMagnet");
	m_MagnetCollider->SetExtent(10.f, 10.f);
	m_MagnetCollider->SetOffset(10.f, -40.f);
	m_MagnetCollider->SetCollisionProfile("PlayerMagnet");
	m_MagnetCollider->SetCollisionBeginFunction<CPlayer>(this, &CPlayer::CollisionBegin);
	m_MagnetCollider->SetCollisionEndFunction<CPlayer>(this, &CPlayer::CollisionEnd);

	CInput::GetInst()->AddBindFunction<CPlayer>("MoveFront", 
		Input_Type::Push, this, &CPlayer::MoveFront, m_Scene);

	CInput::GetInst()->AddBindFunction<CPlayer>("Jump",
		Input_Type::Down, this, &CPlayer::JumpKey, m_Scene);

	CInput::GetInst()->AddBindFunction<CPlayer>("Jump",
		Input_Type::Up, this, &CPlayer::JumpKeyBack, m_Scene);

	CInput::GetInst()->AddBindFunction<CPlayer>("Slide",
		Input_Type::Down, this, &CPlayer::Slide, m_Scene);

	CInput::GetInst()->AddBindFunction<CPlayer>("Slide",
		Input_Type::Up, this, &CPlayer::SlideUp, m_Scene);

	m_HPMax = 100;

	m_Pet = m_Scene->CreateObject<CPet>("Pet");

	m_PetAngle = 240.f;
	m_PetDistance = 150.f;

	Vector2	Pos;
	Pos.x = m_Pos.x + cosf(DegreeToRadian(m_PetAngle)) * m_PetDistance;
	Pos.y = m_Pos.y + sinf(DegreeToRadian(m_PetAngle)) * m_PetDistance;

	m_Pet->SetPos(Pos);

	SetPhysicsSimulate(true);
	SetJumpVelocity(40.f);
	SetSideWallCheck(true);

	return true;
}

void CPlayer::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);

	DeltaTime *= m_TimeScale;

	m_GamePlayTime += DeltaTime;

	m_Pos.x += m_MoveSpeed * DeltaTime;

	if (m_GamePlayTime >= 1.f)
	{
		--m_HP;

		m_Scene->FindWidget<CCharacterHUD>("CharacterHUD")->SetHP(m_HP / (float)m_HPMax);

		m_GamePlayTime = 0.f;
	}
	
	if (m_Pos.y >= 520.f || m_Pos.x >= 15000.f)
	{
		m_GameOverTime += DeltaTime;

		if (m_GameOverTime >= 1.f)
			m_HP = 0;

		if (m_GameOverTime >= 4.f)
			GameOver();
	}

	Vector2	Pos;
	Pos.x = m_Pos.x + cosf(DegreeToRadian(m_PetAngle)) * m_PetDistance;
	Pos.y = m_Pos.y + sinf(DegreeToRadian(m_PetAngle)) * m_PetDistance;

	m_Pet->SetPos(Pos);

	if (m_HP <= 0)
	{
		m_GameOverTime += DeltaTime;

		m_MoveSpeed = 0.f;

		ChangeAnimation("PlayerDead");

		if (m_GameOverTime >= 3.f)
			GameOver();
	}

	if ((m_Move.x != 0.f || m_Move.y != 0.f) && !m_Jump && !m_Slide && m_Ground && !m_Dash)
	{
		ChangeAnimation("PlayerIdle");
	}

	else if (m_Slide)
	{
		ChangeAnimation("PlayerSlide");

	}

	else if (m_Jump)
	{
		if (m_JumpCount == 1)
		{
			ChangeAnimation("PlayerJump");
		}

		else if (m_JumpCount == 2)
		{
			ChangeAnimation("PlayerJump2");
			m_JumpCount = 0;
		}
	}

	else if (m_Dash == true)
	{
		m_ItemTime += DeltaTime;

		ChangeAnimation("PlayerDash");

		if (m_ItemTime >= 6.f)
		{
			m_MoveSpeed = 350.f;

			m_Dash = false;

			m_Collision = true;

			m_ItemTime = 0.f;

			ChangeAnimation("PlayerIdle");
		}
	}

	//if (m_SizeUp == true)
	//{
	//	m_ItemTime += DeltaTime;

	//	ChangeAnimation("SizeUpIdle");

	//	if (m_ItemTime >= 4.f)
	//	{
	//		m_SizeUp = false;

	//		m_ColliderBox->SetExtent(55.f, 78.f);
	//		m_ColliderBox->SetOffset(20.f, -65.f);

	//		m_Collision = true;

	//		m_ItemTime = 0.f;

	//		ChangeAnimation("PlayerIdle");
	//	}
	//}

	if (m_Magnet == true)
	{
		m_ItemTime += DeltaTime;

		Vector2	Pos;
		Pos.x = m_Pos.x + cosf(DegreeToRadian(m_PetAngle)) * m_PetDistance + 330.f;
		Pos.y = m_Pos.y + sinf(DegreeToRadian(m_PetAngle)) * m_PetDistance;

		m_Pet->SetPos(Pos);

		m_Pet->ChangeAnimation("PetMagnet");

		if (m_ItemTime >= 9.f)
		{
			m_Magnet = false;

			m_MagnetCollider->SetExtent(10.f, 10.f);
			m_MagnetCollider->SetOffset(10.f, -40.f);

			Vector2	Pos;
			Pos.x = m_Pos.x + cosf(DegreeToRadian(m_PetAngle)) * m_PetDistance;
			Pos.y = m_Pos.y + sinf(DegreeToRadian(m_PetAngle)) * m_PetDistance;

			m_Pet->SetPos(Pos);

			m_ItemTime = 0.f;

			m_Pet->ChangeAnimation("PetIdle");
		}
	}

}

void CPlayer::PostUpdate(float DeltaTime)
{
	CCharacter::PostUpdate(DeltaTime);

	//if ((m_Move.x != 0.f || m_Move.y != 0.f) && !m_Jump && !m_Slide && m_Ground && !m_Dash)
	//{
	//	ChangeAnimation("PlayerIdle");
	//}

	//else if (m_Slide)
	//{
	//	ChangeAnimation("PlayerSlide");

	//}

	//else if (m_Jump)
	//{
	//	if (m_JumpCount == 1)
	//	{
	//		ChangeAnimation("PlayerJump");
	//	}

	//	else if (m_JumpCount == 2)
	//	{
	//		ChangeAnimation("PlayerJump2");
	//	}
	//}

	//else if (m_Dash == true)
	//{
	//	m_ItemTime += DeltaTime;

	//	ChangeAnimation("PlayerDash");

	//	if (m_ItemTime >= 6.f)
	//	{
	//		m_MoveSpeed = 350.f;

	//		m_Dash = false;

	//		m_Collision = true;

	//		m_ItemTime = 0.f;

	//		ChangeAnimation("PlayerIdle");
	//	}
	//}

	////if (m_SizeUp == true)
	////{
	////	m_ItemTime += DeltaTime;

	////	ChangeAnimation("SizeUpIdle");


	////	if (m_ItemTime >= 4.f)
	////	{
	////		m_SizeUp = false;

	////		m_ColliderBox->SetExtent(55.f, 78.f);
	////		m_ColliderBox->SetOffset(20.f, -65.f);

	////		m_Collision = true;

	////		m_ItemTime = 0.f;

	////		ChangeAnimation("PlayerIdle");
	////	}
	////}

	//if (m_Magnet == true)
	//{
	//	m_ItemTime += DeltaTime;

	//	Vector2	Pos;
	//	Pos.x = m_Pos.x + cosf(DegreeToRadian(m_PetAngle)) * m_PetDistance + 330.f;
	//	Pos.y = m_Pos.y + sinf(DegreeToRadian(m_PetAngle)) * m_PetDistance;

	//	m_Pet->SetPos(Pos);

	//	m_Pet->ChangeAnimation("PetMagnet");

	//	if (m_ItemTime >= 9.f)
	//	{
	//		m_Magnet = false;

	//		m_MagnetCollider->SetExtent(10.f, 10.f);
	//		m_MagnetCollider->SetOffset(10.f, -40.f);

	//		Vector2	Pos;
	//		Pos.x = m_Pos.x + cosf(DegreeToRadian(m_PetAngle)) * m_PetDistance;
	//		Pos.y = m_Pos.y + sinf(DegreeToRadian(m_PetAngle)) * m_PetDistance;

	//		m_Pet->SetPos(Pos);

	//		m_ItemTime = 0.f;

	//		m_Pet->ChangeAnimation("PetIdle");
	//	}
	//}
}

void CPlayer::Render(HDC hDC, float DeltaTime)
{
	CCharacter::Render(hDC, DeltaTime);

	Vector2	Pos = m_Pos - m_Scene->GetCamera()->GetPos();

	MoveToEx(hDC, (int)Pos.x, (int)Pos.y, nullptr);
	//LineTo(hDC, (int)GunPos.x, (int)GunPos.y);
}

float CPlayer::InflictDamage(float Damage)
{
	Damage = CCharacter::InflictDamage(Damage);

	m_HP -= (int)Damage;

	return Damage;
}

void CPlayer::MoveFront()
{
	//Move(m_GunAngle);
	MoveDir(Vector2(0.f, -1.f));
}

void CPlayer::JumpKey()
{
	m_Scene->GetSceneResource()->LoadSound("BGM", "Jump", false, "jump.wav");
	m_Scene->GetSceneResource()->SoundPlay("Jump");
	m_Scene->GetSceneResource()->SetVolume(50);

	Jump();

	m_Jump = true;
}

void CPlayer::JumpKeyBack()
{

}

void CPlayer::Slide()
{
	m_Scene->GetSceneResource()->LoadSound("BGM", "Slide", false, "slide.wav");
	m_Scene->GetSceneResource()->SoundPlay("Slide");
	m_Scene->GetSceneResource()->SetVolume(50);

	m_Slide = true;

	m_ColliderBox->SetExtent(65.f, 60.f);
	m_ColliderBox->SetOffset(-10.f, -35.f);
	m_ColliderBox->SetCollisionProfile("Player");
	m_ColliderBox->SetCollisionBeginFunction<CPlayer>(this, &CPlayer::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CPlayer>(this, &CPlayer::CollisionEnd);

}

void CPlayer::SlideUp()
{
	m_Slide = false;

	m_ColliderBox->SetExtent(55.f, 108.f);
	m_ColliderBox->SetOffset(20.f, -55.f);
	m_ColliderBox->SetCollisionProfile("Player");
	m_ColliderBox->SetCollisionBeginFunction<CPlayer>(this, &CPlayer::CollisionBegin);
	m_ColliderBox->SetCollisionEndFunction<CPlayer>(this, &CPlayer::CollisionEnd);
}

void CPlayer::SizeUp()
{
}

void CPlayer::Dash()
{
	m_Dash = true;
}


void CPlayer::CollisionBegin(CCollider* Src, CCollider* Dest)
{
	CGameManager::GetInst()->SetScore(m_Point);
	CGameManager::GetInst()->SetCoinScore(m_Coin);
	
	if (Dest->GetName() == "Obstacle" || Dest->GetName() == "ObstacleC" || Dest->GetName() == "ObstacleE")
	{
		if (m_Collision == true)
		{
			ChangeAnimation("PlayerCollision");

			m_HP -= 10;
	
			m_Scene->FindWidget<CCharacterHUD>("CharacterHUD")->SetHP(m_HP / (float)m_HPMax);
		}
	}
	
	//m_HPBar->GetWidget<CProgressBar>("HPBar")->SetValue(m_HP / (float)m_HPMax);
	
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
	  
	if (Dest->GetName() == "Heart")
	{
		m_HP += 10;
	
		if (m_HP >= 100)
			m_HP = 100;
	
		m_Scene->FindWidget<CCharacterHUD>("CharacterHUD")->SetPoint(m_Point);
	}
	
	if (Dest->GetName() == "Dash")
	{
		m_Dash = true;
		m_Collision = false;

		m_MoveSpeed = 500.f;
	}
	
	/*if (Dest->GetName() == "SizeUp")
	{
		m_SizeUp = true;
		m_Collision = false;
	
		m_ColliderBox->SetExtent(220.f, 220.f);
		m_ColliderBox->SetOffset(20.f, -85.f);

		ChangeAnimation("SizeUpIdle");
	}*/
	
	if (Dest->GetName() == "Magnet")
	{
		m_Magnet = true;

		m_MagnetCollider->SetExtent(10.f, 280.f);
		m_MagnetCollider->SetOffset(280.f, -220.f);

		if (m_Collision == true)
		{
			ChangeAnimation("PlayerCollision");

			m_HP -= 10;

			m_Scene->FindWidget<CCharacterHUD>("CharacterHUD")->SetHP(m_HP / (float)m_HPMax);
		}
	}
	
	if (Dest->GetName() == "Flag")
	{
	}
}

void CPlayer::CollisionEnd(CCollider* Src, CCollider* Dest)
{
}

void CPlayer::GameOver()
{
	CSceneManager::GetInst()->CreateScene<CEndScene>();
}
