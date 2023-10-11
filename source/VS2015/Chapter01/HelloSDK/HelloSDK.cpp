#include <windows.h>

// WinMain �Լ����� �����ϹǷ� �Լ� ������ �����Ѵ�.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wndclass;
	HWND hwnd;
	MSG msg;

	// ������ Ŭ������ �ʱ�ȭ�ϰ� �ü���� ����Ѵ�.
	wndclass.style = CS_HREDRAW | CS_VREDRAW; // ��Ÿ�� ����
	wndclass.lpfnWndProc = WndProc; // ������ ���ν��� �̸�
	wndclass.cbClsExtra = 0; // ���� �޸�(0����Ʈ)
	wndclass.cbWndExtra = 0; // ���� �޸�(0����Ʈ)
	wndclass.hInstance = hInstance; // �ν��Ͻ� �ڵ�
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ������ ���
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // Ŀ�� ���
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���(���)
	wndclass.lpszMenuName = NULL; // �޴�(NULL->�޴� ����)
	wndclass.lpszClassName = TEXT("HelloClass"); // ������ Ŭ���� �̸�
	if (!RegisterClass(&wndclass)) return 1;

	// �����츦 �����ϰ� ȭ�鿡 ��Ÿ����.
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("HelloSDK"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);

	// �޽��� ť���� �޽����� �ϳ��� ������ ó���Ѵ�.
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	const TCHAR* str = TEXT("Hello, SDK");

	// �߻��� �޽����� ������ ���� ������ ó���Ѵ�.
	switch (message) {
	case WM_CREATE:
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("���콺 Ŭ��!"), TEXT("���콺 �޽���"), MB_OK);
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

	// ���� ���α׷��� ó������ ���� �޽����� �ü���� ó���Ѵ�.
	return DefWindowProc(hwnd, message, wParam, lParam);
}
