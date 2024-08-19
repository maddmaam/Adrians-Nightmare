#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <stdio.h>

#include <xtl.h>
#include <DMusicI.h>


class CSound
{
protected:
	IDirectMusicSegment8* m_pSoundSegment;

public:
	CSound();
	void Create(LPSTR filename);
	void PlaySound();
	void Release();
	void StopSound();

protected:
	static IDirectMusicLoader* m_pLoader;
	static IDirectMusicPerformance8* m_pPerformance;
	static IDirectMusicAudioPath8* m_pMusicAudioPath;
	static IDirectMusicAudioPath8*   m_p3DAudioPath1;

	void LoadSound(char* filename);
	void SetupSound();
};

#endif