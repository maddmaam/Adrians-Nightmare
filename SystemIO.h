#ifndef SYSTEMIO_H
#define SYSTEMIO_H

#include "Global.h"

#define resource_NUM_RESOURCES 1UL

extern BYTE* g_pResourceSysMemData;
extern BYTE* g_pResourceVidMemData;

VOID* FindResourceByName( const CHAR* strName );

HRESULT LoadPackedResource( const CHAR* strResourceFilename );

HRESULT LoadXBGFile( const CHAR* strMeshFilename );

#endif