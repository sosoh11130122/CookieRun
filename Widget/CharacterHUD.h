#pragma once
#include "WidgetWindow.h"

class CCharacterHUD :
    public CWidgetWindow
{
    friend class CScene;

protected:
    CCharacterHUD();
    virtual ~CCharacterHUD();

protected:
    CSharedPtr<class CProgressBar>  m_HPBar;
    CSharedPtr<class CImageWidget>  m_BonusTime;
    CSharedPtr<class CImageWidget>  m_HPBarFrame;
    CSharedPtr<class CImageWidget>  m_HeartImage;
    CSharedPtr<class CImageWidget>  m_CoinImage;
    CSharedPtr<class CImageWidget>  m_JellyImage;
    CSharedPtr<class CText>     m_FPSText;
    CSharedPtr<class CNumber>   m_Point;
    CSharedPtr<class CNumber>   m_Coin;
    CSharedPtr<class CImageWidget>	m_JumpButton;
    CSharedPtr<class CImageWidget>	m_SlideButton;
    CSharedPtr<class CImageWidget>	m_Back;

public:
    void SetHP(float HP);
    void SetPoint(int Point);
    void SetCoin(int Coin);

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);

public:
    void StopButtonCallback();
};

