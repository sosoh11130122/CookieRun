#include "EndWindow.h"
#include "Button.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneResource.h"
#include "../GameManager.h"
#include "../Scene/MainScene.h"
#include "../Scene/EditScene.h"
#include "../Scene/SceneManager.h"
#include "../Input.h"
#include "ImageWidget.h"
#include "Text.h"
#include "Number.h"
#include "CharacterHUD.h"
#include "../Scene/StartScene.h"


CEndWindow::CEndWindow() :
	m_DelayTime(0.f)
{
}

CEndWindow::~CEndWindow()
{
}

bool CEndWindow::Init()
{
	CGameManager::GetInst()->GetScore();
	CGameManager::GetInst()->GetCoinScore();

	if (!CWidgetWindow::Init())
		return false;

	m_Scene->GetSceneResource()->LoadSound("BGM", "Result", false, "result.mp3");
	m_Scene->GetSceneResource()->SoundPlay("Result");
	m_Scene->GetSceneResource()->SetVolume(50);

	m_Scene->GetSceneResource()->LoadSound("UI", "ButtonHovered", false, "UIButton.mp3");
	m_Scene->GetSceneResource()->LoadSound("UI", "ButtonClick", false, "UIEquipmentButton.mp3");


	SetSize(800.f, 480.f);

	CImageWidget* EndBack = CreateWidget<CImageWidget>("EndBack");

	EndBack->SetTexture("EndBack", TEXT("endscene.bmp"));

	EndBack->SetSize(800.f, 480.f);

	EndBack->SetZOrder(0);

	{
		CImageWidget* Score = CreateWidget<CImageWidget>("Score");

		Score->SetTexture("Score", TEXT("score.bmp"));
		Score->SetPos(132.5f, 141.f);
		Score->SetSize(535.f, 111.f);

	}

	{
		CNumber* ScorePoint = CreateWidget<CNumber>("Point");

		ScorePoint->SetNumber(CGameManager::GetInst()->GetScore());

		std::vector<std::wstring>	vecFileName;

		for (int i = 0; i <= 9; ++i)
		{
			TCHAR	FileName[MAX_PATH] = {};
			wsprintf(FileName, TEXT("Number/%d.bmp"), i);
			vecFileName.push_back(FileName);
		}

		ScorePoint->SetTexture("Number", vecFileName);
		ScorePoint->SetSize(15.f, 28.f);
		ScorePoint->SetPos(355.f, 180.f);
		ScorePoint->SetColorKey(4, 7, 7);

	}

	{
		CImageWidget* Score = CreateWidget<CImageWidget>("CoinScore");

		Score->SetTexture("CoinScore", TEXT("coinscore.bmp"));
		Score->SetPos(132.5f, 272.f);
		Score->SetSize(534.f, 111.f);

	}

	{
		m_CoinScore = CreateWidget<CNumber>("Coin");

		m_CoinScore->SetNumber(CGameManager::GetInst()->GetCoinScore());

		std::vector<std::wstring>	vecFileName;

		for (int i = 0; i <= 9; ++i)
		{
			TCHAR	FileName[MAX_PATH] = {};
			wsprintf(FileName, TEXT("Number/%d.bmp"), i);
			vecFileName.push_back(FileName);
		}

		m_CoinScore->SetTexture("Number", vecFileName);
		m_CoinScore->SetSize(15.f, 28.f);
		m_CoinScore->SetPos(390.f, 311.f);
		m_CoinScore->SetColorKey(4, 7, 7);
	}

	CButton* OKButton = CreateWidget<CButton>("OKButton");
			
	OKButton->SetTexture("OKButton", TEXT("okbutton.bmp"));
	OKButton->SetButtonStateData(EButton_State::Normal, Vector2(0.f, 0.f), Vector2(196.f, 76.f));
	OKButton->SetButtonStateData(EButton_State::MouseHovered, Vector2(0.f, 0.f), Vector2(196.f, 76.f));
	OKButton->SetButtonStateData(EButton_State::Click, Vector2(0.f, 0.f), Vector2(196.f, 76.f));
	OKButton->SetButtonStateData(EButton_State::Disable, Vector2(0.f, 0.f), Vector2(196.f, 76.f));

	OKButton->SetPos(300.5f, 380.f);
	OKButton->SetSize(196.f, 76.f);
	OKButton->SetColorKey(0, 0, 0);
	OKButton->SetZOrder(1);

	OKButton->SetCallback<CEndWindow>(EButton_Sound_State::Click,
		this, &CEndWindow::OKButtonCallback);

    return true;
}

void CEndWindow::Update(float DeltaTime)
{
	CWidgetWindow::Update(DeltaTime);


	//m_DelayTime += DeltaTime;

	//if (m_DelayTime >= 1.f)
	//{

	//	CButton* OKButton = CreateWidget<CButton>("OKButton");

	//	OKButton->SetTexture("OKButton", TEXT("okbutton.bmp"));
	//	OKButton->SetPos(300.5f, 373.f);
	//	OKButton->SetSize(196.f, 76.f);
	//	OKButton->SetColorKey(0, 0, 0);

	//	OKButton->SetCallback<CEndWindow>(EButton_Sound_State::Click,
	//		this, &CEndWindow::OKButtonCallback);
	//}

}

void CEndWindow::OKButtonCallback()
{
	CInput::GetInst()->ClearCallback();
	CSceneManager::GetInst()->CreateScene<CStartScene>();
}
