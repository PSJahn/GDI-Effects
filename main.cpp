#include <Windows.h>

HDC hdc = GetDC(0);
int sw = GetSystemMetrics(SM_CXSCREEN);
int sh = GetSystemMetrics(SM_CYSCREEN);
int _h = rand() % sw - (sw / 2 - 110);

void CI(int x, int y, int w, int h)
{
	HDC hdc = GetDC(0);
	HRGN hrgn = CreateEllipticRgn(x, y, w + x, h + y);
	SelectClipRgn(hdc, hrgn);
	BitBlt(hdc, x, y, w, h, hdc, x, y, NOTSRCCOPY);
	DeleteObject(hrgn);
	ReleaseDC(NULL, hdc);
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	
	for (int a = 0; a < 100; a++)
	{
		SelectObject(hdc, CreateSolidBrush(RGB(rand() % 100, rand() % 200, rand() % 100)));
		BitBlt(hdc, rand() % 21 - 10, rand() % 21 - 20, sw, sh, hdc, 0, 0, SRCAND);
		BitBlt(hdc, rand() % 21 - 10, rand() % 21 - 10, sw, sh, hdc, 0, 0, PATINVERT);
	}
	Sleep(100);

	for (int b = 0; b < 100; b++)
	{
		SelectObject(hdc, CreateSolidBrush(RGB(rand() % 100, rand() % 200, rand() % 100)));
		BitBlt(hdc, rand() % 21 - 10, rand() % 21 - 20, sw, sh, hdc, 0, 0, SRCAND);
		BitBlt(hdc, rand() % 21 - 10, rand() % 21 - 10, sw, sh, hdc, 0, 0, PATINVERT);
	}
	Sleep(100);

	for (int c = 0; c < 100; c++)
	{
		SelectObject(hdc, CreateSolidBrush(RGB(rand() % 100, rand() % 2, rand() % 2)));
		BitBlt(hdc, 10 - 10, 10 - 10, sw, sh, hdc, 2, 2, SRCAND);
		BitBlt(hdc, 10 - 10, 12 - 12, sw, sh, hdc, 10, 10, PATINVERT);
	}
	Sleep(100);

	for (int d = 0; d < 100; d++)
	{
		SelectObject(hdc, CreateSolidBrush(RGB(rand() % 123, rand() % 431, rand() % 311)));
		BitBlt(hdc, rand() % 10 - 30, rand() % 21 - 10, sw, sh, hdc, 0, 0, 0x9273ecef);
		BitBlt(hdc, rand() % 21 - 40, rand() % 21 - 10, sw, sh, hdc, 0, 0, PATINVERT);
	}
	Sleep(100);

	RECT rect;
	GetWindowRect(GetDesktopWindow(), &rect);
	int w = rect.right - rect.left - 500, h = rect.bottom - rect.top - 500;

	for (int t = 0;t < 100; t++)
	{
		const int size = 300;
		int x = rand() % (w + size) - size / 2, y = rand() % (h + size) - size / 2;

		for (int i = 0; i < size; i += 100)
		{
			CI(x - i / 2, y - i / 2, i, i);
			Sleep(25);
		}
	}

	for (int q = 0;q < 100; q++) {

		HDC hdc = GetDC(GetDesktopWindow());
		RECT rekt;
		int w = GetSystemMetrics(SM_CXSCREEN);
		int h = GetSystemMetrics(SM_CYSCREEN);
		int _h = rand() % w - (w / 2 - 110);

		GetWindowRect(GetDesktopWindow(), &rekt);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, brush);
		int xyrng = rand() % w;

		POINT pt3[3];
		int inc3 = 60;
		inc3++;
		pt3[0].x = rekt.left + inc3;
		pt3[0].y = rekt.top - inc3;
		pt3[1].x = rekt.right + inc3;
		pt3[1].y = rekt.top + inc3;
		pt3[2].x = rekt.left - inc3;
		pt3[2].y = rekt.bottom - inc3;

		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);
		PlgBlt(hdc, pt3, hdc, rekt.left, rekt.top, rekt.right - rekt.left, rekt.bottom - rekt.top, 0, 0, 0);

		BitBlt(hdc, xyrng, _h, xyrng, _h, hdc, rand() % 100 - 50, xyrng, SRCCOPY);
		PatBlt(hdc, xyrng, h, xyrng, _h, PATINVERT);

		StretchBlt(hdc, -16, -16, w + 32, _h + 32, hdc, 0, 0, w, _h, SRCCOPY);
		StretchBlt(hdc, 16, 16, w - 32, _h - 32, hdc, 0, 0, w, _h, SRCCOPY);
	}
}