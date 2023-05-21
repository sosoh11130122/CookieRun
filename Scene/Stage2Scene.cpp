#include "Stage2Scene.h"
#include "../GameObject/Player.h"
#include "../GameObject/Monster.h"
#include "../GameObject/BackObj.h"
#include "SceneResource.h"
#include "Camera.h"
#include "../Input.h"
#include "../Widget/CharacterHUD.h"
#include "../GameObject/TileMap.h"
#include "../GameObject/Obstacle.h"
#include "../GameObject/ObstacleC.h"
#include "../GameObject/ObstacleE.h"
#include "../GameObject/Jelly.h"
#include "../Widget/Number.h"
#include "../Widget/WidgetWindow.h"
#include "../Widget/Widget.h"
#include "../Widget/WidgetComponent.h"
#include "../Widget/ImageWidget.h"
#include "../GameObject/BlackWindow.h"

CStage2Scene::CStage2Scene()
{
}

CStage2Scene::~CStage2Scene()
{
}

bool CStage2Scene::Init()
{
	GetCamera()->SetResolution(800.f, 485.f);
	GetCamera()->SetWorldResolution(5120.f, 520.f);
	GetCamera()->SetTargetPivot(0.4f, 0.5f);

	CreateObject<CBackObj>("BackObj");

	CTileMap* TileMap = CreateObject<CTileMap>("TileMap");

	TileMap->LoadFileName("stage1.tmp", MAP_PATH);

	CPlayer* Player = CreateObject<CPlayer>("Player");

	SetPlayer(Player);

	GetCamera()->SetTarget(Player);

	//FindWidget<CCharacterHUD>("CharacterHUD");

	return true;
}
