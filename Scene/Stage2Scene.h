#pragma once
#include "Scene.h"

class CStage2Scene :
    public CScene
{
	friend class CSceneManager;

protected:
	CStage2Scene();
	virtual ~CStage2Scene();

public:
	bool Init();
};

