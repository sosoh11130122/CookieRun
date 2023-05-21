#include "EndScene.h"
#include "SceneResource.h"
#include "Camera.h"
#include "../Input.h"
#include "../Widget/EndWindow.h"
#include "../GameManager.h"

CEndScene::CEndScene()
{
}

CEndScene::~CEndScene()
{
}

bool CEndScene::Init()
{
	CGameManager::GetInst()->GetScore();

	GetCamera()->SetResolution(800.f, 420.f);
	GetCamera()->SetWorldResolution(800.f, 420.f);
	GetCamera()->SetTargetPivot(0.5f, 0.5f);

	CreateWidgetWindow<CEndWindow>("EndWindow");

	return true;
}

