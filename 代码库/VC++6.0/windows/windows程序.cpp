#include  <windows.h>
char szTitle[]="简单的 Hello 程序";
char szWindowClass[]="W32";

ATOM MyRegisterClass(HINSTANCE);				//ATOM == unsigned short

BOOL InitInstance(HINSTANCE,int);

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;							//声明消息结构对象
	MyRegisterClass(hInstance);			//注册窗口
	if(!InitInstance(hInstance,nCmdShow))		//初始化
		return FALSE;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);			//处理消息
	}

	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc;		//声明窗口结构对象

	//初始化对象wc的值
	wc.style=CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc=(WNDPROC)WndProc;		//回调函数的函数指针
	wc.cbClsExtra=0;			//窗口类附加数据
	wc.cbWndExtra=0;			//窗口附加数据
	wc.hInstance=hInstance;			//拥有窗口类的实例句柄
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
	hWnd=CreateWindow(
			szWindowClass,
			szTitle,
			WS_OVERLAPPEDWINDOW|
			WS_VSCROLL|
			WS_HSCROLL,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			hInstance,
			NULL);
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
	char szHello[]="Hello World";
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