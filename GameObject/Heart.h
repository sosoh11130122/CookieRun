#pragma once
#include "GameObject.h"

class CHeart :
    public CGameObject
{
    friend class CScene;

protected:
	CHeart();
	virtual ~CHeart();

public:
	int	m_HP;

private:
	CColliderBox* m_ColliderBox;

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Render(HDC hDC, float DeltaTime);

private:
	void CollisionBegin(CCollider* Src, CCollider* Dest);
	void CollisionEnd(CCollider* Src, CCollider* Dest);
};

