#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <xtl.h>
#include <DMusicI.h>


class CSound
{
protected:
	IDirectMusicSegment8* m_pSoundSegment;

public:
	CSound();
	void Create(char* filename);
	void PlaySound();
	void Release();
	void StopSound();

protected:
	static IDirectMusicLoader* m_pLoader;
	static IDirectMusicPerformance8* m_pPerformance;

	void LoadSound(char* filename);
	void SetupSound();
};

#endif