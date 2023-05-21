
#include "MainScene.h"
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
#include "../GameObject/Heart.h"
#include "../GameObject/SizeUp.h"
#include "../GameObject/Dash.h"
#include "../GameObject/EndFlag.h"
#include "../GameObject/Coin.h"
#include "../GameObject/Magnet.h"

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{
	CreateAnimationSequence();

	GetSceneResource()->LoadSound("BGM", "MainBGM", true, "map.mp3");
	GetSceneResource()->SoundPlay("MainBGM");

	GetSceneResource()->SetVolume(50);

	GetCamera()->SetResolution(800.f, 485.f);
	GetCamera()->SetWorldResolution(15000.f, 520.f);
	GetCamera()->SetTargetPivot(0.3f, 0.5f);

	CreateObject<CBackObj>("BackObj");

	CTileMap* TileMap = CreateObject<CTileMap>("TileMap");

	TileMap->LoadFileName("map.tmp", MAP_PATH);



	//=======================================================================================
	//=======================================================================================
	//=======================================================================================


	CInput::GetInst()->AddBindFunction<CMainScene>("Cam1",
		Input_Type::Down, this, &CMainScene::Cam1Key, this);
	CInput::GetInst()->AddBindFunction<CMainScene>("Cam2",
		Input_Type::Down, this, &CMainScene::Cam2Key, this);

	//====================================================================================
	//====================================================================================
	//====================================================================================

	// ==================== 몬스터 대신 obstacle 생성하기
	//m_Monster = CreateObject<CMonster>("Monster");
	// ================================================= 오브젝트
	CObstacleC* ObstacleC = CreateObject<CObstacleC>("ObstacleC");

	ObstacleC->SetPos(890.f, 373.f);
	ObstacleC->SetSize(110.f, 180.f);
	ObstacleC->SetPivot(0.5f, 0.5f);

	ObstacleC->SetTexture("C", TEXT("Obstacle/C.bmp"), TEXTURE_PATH);
	ObstacleC->SetColorKey(35, 31, 32);

	ObstacleC = CreateObject<CObstacleC>("ObstacleC");

	ObstacleC->SetPos(2065.f, 420.f);
	ObstacleC->SetSize(110.f, 180.f);
	ObstacleC->SetPivot(0.5f, 0.5f);

	ObstacleC->SetTexture("C", TEXT("Obstacle/C.bmp"), TEXTURE_PATH);
	ObstacleC->SetColorKey(35, 31, 32);
	
	ObstacleC = CreateObject<CObstacleC>("ObstacleC");

	ObstacleC->SetPos(3720.f, 320.f);
	ObstacleC->SetSize(110.f, 180.f);
	ObstacleC->SetPivot(0.5f, 0.5f);

	ObstacleC->SetTexture("C", TEXT("Obstacle/C.bmp"), TEXTURE_PATH);
	ObstacleC->SetColorKey(35, 31, 32);

	//===================================================================
	//===================================================================
	//===================================================================

	CObstacle* Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(1657.f, 263.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("A", TEXT("Obstacle/A.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleB");

	Obstacle->SetPos(1777.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("B", TEXT("Obstacle/B.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(2266.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("A", TEXT("Obstacle/A.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleB");

	Obstacle->SetPos(2331.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("B", TEXT("Obstacle/B.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(4571.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("A", TEXT("Obstacle/A.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleB");

	Obstacle->SetPos(4636.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("B", TEXT("Obstacle/B.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(8352.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("7070", TEXT("Obstacle/7070.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleB");

	Obstacle->SetPos(8707.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("ab", TEXT("Obstacle/ab.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(8772.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("70702", TEXT("Obstacle/70702.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleB");

	Obstacle->SetPos(8837.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("7070", TEXT("Obstacle/7070.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(10395.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("70702", TEXT("Obstacle/70702.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleB");

	Obstacle->SetPos(10570.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("ab", TEXT("Obstacle/ab.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(10765.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("7070", TEXT("Obstacle/7070.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleB");

	Obstacle->SetPos(10830.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("ab", TEXT("Obstacle/ab.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	Obstacle = CreateObject<CObstacle>("ObstacleA");

	Obstacle->SetPos(11090.f, 373.f);
	Obstacle->SetSize(65.f, 75.f);
	Obstacle->SetPivot(0.5f, 0.5f);

	Obstacle->SetTexture("70702", TEXT("Obstacle/70702.bmp"), TEXTURE_PATH);
	Obstacle->SetColorKey(35, 31, 32);

	//===================================================================
	//===================================================================
	//===================================================================

	CObstacleE* ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(1120.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);

	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(1235.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);

	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(5265.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);

	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(5370.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);


	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(5475.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32); 


	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(5580.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);


	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(5685.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);


	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(5790.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("E", TEXT("Obstacle/E.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);


	ObstacleE = CreateObject<CObstacleE>("ObstacleE");

	ObstacleE->SetPos(9794.f, 150.f);
	ObstacleE->SetSize(115.f, 340.f);
	ObstacleE->SetPivot(0.5f, 0.5f);

	ObstacleE->SetTexture("ee", TEXT("Obstacle/ee.bmp"), TEXTURE_PATH);
	ObstacleE->SetColorKey(35, 31, 32);


	//============================================================================
	//============================================================================
	//============================================================================
	//=============================================== 젤리

	CJelly* Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(423.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(459.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(495.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(531.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(567.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(603.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(639.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(675.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(711.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(747.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(783.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	CCoin* Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(783.f, 297.f);
	Coin->SetSize(80.f, 80.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("SilverCoin", TEXT("silvercoin.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(820.f, 297.f);
	Coin->SetSize(80.f, 80.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("SilverCoin", TEXT("silvercoin.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(856.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(892.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(892.f, 237.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(928.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(964.f, 297.f);
	Coin->SetSize(80.f, 80.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("GoldCoin", TEXT("goldcoin.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(1000.f, 297.f);
	Coin->SetSize(80.f, 80.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("GoldCoin", TEXT("goldcoin.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1000.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1036.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1036.f, 327.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1036.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1072.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1108.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1144.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1180.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1216.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1252.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1288.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1385.f, 250.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1421.f, 250.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	//Jelly = CreateObject<CJelly>("JellyBean");

	//Jelly->SetPos(1600.f, 220.f);
	//Jelly->SetSize(36.f, 30.f);
	//Jelly->SetPivot(0.5f, 0.5f);

	//Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	//Jelly->SetColorKey(35, 31, 32);

	//Jelly = CreateObject<CJelly>("JellyBean");

	//Jelly->SetPos(1636.f, 190.f);
	//Jelly->SetSize(36.f, 30.f);
	//Jelly->SetPivot(0.5f, 0.5f);

	//Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	//Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1672.f, 190.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1708.f, 220.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1744.f, 250.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1780.f, 280.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1816.f, 310.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1852.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1888.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1924.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(1960.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2030.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2066.f, 270.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2102.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2154.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2190.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2226.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2262.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2298.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2298.f, 237.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2334.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2334.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2370.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2406.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2442.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2442.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2478.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2590.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2590.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2590.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2590.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2626.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2626.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2626.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2626.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2662.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2662.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2662.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2662.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2698.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2698.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2698.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2698.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2734.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2734.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2734.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2734.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2770.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2770.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2770.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2770.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2806.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2806.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2806.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2806.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2842.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2842.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2842.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2842.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2878.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2878.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2878.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2878.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2914.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2914.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2914.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(2914.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3000.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3000.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3000.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3000.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3036.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3036.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3036.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3036.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3072.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3072.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3072.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3072.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3108.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3108.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3108.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3108.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3144.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3144.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3144.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3144.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3180.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3180.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3180.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3180.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3216.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3216.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3216.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3216.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3252.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3252.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3252.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3252.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3288.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3288.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3288.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3288.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3324.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3324.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3324.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3324.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3403.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3439.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3475.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3511.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3547.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3583.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3620.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3620.f, 270.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3656.f, 230.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3690.f, 200.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3720.f, 200.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3720.f, 170.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3756.f, 200.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3792.f, 230.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3828.f, 270.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3828.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3868.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(3904.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	//Jelly = CreateObject<CJelly>("JellyBean");

	//Jelly->SetPos(4008.f, 267.f);
	//Jelly->SetSize(36.f, 30.f);
	//Jelly->SetPivot(0.5f, 0.5f);

	//Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	//Jelly->SetColorKey(35, 31, 32);

	//Jelly = CreateObject<CJelly>("JellyBean");

	//Jelly->SetPos(4044.f, 267.f);
	//Jelly->SetSize(36.f, 30.f);
	//Jelly->SetPivot(0.5f, 0.5f);

	//Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	//Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4200.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4236.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4348.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4384.f, 323.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4420.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4456.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4492.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4528.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4567.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4600.f, 237.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4636.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4672.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4708.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4744.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4780.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4816.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4852.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4888.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4934.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4934.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4970.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(4970.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5006.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5006.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5042.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5042.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5078.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5078.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5114.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5114.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5150.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5150.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5186.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5186.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5227.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5263.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5299.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5335.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5371.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5407.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5443.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5479.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5515.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5551.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5587.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5623.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5659.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5695.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5731.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5767.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5803.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5839.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5896.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5932.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5932.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5968.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(5968.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6004.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6004.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6040.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6040.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6076.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6076.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6112.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6160.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6196.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6232.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6268.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6304.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6340.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6376.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6412.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6448.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6484.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6520.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6556.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6592.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6628.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6664.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6700.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6736.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6772.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6808.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6844, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6880.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6916.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6952.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(6988.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(7024.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	//=======================================================================================================
	//=======================================================================================================
	//=======================================================================================================

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8100.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8136.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8172.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8208.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8244.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8280, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8316.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8352.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8388.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8424.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8460.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8496.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8532.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8568.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8604.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8640.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8676.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8712.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8712.f, 237.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8748.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8748.f, 237.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8748.f, 207.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8784.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8784.f, 237.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8784.f, 207.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8820.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8820.f, 237.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8856.f, 267.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8892.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8928.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(8964.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9000.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9036.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9072.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9108.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9144.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9180.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9216.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9252.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9288.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9650.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9686.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9722.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9758.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9794.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9830.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9866.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9902.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9938.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(9974.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10010.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10046.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10082.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10118.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10154.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10190.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10226.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10262.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10298.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(10330.f, 140.f);
	Coin->SetSize(140.f, 140.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("GoldCoinBig", TEXT("goldcoinbig.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10334.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(10430.f, 70.f);
	Coin->SetSize(140.f, 141.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("SilverCoinBig", TEXT("silvercoinbig.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10442.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10478.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10514, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(10530.f, 140.f);
	Coin->SetSize(140.f, 140.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("GoldCoinBig", TEXT("goldcoinbig.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10622.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(10630.f, 70.f);
	Coin->SetSize(140.f, 141.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("SilverCoinBig", TEXT("silvercoinbig.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10658.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10694.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(10730.f, 140.f);
	Coin->SetSize(140.f, 140.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("GoldCoinBig", TEXT("goldcoinbig.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Coin = CreateObject<CCoin>("Coin");

	Coin->SetPos(10830.f, 70.f);
	Coin->SetSize(140.f, 141.f);
	Coin->SetPivot(0.5f, 0.5f);

	Coin->SetTexture("SilverCoinBig", TEXT("silvercoinbig.bmp"), TEXTURE_PATH);
	Coin->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10930.f, 70.f);
	Jelly->SetSize(135.f, 153.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star1", TEXT("star1.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10910.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10946.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(10982.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11018.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11030.f, 140.f);
	Jelly->SetSize(138.f, 151.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star2", TEXT("star2.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11130.f, 70.f);
	Jelly->SetSize(135.f, 153.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star1", TEXT("star1.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11162.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11198.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11230.f, 140.f);
	Jelly->SetSize(138.f, 151.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star2", TEXT("star2.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11234.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11270.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11309.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11330.f, 70.f);
	Jelly->SetSize(135.f, 153.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star1", TEXT("star1.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11345.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11417.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11430.f, 140.f);
	Jelly->SetSize(138.f, 151.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star2", TEXT("star2.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11453.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11489.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11525.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11530.f, 70.f);
	Jelly->SetSize(135.f, 153.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star1", TEXT("star1.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11561.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11597.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11630.f, 140.f);
	Jelly->SetSize(138.f, 151.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star2", TEXT("star2.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11633.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11669, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11705.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11730.f, 70.f);
	Jelly->SetSize(135.f, 153.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star1", TEXT("star1.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11741.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11777.f, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11813, 300.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11830.f, 140.f);
	Jelly->SetSize(138.f, 151.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star2", TEXT("star2.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11849.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11885.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11921.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11930.f, 70.f);
	Jelly->SetSize(135.f, 153.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star1", TEXT("star1.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11957.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(11993.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12029.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12030.f, 140.f);
	Jelly->SetSize(138.f, 151.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("star2", TEXT("star2.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(0, 0, 0);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12065.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12101.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12137.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12173.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12209.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12245.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12281.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12317.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12353.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12389.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12425.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12461.f, 357.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12497.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12533.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12569.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12605.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(12641.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);


	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13120.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13120.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13120.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13120.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13120.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13156.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13156.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13156.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13192.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13192.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13192.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13228.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13228.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13228.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13264.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13264.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13264.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);




	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13336.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13336.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13336.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13336.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13336.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13372.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13408.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13444.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13480.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13480.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13480.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13480.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13480.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);



	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13552.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13552.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13552.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13552.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13552.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13588.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13588.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13624.f, 367.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13624.f, 247.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13660.f, 337.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13660.f, 277.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	Jelly = CreateObject<CJelly>("JellyBean");

	Jelly->SetPos(13696.f, 307.f);
	Jelly->SetSize(36.f, 30.f);
	Jelly->SetPivot(0.5f, 0.5f);

	Jelly->SetTexture("a", TEXT("jellybean.bmp"), TEXTURE_PATH);
	Jelly->SetColorKey(35, 31, 32);

	//=======================================================================================================
	//=======================================================================================================
	//=======================================================================================================

	CBlackWindow* BlackWindow = CreateObject<CBlackWindow>("BlackWindow");

	BlackWindow->SetTexture("BlackWindow", TEXT("blackwindow.bmp"), TEXTURE_PATH);
	BlackWindow->SetSize(800.f, 520.f);
	BlackWindow->SetPos(7180.f, 0.f);
	BlackWindow->SetPivot(0.f, 0.f);



	//=======================================================================================
	//=======================================================================================
	//=======================================================================================아이템

	CHeart* Heart = CreateObject<CHeart>("Heart");
	//Heart->SetPos(3995.f, 210.f);

	//Heart = CreateObject<CHeart>("Heart");
	Heart->SetPos(9370.f, 210.f);

	Heart = CreateObject<CHeart>("Heart");
	Heart->SetPos(9500.f, 210.f);

	CDash* Dash = CreateObject<CDash>("Dash");
	Dash->SetPos(1560.f, 210.f);

	//Dash = CreateObject<CDash>("Dash");
	//Dash->SetPos(4230.f, 210.f);

	CMagnet* Magnet = CreateObject<CMagnet>("Magnet");
	Magnet->SetPos(10170.f, 210.f);


	//=======================================================================================
	//=======================================================================================
	//=======================================================================================
	
	CPlayer* Player = CreateObject<CPlayer>("Player");
	
	SetPlayer(Player);
	
	GetCamera()->SetTarget(Player);



	//=======================================================================================
	//=======================================================================================
	//=======================================================================================


	CreateWidgetWindow<CCharacterHUD>("CharacterHUD");


	//=======================================================================================
	//=======================================================================================
	//=======================================================================================

	return true;
}


void CMainScene::CreateAnimationSequence()
{
	GetSceneResource()->CreateAnimationSequence("PlayerIdle", "PlayerIdle", TEXT("Player/Run/idle.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerIdle", 240.f * i, 0.f, 240.f, 240.f);
	}

	GetSceneResource()->SetColorKey("PlayerIdle", 35, 31, 32);

	GetSceneResource()->CreateAnimationSequence("PlayerJump",
		"PlayerJump", TEXT("Player/Jump/jump1.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 2; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerJump", 240.f * i, 0.f,
			240.f, 240.f);
	}

	GetSceneResource()->SetColorKey("PlayerJump", 35, 31, 32);

	GetSceneResource()->CreateAnimationSequence("PlayerSlide",
		"PlayerSlide", TEXT("Player/Slide/slide.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 2; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerSlide", 240.f * i, 0.f,
			240.f, 240.f);
	}

	GetSceneResource()->SetColorKey("PlayerSlide", 35, 31, 32);

	GetSceneResource()->CreateAnimationSequence("PlayerJump2",
		"PlayerJump2", TEXT("Player/Jump/jump2.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 7; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerJump2", 240.f * i, 0.f,
			240.f, 240.f);
	}

	GetSceneResource()->SetColorKey("PlayerJump2", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("PlayerCollision",
		"PlayerCollision", TEXT("Player/Collision/collision.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 2; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerCollision", 240.f * i, 0.f,
			240.f, 240.f);
	}

	GetSceneResource()->SetColorKey("PlayerCollision", 4, 7, 7);

	GetSceneResource()->CreateAnimationSequence("PlayerDash",
		"PlayerDash", TEXT("Player/Dash/dash.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerDash", 240.f * i, 0.f,
			240.f, 240.f);
	}

	GetSceneResource()->SetColorKey("PlayerDash", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("PlayerDead",
		"PlayerDead", TEXT("Player/Dead/dead.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 5; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PlayerDead", 240.f * i, 0.f,
			240.f, 240.f);
	}

	GetSceneResource()->SetColorKey("PlayerDead", 4, 7, 7);


	GetSceneResource()->CreateAnimationSequence("FlagOn",
		"FlagOn", TEXT("flag.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 8; ++i)
	{
		GetSceneResource()->AddAnimationFrame("FlagOn", 259.875f * i, 0.f,
			259.875f, 300.f);
	}

	GetSceneResource()->SetColorKey("FlagOn", 4, 7, 7);

	GetSceneResource()->CreateAnimationSequence("Heart",
		"Heart", TEXT("heart.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 5; ++i)
	{
		GetSceneResource()->AddAnimationFrame("Heart", 65.6f * i, 0.f,
			65.6f, 76.f);
	}

	GetSceneResource()->SetColorKey("Heart", 4, 7, 7);

	GetSceneResource()->CreateAnimationSequence("PetIdle",
		"PetIdle", TEXT("pet.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PetIdle", 80.f * i, 0.f,
			80.f, 80.f);
	}

	GetSceneResource()->SetColorKey("PetIdle", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("PetMagnet",
		"PetMagnet", TEXT("petmagnet.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("PetMagnet", 80.f * i, 0.f,
			80.f, 80.f);
	}

	GetSceneResource()->SetColorKey("PetMagnet", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("Magnet",
		"Magnet", TEXT("magnet.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("Magnet", 76.f * i, 0.f,
			76.f, 76.f);
	}

	GetSceneResource()->SetColorKey("Magnet", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("DashItem",
		"DashItem", TEXT("dashitemimage.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("DashItem", 76.f * i, 0.f,
			76.f, 76.f);
	}

	GetSceneResource()->SetColorKey("DashItem", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("SizeUpItem",
		"SizeUpItem", TEXT("sizeupitem.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("SizeUpItem", 75.75f * i, 0.f,
			75.75f, 76.f);
	}

	GetSceneResource()->SetColorKey("SizeUpItem", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("SizeUpIdle",
		"SizeUpIdle", TEXT("Player/Run/sizeuprun.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 4; ++i)
	{
		GetSceneResource()->AddAnimationFrame("SizeUpIdle", 360.f * i, 0.f,
			360.f, 360.f);
	}

	GetSceneResource()->SetColorKey("SizeUpIdle", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("SizeUpJump",
		"SizeUpJump", TEXT("Player/Jump/sizeupjump.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 2; ++i)
	{
		GetSceneResource()->AddAnimationFrame("SizeUpJump", 360.f * i, 0.f,
			360.f, 360.f);
	}

	GetSceneResource()->SetColorKey("SizeUpJump", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("SizeUpJump2",
		"SizeUpJump2", TEXT("Player/Jump/sizeupjump2.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 7; ++i)
	{
		GetSceneResource()->AddAnimationFrame("SizeUpJump2", 360.f * i, 0.f,
			360.f, 360.f);
	}

	GetSceneResource()->SetColorKey("SizeUpJump2", 34, 30, 31);

	GetSceneResource()->CreateAnimationSequence("SizeUpSlide",
		"SizeUpSlide", TEXT("Player/Slide/sizeupslide.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 2; ++i)
	{
		GetSceneResource()->AddAnimationFrame("SizeUpSlide", 360.f * i, 0.f,
			360.f, 360.f);
	}

	GetSceneResource()->SetColorKey("SizeUpSlide", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("SizeUpDead",
		"SizeUpDead", TEXT("Player/Dead/sizeupdead.bmp"), TEXTURE_PATH);

	for (int i = 0; i < 5; ++i)
	{
		GetSceneResource()->AddAnimationFrame("SizeUpDead", 360.f * i, 0.f,
			360.f, 360.f);
	}

	GetSceneResource()->SetColorKey("SizeUpDead", 0, 0, 0);

}

void CMainScene::Cam1Key()
{
	GetCamera()->SetTarget(m_Player);
}

void CMainScene::Cam2Key()
{
	
}
