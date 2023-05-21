#pragma once
#include "GameObject.h"

class CBlackWindow :
    public CGameObject
{
	friend class CScene;

protected:
	CBlackWindow();
	~CBlackWindow();

private:
	float	m_Damage;
	CColliderBox* m_ColliderBox;

public:
	void SetDamage(float Damage)
	{
		m_Damage = Damage;
	}

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Render(HDC hDC, float DeltaTime);

private:
	void CollisionBegin(CCollider* Src, CCollider* Dest);
	void CollisionEnd(CCollider* Src, CCollider* Dest);
};

