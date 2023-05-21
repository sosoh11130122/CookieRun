#pragma once
#include "GameObject.h"

class CDash :
    public CGameObject
{
	friend class CScene;

protected:
	CDash();
	virtual ~CDash();

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

