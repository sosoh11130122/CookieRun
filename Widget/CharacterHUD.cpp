
#include "CharacterHUD.h"
#include "Button.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"
#include "../GameManager.h"
#include "../Scene/MainScene.h"
#include "../Scene/SceneManager.h"
#include "../Input.h"
#include "ProgressBar.h"
#include "ImageWidget.h"
#include "Text.h"
#include "Number.h"

CCharacterHUD::CCharacterHUD()
{
}

CCharacterHUD::~CCharacterHUD()
{
}

void CCharacterHUD::SetHP(float HP)
{
	m_HPBar->SetValue(HP);
}

void CCharacterHUD::SetPoint(int Point)
{
	m_Point->SetNumber(Point);
}

void CCharacterHUD::SetCoin(int Coin)
{
	m_Coin->SetNumber(Coin);
}


bool CCharacterHUD::Init()
{
	if (!CWidgetWindow::Init())
		return false;

	//m_Point->SetTexture("Point", TEXT("BarBack.bmp"));
	//m_Point->SetColorKey(255, 0, 255);

	/*m_Scene->GetSceneResource()->LoadSound("UI", "ButtonHovered", false,
		"1Up.wav");
	m_Scene->GetSceneResource()->LoadSound("UI", "ButtonClick", false,
		"Stun.wav");*/

	
	SetSize(800.f, 480.f);

	m_Back = CreateWidget<CImageWidget>("Back");

	m_Back->SetTexture("Back", TEXT("widget1.bmp"), TEXTURE_PATH);
	m_Back->SetColorKey(0, 0, 0);
	m_Back->SetPos(0.f, -50.f);
	m_Back->SetSize(800.f, 520.f);
	m_Back->SetZOrder(0);


	m_BonusTime = CreateWidget<CImageWidget>("BonusTimeBack");

	m_BonusTime->SetTexture("BonusTimeBack", TEXT("bonustime.bmp"), TEXTURE_PATH);
	m_BonusTime->SetColorKey(0, 0, 0);
	m_BonusTime->SetPos(20.f, 20.f);
	m_BonusTime->SetSize(177.f, 27.f);
	m_BonusTime->SetZOrder(1);


	m_HPBarFrame = CreateWidget<CImageWidget>("HPBarFrame");

	m_HPBarFrame->SetTexture("HPBarFrame", TEXT("barframe.bmp"));
	m_HPBarFrame->SetColorKey(0, 0, 0);

	m_HPBarFrame->SetSize(420.f, 54.f);
	m_HPBarFrame->SetPos(230.f, 20.f);

	m_HPBar = CreateWidget<CProgressBar>("HPBar");

	m_HPBar->SetTexture(EProgressBar_Texture_Type::Bar, "HPBar", TEXT("hpbar.bmp"));
	m_HPBar->SetColorKey(EProgressBar_Texture_Type::Bar, 4, 7, 7);

	m_HPBar->SetSize(375.f, 34.f);
	m_HPBar->SetPos(274.f, 28.f);
	m_HPBar->SetBarDir(EProgressBar_Dir::LeftToRight);
	m_HPBar->SetZOrder(1);

	m_CoinImage = CreateWidget<CImageWidget>("CoinImage");

	m_CoinImage->SetTexture("CoinImage", TEXT("silver.bmp"), TEXTURE_PATH);
	m_CoinImage->SetColorKey(0, 0, 0);
	m_CoinImage->SetPos(17.f, 60.f);
	m_CoinImage->SetSize(40.f, 40.f);
	m_CoinImage->SetZOrder(1);

	m_JellyImage = CreateWidget<CImageWidget>("JellyImage");

	m_JellyImage->SetTexture("JellyImage", TEXT("jellyicon.bmp"), TEXTURE_PATH);
	m_JellyImage->SetColorKey(0, 0, 0);
	m_JellyImage->SetPos(655.f, 70.f);
	m_JellyImage->SetSize(20.f, 26.f);
	m_JellyImage->SetZOrder(1);

	//===================================================================

	m_JumpButton = CreateWidget<CImageWidget>("JumpButton");
	m_JumpButton->SetTexture("JumpButton", TEXT("jumpoff.bmp"), TEXTURE_PATH);
	m_JumpButton->SetColorKey(4, 7, 7);
	m_JumpButton->SetPos(20.f, 340.f);
	m_JumpButton->SetSize(152.f, 117.f);
	m_JumpButton->SetZOrder(1);

	m_SlideButton = CreateWidget<CImageWidget>("SlideButton");
	m_SlideButton->SetTexture("SlideButton", TEXT("slideoff.bmp"), TEXTURE_PATH);
	m_SlideButton->SetColorKey(4, 7, 7);
	m_SlideButton->SetPos(628.f, 340.f);
	m_SlideButton->SetSize(152.f, 117.f);
	m_SlideButton->SetZOrder(1);

	//===================================================================
	
	//CButton* StopButton = CreateWidget<CButton>("StopButton");

	//StopButton->SetTexture("StopButton", TEXT("stop.bmp"));
	//StopButton->SetSize(56.f, 56.f);
	//StopButton->SetPos(724.f, 60.f);
	//StopButton->SetColorKey(4, 7, 7);

	//StopButton->SetZOrder(1);

	//StopButton->SetCallback<CCharacterHUD>(EButton_Sound_State::Click,
	//	this, &CCharacterHUD::StopButtonCallback);

	//==================================================================
	// ¼ýÀÚ============================================================

	
	{
		m_Point = CreateWidget<CNumber>("Point");

		std::vector<std::wstring>	vecFileName;

		for (int i = 0; i <= 9; ++i)
		{
			TCHAR	FileName[MAX_PATH] = {};
			wsprintf(FileName, TEXT("Number/%d.bmp"), i);
			vecFileName.push_back(FileName);
		}

		m_Point->SetTexture("Number", vecFileName);
		m_Point->SetSize(15.f, 28.f);
		m_Point->SetPos(680.f, 70.f);
		m_Point->SetColorKey(4, 7, 7);
	}
	
	{
		m_Coin = CreateWidget<CNumber>("Coin");

		std::vector<std::wstring>	vecFileName;

		for (int i = 0; i <= 9; ++i)
		{
			TCHAR	FileName[MAX_PATH] = {};
			wsprintf(FileName, TEXT("Number/%d.bmp"), i);
			vecFileName.push_back(FileName);
		}

		m_Coin->SetTexture("Number", vecFileName);
		m_Coin->SetSize(15.f, 28.f);
		m_Coin->SetPos(60.f, 70.f);
		m_Coin->SetColorKey(4, 7, 7);

	}

	return true;
}

void CCharacterHUD::Update(float DeltaTime)
{
	CWidgetWindow::Update(DeltaTime);
}

void CCharacterHUD::StopButtonCallback()
{
}
