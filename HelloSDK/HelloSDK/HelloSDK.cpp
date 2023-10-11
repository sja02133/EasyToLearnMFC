#include <Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wndclass;
	HWND hwnd;

	MSG msg;

	//wndclass.style = CS_HREDRAW | CS_VREDRAW;		//�⺻
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;		//���� ���� 1
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// �⺻
	wndclass.hIcon = LoadIcon(NULL, IDI_QUESTION);		// ���� ���� 2
	//wndclass.hCursor = LoadCursorW(NULL, IDC_ARROW);		// �⺻
	wndclass.hCursor = LoadCursorW(NULL, IDC_UPARROW);		// ���� ���� 3
	//wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//�⺻
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// ���� ���� 4
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = TEXT("HelloClass");
	if (!RegisterClass(&wndclass)) return 1;

	//hwnd = CreateWindow(TEXT("HelloClass"), TEXT("HelloSDK"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
	//	CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	//hwnd = CreateWindow(TEXT("HelloClass"), TEXT("Hello World"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
	//	CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// ���� ���� 5
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("Hello World"), WS_POPUPWINDOW, 0, 0,
		500, 200, NULL, NULL, hInstance, NULL);	// ���� ���� 6
	
	ShowWindow(hwnd, nCmdShow);		//�⺻

	// ���� ���� 7
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

	//���� ���� 10
	int messageBoxReturnValue = 0;
	// -- 

	switch (message)
	{
	case WM_CREATE:
		return 0;
	case WM_LBUTTONDOWN:
		//MessageBox(hwnd, TEXT("���콺 Ŭ��"), TEXT("���콺 �޼���"), MB_OK);
		//MessageBox(hwnd, TEXT("���콺 Ŭ��"), TEXT("���콺 �޼���"), MB_YESNO);	// ���� ���� 8
		//MessageBox(hwnd, TEXT("���콺 Ŭ��"), TEXT("���콺 �޼���"), MB_OK | MB_ICONSTOP);	// ���� ���� 9
		
		// ���� ���� 10
		messageBoxReturnValue = MessageBox(hwnd, TEXT("���콺 Ŭ��"), TEXT("�����Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONSTOP);
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