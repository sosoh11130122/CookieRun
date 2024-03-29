#pragma once

#include "../../Ref.h"

class CSound :
    public CRef
{
    friend class CSoundManager;

private:
    CSound();
    ~CSound();

private:
    FMOD::System* m_System;
    FMOD::Sound* m_Sound;
    FMOD::ChannelGroup* m_Group;
    FMOD::Channel* m_Channel;
    bool        m_Play;
    bool        m_Loop;
    bool        m_Pause;

public:
    bool GetPlay()   const
    {
        return m_Play;
    }

    bool GetLoop()  const
    {
        return m_Loop;
    }

public:
    bool LoadSound(FMOD::System* System, FMOD::ChannelGroup* Group, bool Loop,
        const char* FileName, const std::string& PathName = SOUND_PATH);
    void Play();
    void Stop();
    void Pause();
    void Resume();
};

