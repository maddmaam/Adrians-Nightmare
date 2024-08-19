#include "Sound.h"
#include "Rendering\Render.h"

IDirectMusicLoader* CSound::m_pLoader = NULL;
IDirectMusicPerformance8* CSound::m_pPerformance = NULL;
IDirectMusicAudioPath8* CSound::m_pMusicAudioPath = NULL;
IDirectMusicAudioPath8*   CSound::m_p3DAudioPath1 = NULL;

CSound::CSound(void)
{
	m_pLoader = NULL;
	m_pPerformance = NULL;
}

void CSound::Create(char* filename)
{
	if ((m_pLoader == NULL) && (m_pPerformance == NULL))
	{
		DisplayText("Setting Up Sound", 100L, 100L);
		SetupSound();
	}
	LoadSound(filename);
}

void CSound::LoadSound(char* filename)
{
	m_pLoader->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8, filename, (VOID**) &m_pSoundSegment);
}

void CSound::PlaySound()
{
	m_pPerformance->PlaySegmentEx( m_pSoundSegment, NULL, NULL, DMUS_SEGF_SECONDARY,
                                               0, NULL, NULL, m_p3DAudioPath1 );
}

void CSound::SetupSound()
{
	IDirectMusicHeap* pNormalHeap;
	DirectMusicCreateDefaultHeap(&pNormalHeap);

	IDirectMusicHeap* pPhysicalHeap;
	DirectMusicCreateDefaultPhysicalHeap(&pPhysicalHeap);

	DirectMusicInitializeEx( pNormalHeap, pPhysicalHeap, &DirectMusicDefaultFactory);

	pNormalHeap->Release();
	pPhysicalHeap->Release();

	DirectMusicCreateInstance( CLSID_DirectMusicLoader, NULL, IID_IDirectMusicLoader8, (VOID**) &m_pLoader);

	DirectMusicCreateInstance(CLSID_DirectMusicPerformance, NULL, IID_IDirectMusicPerformance8, (VOID**) &m_pPerformance);

	m_pPerformance->InitAudioX( DMUS_APATH_SHARED_STEREOPLUSREVERB, 64, 128, 0);

	m_pPerformance->GetDefaultAudioPath( &m_pMusicAudioPath );

	m_pMusicAudioPath->SetVolume( (100*100)-10000, 0 );

	DirectSoundUseLightHRTF();

	m_pPerformance->CreateStandardAudioPath ( DMUS_APATH_DYNAMIC_3D, 64,
                                             TRUE, &m_p3DAudioPath1 );
}

void CSound::Release()
{
	m_pSoundSegment->Release();
}