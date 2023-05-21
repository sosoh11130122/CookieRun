
#include "CollisionManager.h"
#include "ColliderBox.h"
#include "ColliderCircle.h"

DEFINITION_SINGLE(CCollisionManager)

CCollisionManager::CCollisionManager()
{
}

CCollisionManager::~CCollisionManager()
{
	auto	iter = m_mapProfile.begin();
	auto	iterEnd = m_mapProfile.end();

	for (; iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}
}

bool CCollisionManager::Init()
{
	CreateProfile("Default", ECollision_Channel::Default, true);
	CreateProfile("Player", ECollision_Channel::Player, true, ECollision_Interaction::Ignore);
	CreateProfile("Mouse", ECollision_Channel::Mouse, true, ECollision_Interaction::Collision);
	CreateProfile("JellyBean", ECollision_Channel::JellyBean, true, ECollision_Interaction::Ignore);
	CreateProfile("Obstacle", ECollision_Channel::Obstacle, true, ECollision_Interaction::Ignore);
	CreateProfile("ObstacleC", ECollision_Channel::Obstacle, true, ECollision_Interaction::Ignore);
	CreateProfile("ObstacleE", ECollision_Channel::Obstacle, true, ECollision_Interaction::Ignore);
	CreateProfile("BlackWindow", ECollision_Channel::BlackWindow, true, ECollision_Interaction::Ignore);
	CreateProfile("Coin", ECollision_Channel::Coin, true, ECollision_Interaction::Ignore);
	CreateProfile("SizeUp", ECollision_Channel::SizeUp, true, ECollision_Interaction::Ignore);
	CreateProfile("Heart", ECollision_Channel::Heart, true, ECollision_Interaction::Ignore);
	CreateProfile("Dash", ECollision_Channel::Dash, true, ECollision_Interaction::Ignore);
	CreateProfile("Flag", ECollision_Channel::Flag, true, ECollision_Interaction::Ignore);
	CreateProfile("Pet", ECollision_Channel::Pet, true, ECollision_Interaction::Ignore);
	CreateProfile("Magnet", ECollision_Channel::Magnet, true, ECollision_Interaction::Ignore);
	CreateProfile("PlayerMagnet", ECollision_Channel::Player, true, ECollision_Interaction::Ignore);



	SetCollisionInteraction("Player", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::MonsterAttack, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::Monster, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::Mouse, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::JellyBean, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::Obstacle, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::BlackWindow, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::Coin, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::SizeUp, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::Heart, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::Dash, ECollision_Interaction::Collision);
	SetCollisionInteraction("Player", ECollision_Channel::Magnet, ECollision_Interaction::Collision);

	SetCollisionInteraction("JellyBean", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("JellyBean", ECollision_Channel::Player, ECollision_Interaction::Collision);
	SetCollisionInteraction("JellyBean", ECollision_Channel::Pet, ECollision_Interaction::Collision);

	SetCollisionInteraction("Obstacle", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Obstacle", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("ObstacleC", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("ObstacleC", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("ObstacleE", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("ObstacleE", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("BlackWindow", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("BlackWindow", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("Coin", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Coin", ECollision_Channel::Player, ECollision_Interaction::Collision);
	SetCollisionInteraction("Coin", ECollision_Channel::Pet, ECollision_Interaction::Collision);

	SetCollisionInteraction("SizeUp", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("SizeUp", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("Heart", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Heart", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("Dash", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Dash", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("Flag", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Flag", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("Magnet", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Magnet", ECollision_Channel::Player, ECollision_Interaction::Collision);

	SetCollisionInteraction("Pet", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("Pet", ECollision_Channel::JellyBean, ECollision_Interaction::Collision);
	SetCollisionInteraction("Pet", ECollision_Channel::Coin, ECollision_Interaction::Collision);

	SetCollisionInteraction("PlayerMagnet", ECollision_Channel::Default, ECollision_Interaction::Collision);
	SetCollisionInteraction("PlayerMagnet", ECollision_Channel::JellyBean, ECollision_Interaction::Collision);
	SetCollisionInteraction("PlayerMagnet", ECollision_Channel::Coin, ECollision_Interaction::Collision);


	return true;
}

bool CCollisionManager::CreateProfile(const std::string& Name, ECollision_Channel Channel, 
	bool Enable, ECollision_Interaction BaseIteraction)
{
	CollisionProfile* Profile = FindProfile(Name);

	if (Profile)
		return false;

	Profile = new CollisionProfile;

	Profile->Name = Name;
	Profile->Channel = Channel;
	Profile->Enable = Enable;
	Profile->vecCollisionInteraction.resize((size_t)ECollision_Channel::Max);

	for (int i = 0; i < (int)ECollision_Channel::Max; ++i)
	{
		Profile->vecCollisionInteraction[i] = BaseIteraction;
	}

	m_mapProfile.insert(std::make_pair(Name, Profile));

	return true;
}

bool CCollisionManager::SetCollisionInteraction(const std::string& Name, ECollision_Channel Channel,
	ECollision_Interaction Iteraction)
{
	CollisionProfile* Profile = FindProfile(Name);

	if (!Profile)
		return false;

	Profile->vecCollisionInteraction[(int)Channel] = Iteraction;

	return true;
}

CollisionProfile* CCollisionManager::FindProfile(const std::string& Name)
{
	auto	iter = m_mapProfile.find(Name);

	if (iter == m_mapProfile.end())
		return nullptr;

	return iter->second;
}

bool CCollisionManager::CollisionBoxToBox(Vector2& HitPoint, CColliderBox* Src,
	CColliderBox* Dest)
{
	if (CollisionBoxToBox(HitPoint, Src->GetInfo(), Dest->GetInfo()))
	{
		Dest->m_HitPoint = HitPoint;
		return true;
	}

	return false;
}

bool CCollisionManager::CollisionCircleToCircle(Vector2& HitPoint, CColliderCircle* Src, 
	CColliderCircle* Dest)
{
	if (CollisionCircleToCircle(HitPoint, Src->GetInfo(), Dest->GetInfo()))
	{
		Dest->m_HitPoint = HitPoint;
		return true;
	}

	return false;
}

bool CCollisionManager::CollisionBoxToCircle(Vector2& HitPoint, CColliderBox* Src, CColliderCircle* Dest)
{
	if (CollisionBoxToCircle(HitPoint, Src->GetInfo(), Dest->GetInfo()))
	{
		Dest->m_HitPoint = HitPoint;
		return true;
	}

	return false;
}

bool CCollisionManager::CollisionPointToBox(Vector2& HitPoint, const Vector2& Src,
	CColliderBox* Dest)
{
	if (CollisionPointToBox(HitPoint, Src, Dest->GetInfo()))
	{
		Dest->m_HitPoint = HitPoint;
		return true;
	}

	return false;
}

bool CCollisionManager::CollisionPointToCircle(Vector2& HitPoint, 
	const Vector2& Src, CColliderCircle* Dest)
{
	if (CollisionPointToCircle(HitPoint, Src, Dest->GetInfo()))
	{
		Dest->m_HitPoint = HitPoint;
		return true;
	}

	return false;
}

bool CCollisionManager::CollisionBoxToBox(Vector2& HitPoint, const BoxInfo& Src, 
	const BoxInfo& Dest)
{
	if (Src.LT.x > Dest.RB.x)
		return false;

	else if (Src.LT.y > Dest.RB.y)
		return false;

	else if (Src.RB.x < Dest.LT.x)
		return false;

	else if (Src.RB.y < Dest.LT.y)
		return false;

	float Left = Src.LT.x > Dest.LT.x ? Src.LT.x : Dest.LT.x;
	float Top = Src.LT.y > Dest.LT.y ? Src.LT.y : Dest.LT.y;
	float Right = Src.RB.x < Dest.RB.x ? Src.RB.x : Dest.RB.x;
	float Bottom = Src.RB.y < Dest.RB.y ? Src.RB.y : Dest.RB.y;

	HitPoint.x = (Left + Right) / 2.f;
	HitPoint.y = (Top + Bottom) / 2.f;

	return true;
}

bool CCollisionManager::CollisionCircleToCircle(Vector2& HitPoint, const CircleInfo& Src, 
	const CircleInfo& Dest)
{
	// 센터 사이의 거리를 구한다.
	float Dist = Src.Center.Distance(Dest.Center);

	bool result = Dist <= Src.Radius + Dest.Radius;

	HitPoint = (Src.Center + Dest.Center) / 2.f;

	return result;
}

bool CCollisionManager::CollisionBoxToCircle(Vector2& HitPoint, const BoxInfo& Src, 
	const CircleInfo& Dest)
{
	// 원의 중점이 사각형의 좌, 우 영역 혹은 위, 아래 영역에 존재하는지 판단한다.
	if ((Src.LT.x <= Dest.Center.x && Dest.Center.x <= Src.RB.x) ||
		(Src.LT.y <= Dest.Center.y && Dest.Center.y <= Src.RB.y))
	{
		// 사각형을 원의 반지름만큼 확장한다.
		BoxInfo	RC = Src;
		RC.LT.x -= Dest.Radius;
		RC.LT.y -= Dest.Radius;
		RC.RB.x += Dest.Radius;
		RC.RB.y += Dest.Radius;

		// 확장된 사각형 안에 원의 중점이 들어온다면 충돌된 것이다.
		if (RC.LT.x > Dest.Center.x)
			return false;

		else if (RC.LT.y > Dest.Center.y)
			return false;

		else if (RC.RB.x < Dest.Center.x)
			return false;

		else if (RC.RB.y < Dest.Center.y)
			return false;

		// 히트포인트.
		BoxInfo	CircleBox;
		CircleBox.LT = Dest.Center - Dest.Radius;
		CircleBox.RB = Dest.Center + Dest.Radius;

		float Left = Src.LT.x > CircleBox.LT.x ? Src.LT.x : CircleBox.LT.x;
		float Top = Src.LT.y > CircleBox.LT.y ? Src.LT.y : CircleBox.LT.y;
		float Right = Src.RB.x < CircleBox.RB.x ? Src.RB.x : CircleBox.RB.x;
		float Bottom = Src.RB.y < CircleBox.RB.y ? Src.RB.y : CircleBox.RB.y;

		HitPoint.x = (Left + Right) / 2.f;
		HitPoint.y = (Top + Bottom) / 2.f;

		return true;
	}

	Vector2	Pos[4] =
	{
		Src.LT,
		Vector2(Src.RB.x, Src.LT.y),
		Vector2(Src.LT.x, Src.RB.y),
		Src.RB
	};

	// 4개의 점중 하나라도 원 안에 들어온다면 충돌한 것이다.
	for (int i = 0; i < 4; ++i)
	{
		float Dist = Dest.Center.Distance(Pos[i]);

		if (Dist <= Dest.Radius)
		{
			BoxInfo	CircleBox;
			CircleBox.LT = Dest.Center - Dest.Radius;
			CircleBox.RB = Dest.Center + Dest.Radius;

			float Left = Src.LT.x > CircleBox.LT.x ? Src.LT.x : CircleBox.LT.x;
			float Top = Src.LT.y > CircleBox.LT.y ? Src.LT.y : CircleBox.LT.y;
			float Right = Src.RB.x < CircleBox.RB.x ? Src.RB.x : CircleBox.RB.x;
			float Bottom = Src.RB.y < CircleBox.RB.y ? Src.RB.y : CircleBox.RB.y;

			HitPoint.x = (Left + Right) / 2.f;
			HitPoint.y = (Top + Bottom) / 2.f;

			return true;
		}
	}

	return false;
}

bool CCollisionManager::CollisionPointToBox(Vector2& HitPoint, const Vector2& Src,
	const BoxInfo& Dest)
{
	if (Dest.LT.x > Src.x)
		return false;

	else if (Dest.LT.y > Src.y)
		return false;

	else if (Dest.RB.x < Src.x)
		return false;

	else if (Dest.RB.y < Src.y)
		return false;

	HitPoint = Src;

	return true;
}

bool CCollisionManager::CollisionPointToCircle(Vector2& HitPoint,
	const Vector2& Src, const CircleInfo& Dest)
{
	float Dist = Dest.Center.Distance(Src);

	if (Dist <= Dest.Radius)
	{
		HitPoint = Src;

		return true;
	}

	return false;
}
