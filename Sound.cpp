#include "Sound.h"
#include "Rendering\Render.h"
#include "myfactory.h"

IDirectMusicLoader* CSound::m_pLoader = NULL;
IDirectMusicPerformance8* CSound::m_pPerformance = NULL;
IDirectMusicAudioPath8* CSound::m_pMusicAudioPath = NULL;
IDirectMusicAudioPath8*   CSound::m_p3DAudioPath1 = NULL;

CSound::CSound(void)
{
	m_pLoader = NULL;
	m_pPerformance = NULL;
	m_pSoundSegment = NULL;
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

void CSound::LoadSound(LPSTR filename)
{
	m_pLoader->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8, filename, (VOID**)&m_pSoundSegment);
}

void CSound::PlaySound()
{
	//m_pPerformance->PlaySegmentEx( m_pSoundSegment, NULL, NULL, 0, 0, NULL, NULL, NULL );
}

void CSound::SetupSound()
{
	IDirectMusicHeap* pNormalHeap;
	DirectMusicCreateDefaultHeap(&pNormalHeap);

	IDirectMusicHeap* pPhysicalHeap;
	DirectMusicCreateDefaultPhysicalHeap(&pPhysicalHeap);

	DirectMusicInitializeEx( pNormalHeap, pPhysicalHeap, MyFactory);

	pNormalHeap->Release();
	pPhysicalHeap->Release();

	DirectMusicCreateInstance( CLSID_DirectMusicLoader, NULL, IID_IDirectMusicLoader8, (VOID**)&m_pLoader);
	DirectMusicCreateInstance(CLSID_DirectMusicPerformance, NULL, IID_IDirectMusicPerformance8, (VOID**)&m_pPerformance);

	m_pPerformance->InitAudioX( DMUS_APATH_SHARED_STEREOPLUSREVERB, 64, 128, 0);

	m_pLoader->SetSearchDirectory( GUID_DirectMusicAllTypes, "D:\\Media", FALSE );

}

void CSound::Release()
{
	m_pSoundSegment->Release();
}