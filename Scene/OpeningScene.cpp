#include "OpeningScene.h"
#include "SceneResource.h"
#include "Camera.h"
#include "../Input.h"
#include "../Widget/OpeningWindow.h"

COpeningScene::COpeningScene()
{
}

COpeningScene::~COpeningScene()
{
}

bool COpeningScene::Init()
{
	GetCamera()->SetResolution(800.f, 480.f);
	GetCamera()->SetWorldResolution(800.f, 480.f);
	GetCamera()->SetTargetPivot(0.5f, 0.5f);

	CreateWidgetWindow<COpeningWindow>("OpeningWindow");

	return true;
}

