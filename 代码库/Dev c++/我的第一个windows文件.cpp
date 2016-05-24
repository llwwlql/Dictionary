#include <windows.h>
#include <stdio.h>
char szTitle[]="简单的 Hello 程序";		//标题条字符串 
char szWindowClass[]="W32";				//窗口类名 
ATOM MyRegisterClass(HINSTANCE);
BOOL InitInstance(HINSTANCE,int);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;
	MyRegisterClass(hInstance);
	if(!InitInstance(hInstance,nCmdShow))
		return FALSE;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc;
	wc.style=CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc=(WNDPROC)WndProc;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hInstance=hInstance;
	wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName=NULL;
	wc.lpszClassName=szWindowClass;
	return RegisterClass(&wc);
}

BOOL InitInstance(HINSTANCE hInstance,int nCmdShow)
{
	HWND hWnd;
	hWnd=CreateWindow(szWindowClass,szTitle,WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);
	if(!hWnd)
		return FALSE;
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	char szHello[]="Hello";
	switch(message)
	{
	case WM_PAINT:
			hdc=BeginPaint(hWnd,&ps);
			TextOut(hdc,80,150,szHello,strlen(szHello));
			EndPaint(hWnd,&ps);
			break;
	case WM_DESTROY:
			PostQuitMessage(0);
			break;
	default:
			return DefWindowProc(hWnd,message,wParam,lParam);

	}
	
	return 0;
}
