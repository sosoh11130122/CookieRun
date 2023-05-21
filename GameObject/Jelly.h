#pragma once
#include "GameObject.h"

class CJelly :
    public CGameObject
{
	friend class CScene;

protected:
	CJelly();
	virtual ~CJelly();

private:
	int m_Point;

public:
	void SetPoint(int Point)
	{
		m_Point = Point;
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

