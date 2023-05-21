#pragma once
#include "Scene.h"
class COpeningScene :
    public CScene
{
	friend class CSceneManager;

protected:
	COpeningScene();
	virtual ~COpeningScene();

public:
	bool Init();
};

