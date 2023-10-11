#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wndclass;
	HWND hwnd;

	MSG msg;

	//wndclass.style = CS_HREDRAW | CS_VREDRAW;		//기본
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;		//연습 문제 1
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// 기본
	wndclass.hIcon = LoadIcon(NULL, IDI_QUESTION);		// 연습 문제 2
	//wndclass.hCursor = LoadCursorW(NULL, IDC_ARROW);		// 기본
	wndclass.hCursor = LoadCursorW(NULL, IDC_UPARROW);		// 연습 문제 3
	//wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//기본
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// 연습 문제 4
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = TEXT("HelloClass");
	if (!RegisterClass(&wndclass)) return 1;

	//hwnd = CreateWindow(TEXT("HelloClass"), TEXT("HelloSDK"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
	//	CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	//hwnd = CreateWindow(TEXT("HelloClass"), TEXT("Hello World"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
	//	CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// 연습 문제 5
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("Hello World"), WS_POPUPWINDOW, 0, 0,
		500, 200, NULL, NULL, hInstance, NULL);	// 연습 문제 6
	
	ShowWindow(hwnd, nCmdShow);		//기본

	// 연습 문제 7
	//nCmdShow = SW_MAXIMIZE;
	//ShowWindow(hwnd, nCmdShow);
	// --

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	const TCHAR* str = TEXT("Hello, SDK");

	//연습 문제 10
	int messageBoxReturnValue = 0;
	// -- 

	switch (message)
	{
	case WM_CREATE:
		return 0;
	case WM_LBUTTONDOWN:
		//MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("마우스 메세지"), MB_OK);
		//MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("마우스 메세지"), MB_YESNO);	// 연습 문제 8
		//MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("마우스 메세지"), MB_OK | MB_ICONSTOP);	// 연습 문제 9
		
		// 연습 문제 10
		messageBoxReturnValue = MessageBox(hwnd, TEXT("마우스 클릭"), TEXT("종료하시겠습니까?"), MB_YESNO | MB_ICONSTOP);
		if(messageBoxReturnValue == IDYES)
			PostQuitMessage(0);
		// --
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, str, lstrlen(str));
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}