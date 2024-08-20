#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <stdio.h>

#include <xtl.h>
#include <DMusicI.h>

static IDirectMusicLoader* g_pLoader;

static IDirectMusicAudioPath8* g_MusicAudioPath;
static IDirectMusicAudioPath8* g_SfxPath;

class CSound
{
protected:
	IDirectMusicPerformance8* m_pPerformance;
	IDirectMusicSegment8* m_pSoundSegment;
	IDirectMusicSegmentState* m_pSegmentState;

public:
	CSound();
	void Create(LPSTR filename);
	void PlaySound(IDirectMusicAudioPath8* path);
	void Release();
	void StopSound();
	bool isPlaying();
	HRESULT isPlayingRaw();
	void setLoop(DWORD dwRepeats);

protected:
	void LoadSound(char* filename);
	void SetupSound();
	void SetupPerformer();
};

#endif