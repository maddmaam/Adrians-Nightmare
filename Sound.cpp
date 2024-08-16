#include "Sound.h"

IDirectMusicLoader* CSound::m_pLoader;
IDirectMusicPerformance8* CSound::m_pPerformance;

CSound::CSound(void)
{
	m_pLoader = NULL;
	m_pPerformance = NULL;
}

void CSound::Create(char* filename)
{
	if ((m_pLoader == NULL) && (m_pPerformance == NULL))
	{
		//SetupSound();
	}
	//LoadSound(filename);
}