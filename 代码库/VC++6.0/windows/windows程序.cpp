#include  <windows.h>
char szTitle[]="�򵥵� Hello ����";
char szWindowClass[]="W32";

ATOM MyRegisterClass(HINSTANCE);				//ATOM == unsigned short

BOOL InitInstance(HINSTANCE,int);

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;							//������Ϣ�ṹ����
	MyRegisterClass(hInstance);			//ע�ᴰ��
	if(!InitInstance(hInstance,nCmdShow))		//��ʼ��
		return FALSE;
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);			//������Ϣ
	}

	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc;		//�������ڽṹ����

	//��ʼ������wc��ֵ
	wc.style=CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc=(WNDPROC)WndProc;		//�ص������ĺ���ָ��
	wc.cbClsExtra=0;			//�����฽������
	wc.cbWndExtra=0;			//���ڸ�������
	wc.hInstance=hInstance;			//ӵ�д������ʵ�����
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