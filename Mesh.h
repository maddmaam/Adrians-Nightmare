#ifndef MESH_H
#define MESH_H

#include "Global.h"

//-----------------------------------------------------------------------------
// Name: struct XBMESH_SUBSET
// Desc: Struct to hold data for rendering a mesh
//-----------------------------------------------------------------------------
struct XBMESH_SUBSET
{
    D3DMATERIAL8       mtrl;            // Material for this subset
    LPDIRECT3DTEXTURE8 pTexture;        // Texture
    CHAR               strTexture[64];
    DWORD              dwVertexStart;   // Range of vertices to render
    DWORD              dwVertexCount;
    DWORD              dwIndexStart;    // Range of vertex indices to render
    DWORD              dwIndexCount;
};

//-----------------------------------------------------------------------------
// Name: struct XBMESH_DATA
// Desc: Struct for mesh data
//-----------------------------------------------------------------------------
struct XBMESH_DATA
{
    D3DVertexBuffer   m_VB;            // Mesh geometry
    DWORD             m_dwNumVertices;
    D3DIndexBuffer    m_IB;
    DWORD             m_dwNumIndices;
    
    DWORD             m_dwFVF;         // Mesh vertex info
    DWORD             m_dwVertexSize;
    D3DPRIMITIVETYPE  m_dwPrimType;

    DWORD             m_dwNumSubsets;  // Subset info for rendering calls
    XBMESH_SUBSET*    m_pSubsets;
};

//-----------------------------------------------------------------------------
// Name: struct XBMESHFRAME
// Desc: Struct for building a hierarchy of meshes.
//-----------------------------------------------------------------------------
__declspec(align(16)) struct XBMESH_FRAME
{
    D3DXMATRIX        m_matTransform; // The transformation matrix for this frame
    
    XBMESH_DATA       m_MeshData;     // The mesh data belonging to this frame

    CHAR              m_strName[64];
    
    XBMESH_FRAME*     m_pChild;       // Child and sibling ptrs for the hierarchy
    XBMESH_FRAME*     m_pNext;
};

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
extern VOID* g_pMeshSysMemData; // Sysmem data for the mesh
extern VOID* g_pMeshVidMemData; // Vidmem data for the mesh
extern XBMESH_FRAME* g_pMeshFrames; // Num of hierarchial frames in the mesh
extern DWORD g_dwNumMeshFrames;   // Hierarchy of frames for the mesh


HRESULT RenderMesh( LPDIRECT3DDEVICE8 pd3dDevice, XBMESH_DATA* pMesh );

#endif