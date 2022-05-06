#include "DXUT.h"
#include "resource.h"
#include "Engine/SceneManager.h"
#include "Engine/Materials/MaterialManager.h"

// 시작할 때 한번 실행
HRESULT CALLBACK OnD3D9CreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{
    cout << "Create Device" << endl;
    SceneManager::Instance()->Initialize();
    MaterialManager::Instance()->Initialize();
    return S_OK;
}

// 시작할 때 Create 후, 화면크기 바뀔 때 LostDevice 후 실행
HRESULT CALLBACK OnD3D9ResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{
    cout << "Reset Device" << endl;
    return S_OK;
}

// 프레임마다 실행
void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
    SceneManager::Instance()->GetCurrentScene()->Update(fElapsedTime);
    // Update
}

// 렌더링
void CALLBACK OnD3D9FrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
    HRESULT hr;

    // Clear the render target and the zbuffer 
    V( pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB( 0, 45, 50, 170 ), 1.0f, 0 ) );

    // Render the scene
    if( SUCCEEDED( pd3dDevice->BeginScene() ) )
    {
        SceneManager::Instance()->GetCurrentScene()->Render();
        // Render
        V( pd3dDevice->EndScene() );
    }
}


//--------------------------------------------------------------------------------------
// Handle messages to the application 
//--------------------------------------------------------------------------------------
// 얜 어따쓰는거지
LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing, void* pUserContext )
{
    return 0;
}

// 화면크기 바뀔 때, 끌 때 실행
void CALLBACK OnD3D9LostDevice( void* pUserContext )
{
    cout << "Lost Device" << endl;
}

// 끌 때 LostDevice 후 실행
void CALLBACK OnD3D9DestroyDevice( void* pUserContext )
{
    SceneManager::Instance()->GetCurrentScene()->Exit();
    MaterialManager::Instance()->Exit();
    cout << "Destroy Device" << endl;
}

//INT WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, int )
int main()
{
    // Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

    // Set the callback functions
    DXUTSetCallbackD3D9DeviceCreated( OnD3D9CreateDevice );
    DXUTSetCallbackD3D9DeviceReset( OnD3D9ResetDevice );
    DXUTSetCallbackFrameMove( OnFrameMove );
    DXUTSetCallbackD3D9FrameRender( OnD3D9FrameRender );
    DXUTSetCallbackMsgProc( MsgProc );
    DXUTSetCallbackD3D9DeviceLost( OnD3D9LostDevice );
    DXUTSetCallbackD3D9DeviceDestroyed( OnD3D9DestroyDevice );

    // TODO: Perform any application-level initialization here

    // Initialize DXUT and create the desired Win32 window and Direct3D device for the application
    DXUTInit( true, true ); // Parse the command line and show msgboxes
    DXUTSetHotkeyHandling( true, true, true );  // handle the default hotkeys
    DXUTSetCursorSettings( true, true ); // Show the cursor and clip it when in full screen
    DXUTCreateWindow( L"ABEngine" );
    DXUTCreateDevice( true, SCW, SCH );

    SceneManager::Instance()->ChangeScene(L"Test");

    // Start the render loop
    DXUTMainLoop();
    return DXUTGetExitCode();
}


