#include "Sound.h"
#include "Rendering\Render.h"
#include "myfactory.h"

#include "SystemIO.h"

//-----------------------------------------------------------------------------
// Name: InitSound()
// Desc: Sets up sound environment (only done once per game)
//-----------------------------------------------------------------------------
HRESULT InitSound()
{
	// Create heaps for memory
	IDirectMusicHeap* pNormalHeap;
	DirectMusicCreateDefaultHeap(&pNormalHeap);
	IDirectMusicHeap* pPhysicalHeap;
	DirectMusicCreateDefaultPhysicalHeap(&pPhysicalHeap);

	// Inistialise DirectX Audio
	DirectMusicInitializeEx(pNormalHeap, pPhysicalHeap, MyFactory );

	//free the heaps
	pNormalHeap->Release();
	pPhysicalHeap->Release();

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: CSound::CSound()
// Desc: Initialize the CSound object
//-----------------------------------------------------------------------------
CSound::CSound(void)
{
	m_pSoundSegment = NULL;
	m_pPerformance = NULL;
}

//-----------------------------------------------------------------------------
// Name: CSound::Create()
// Desc: Load and create the sound file
//-----------------------------------------------------------------------------
void CSound::Create(char* filename)
{
	SetupPerformer();

	HRESULT result;
	if( FAILED(result = LoadSound(filename, &m_pSoundSegment)) )
	{
		char szbuff[100];
		sprintf(szbuff, "Load Sound Failed: %x", result);
		DisplayText(szbuff, 100L, 70L); //TODO update to Debugger
	}
}

//-----------------------------------------------------------------------------
// Name: CSound::PlaySound()
// Desc: Play the Sound
//-----------------------------------------------------------------------------
void CSound::PlaySound(IDirectMusicAudioPath8* path)
{
	HRESULT result;
	if( FAILED(result = m_pPerformance->PlaySegmentEx( m_pSoundSegment, NULL, NULL, 0, 0, &m_pSegmentState, NULL, path)))
	{
		char szbuff[100];
		sprintf(szbuff, "Play Segment Failed: %x", result);
		DisplayText(szbuff, 100L, 70L); //TODO update to Debugger
	}
}

//-----------------------------------------------------------------------------
// Name: CSound::PlaySound()
// Desc: Play the Sound
//-----------------------------------------------------------------------------
void CSound::StopSound()
{
	HRESULT result;
	if( FAILED(result = m_pPerformance->StopEx(NULL, 0, 0)))
	{
		char szbuff[100];
		sprintf(szbuff, "Stop Segment Failed: %x", result);
		DisplayText(szbuff, 100L, 70L); //TODO update to Debugger
	}
}

//-----------------------------------------------------------------------------
// Name: CSound::isPlaying()
// Desc: Checks if the sound is currently playing
//-----------------------------------------------------------------------------
bool CSound::isPlaying()
{
	if(m_pPerformance->IsPlaying(m_pSoundSegment, NULL) == 1) {
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Name: CSound::setLoop()
// Desc: Sets the sound to loop or not
//-----------------------------------------------------------------------------
void CSound::setLoop(DWORD dwRepeats)
{
	m_pSoundSegment->SetRepeats(dwRepeats);
}

//-----------------------------------------------------------------------------
// Name: CSound::SetupPerformer()
// Desc: Sets up the performer (object that plays the sound threaded)
//-----------------------------------------------------------------------------
void CSound::SetupPerformer()
{
	DirectMusicCreateInstance(CLSID_DirectMusicPerformance, NULL, IID_IDirectMusicPerformance8, (VOID**)&m_pPerformance);
	if( FAILED(m_pPerformance->InitAudioX(DMUS_APATH_SHARED_STEREOPLUSREVERB, 32, 128, 0)))
	{
		DisplayText("InitAudioX Failed", 100L, 60L); //TODO update to Debugger
	}

	m_pPerformance->GetDefaultAudioPath( &g_MusicAudioPath );
	g_MusicAudioPath->SetVolume(0, 0);
	m_pPerformance->CreateStandardAudioPath(DMUS_APATH_SHARED_STEREOPLUSREVERB, 32, TRUE, &g_SfxPath);
	g_SfxPath->SetVolume(0, 0);
}

//-----------------------------------------------------------------------------
// Name: CSound::Release()
// Desc: Releases used memory
//-----------------------------------------------------------------------------
void CSound::Release()
{
	m_pSoundSegment->Release();
}