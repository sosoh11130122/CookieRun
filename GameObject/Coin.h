#pragma once
#include "GameObject.h"

class CCoin :
    public CGameObject
{
	friend class CScene;

protected:
	CCoin();
	virtual ~CCoin();

private:
	int m_Point;
	int m_Coin;

public:
	void SetPoint(int Point)
	{
		m_Point = Point;
	}

	void SetCount(int Coin)
	{
		m_Coin = Coin;
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

