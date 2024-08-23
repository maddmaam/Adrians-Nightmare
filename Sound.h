#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <stdio.h>

#include "Global.h"
#include <DMusicI.h>

static IDirectMusicAudioPath8* g_MusicAudioPath;
static IDirectMusicAudioPath8* g_SfxPath;

HRESULT InitSound();

// Class that holds and plays Audio
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
	void StopSound(); //TODO not implemented? I guess?
	bool isPlaying();
	void setLoop(DWORD dwRepeats);
	void Release();

protected:
	void SetupPerformer();
};

#endif