#pragma once
#include "WidgetWindow.h"
#include "../Scene/EndScene.h"

class CEndWindow :
    public CWidgetWindow
{
    friend class CScene;
    friend class CCharacterHUD;
    friend class CGameObject;

protected:
    CEndWindow();
    virtual ~CEndWindow();

private:
    float   m_DelayTime;
    CSharedPtr<class CNumber>   m_Score;
    CSharedPtr<class CNumber>   m_CoinScore;



public:
    virtual bool Init();
    virtual void Update(float DeltaTime);

public:
    void OKButtonCallback();
};

