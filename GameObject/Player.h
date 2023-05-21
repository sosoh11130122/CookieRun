#pragma once

#include "Character.h"

struct SkillCoolDownInfo
{
	float	CoolDown;
	bool	CoolDownEnable;
};

class CPlayer :
    public CCharacter
{
	friend class CScene;

protected:
	CPlayer();
	virtual ~CPlayer();

private:
	CSharedPtr<class CPet>	m_Pet;
	float	m_PetDistance;
	float	m_PetAngle;

	int		m_PlayerDir;
	std::vector<std::string>	m_vecSequenceKey[2];

	int		m_HP;
	int		m_HPMax;

	CSharedPtr<class CWidgetComponent>	m_HPBar;
	CSharedPtr<class CWidgetComponent>	m_NameBar;

	CColliderBox* m_ColliderBox;
	CColliderBox* m_MagnetCollider;
	
	CSharedPtr<class CImageWidget>	m_Button;

	float	m_MoveTime;
	bool	m_Slide;
	float	m_GamePlayTime;
	bool	m_Dead;
	bool	m_Collision;
	float	m_GameOverTime;
	bool	m_SizeUp;
	bool	m_Dash;
	float	m_ItemTime;
	bool	m_Magnet;


public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Render(HDC hDC, float DeltaTime);
	virtual float InflictDamage(float Damage);

private:
	void MoveFront();
	void JumpKey();
	void JumpKeyBack();
	void Slide();
	void SlideUp();
	void SizeUp();
	void Dash();

private:
	void CollisionBegin(CCollider* Src, CCollider* Dest);
	void CollisionEnd(CCollider* Src, CCollider* Dest);

private:
	void GameOver();
};

