#include "Sound.h"
#include "Rendering\Render.h"
#include "myfactory.h"

CSound::CSound(void)
{
	m_pSoundSegment = NULL;
	m_pPerformance = NULL;
}

void CSound::Create(char* filename)
{
	if (g_pLoader == NULL)
	{
		SetupSound();
	}
	if(m_pPerformance == NULL)
	{
		SetupPerformer();
	}
	LoadSound(filename);
}

void CSound::LoadSound(LPSTR filename)
{
	HRESULT result;
	if( FAILED(result = g_pLoader->LoadObjectFromFile(CLSID_DirectMusicSegment, IID_IDirectMusicSegment8 , filename, (VOID**)&m_pSoundSegment)))
	{
		char szbuff[100];
		sprintf(szbuff, "File Load Failed: %x", result);
		DisplayText(szbuff, 100L, 70L);
	}
}

void CSound::PlaySound(IDirectMusicAudioPath8* path)
{
	HRESULT result;
	if( FAILED(result = m_pPerformance->PlaySegmentEx( m_pSoundSegment, NULL, NULL, 0, 0, &m_pSegmentState, NULL, path)))
	{
		char szbuff[100];
		sprintf(szbuff, "Play Segment Failed: %x", result);
		DisplayText(szbuff, 100L, 70L);
	}

	
}
HRESULT CSound::isPlayingRaw()
{
	return m_pPerformance->IsPlaying(m_pSoundSegment, NULL);
}

bool CSound::isPlaying()
{
	if(m_pPerformance->IsPlaying(m_pSoundSegment, NULL) == 1) {
		return true;
	}
	return false;
}

void CSound::setLoop(DWORD dwRepeats)
{
	m_pSoundSegment->SetRepeats(dwRepeats);
}

void CSound::SetupPerformer()
{
	DirectMusicCreateInstance(CLSID_DirectMusicPerformance, NULL, IID_IDirectMusicPerformance8, (VOID**)&m_pPerformance);
	if( FAILED(m_pPerformance->InitAudioX(DMUS_APATH_SHARED_STEREOPLUSREVERB, 32, 128, 0)))
	{
		DisplayText("InitAudioX Failed", 100L, 60L);
	}
}

void CSound::SetupSound()
{
	IDirectMusicHeap* pNormalHeap;
	DirectMusicCreateDefaultHeap(&pNormalHeap);

	IDirectMusicHeap* pPhysicalHeap;
	DirectMusicCreateDefaultPhysicalHeap(&pPhysicalHeap);

	//pNormalHeap, pPhysicalHeap, MyFactory
	DirectMusicInitializeEx(pNormalHeap, pPhysicalHeap, MyFactory );

	pNormalHeap->Release();
	pPhysicalHeap->Release();

	DirectMusicCreateInstance(CLSID_DirectMusicLoader, NULL, IID_IDirectMusicLoader8, (VOID**)&g_pLoader);

	g_pLoader->SetSearchDirectory(GUID_DirectMusicAllTypes, "D:\\Media\\", FALSE); 

	m_pPerformance->GetDefaultAudioPath( &g_MusicAudioPath );
	m_pPerformance->CreateStandardAudioPath(DMUS_APATH_SHARED_STEREOPLUSREVERB, 32, TRUE, &g_SfxPath);
}

void CSound::Release()
{
	m_pSoundSegment->Release();
}