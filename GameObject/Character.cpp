
#include "Character.h"

CCharacter::CCharacter()
{
	SetTypeID<CCharacter>();
}

CCharacter::CCharacter(const CCharacter& Obj) :
	CGameObject(Obj)
{
}

CCharacter::~CCharacter()
{
}

bool CCharacter::Init()
{
	return true;
}

void CCharacter::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CCharacter::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CCharacter::Render(HDC hDC, float DeltaTime)
{
	CGameObject::Render(hDC, DeltaTime);
}

float CCharacter::InflictDamage(float Damage)
{
	return CGameObject::InflictDamage(Damage);
}

int CCharacter::PlusPoint(int Point)
{
	return CGameObject::PlusPoint(Point);
}

int CCharacter::PlusCoin(int Coin)
{
	return CGameObject::PlusCoin(Coin);
}
