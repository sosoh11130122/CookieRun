#pragma once
#include "GameObject.h"

class CPet :
    public CGameObject
{
	friend class CScene;

protected:
	CPet();
	virtual ~CPet();

private:
	CColliderBox* m_ColliderBox;


public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void Render(HDC hDC, float DeltaTime);

private:
	void CollisionBegin(CCollider* Src, CCollider* Dest);
	void CollisionEnd(CCollider* Src, CCollider* Dest);
};

