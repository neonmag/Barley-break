#include "Pyatnashki.h"
using namespace std;

int pressedButton;
int arr[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
TCHAR buf[10];

void Pyatnashki::PrintProcessInfo(PROCESSENTRY32 processInfo, HWND hList)
{
	SendMessage(hList, LB_ADDSTRING, 0, LPARAM(processInfo.szExeFile));
}

Pyatnashki* Pyatnashki::ptr = NULL;

Pyatnashki::Pyatnashki(void)
{
	ptr = this;
}

Pyatnashki::~Pyatnashki(void)
{

}

void Pyatnashki::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL Pyatnashki::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	srand(time(0));
	for (int i = 0; i < 16; i++)
	{
		hButton[i] = GetDlgItem(hwnd, IDC_BUTTON1 + i);
	}
	for (int i = 0; i < 15; i++)
	{
		arr[i] = rand() % 15 + 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
		_itow_s(arr[i], buf, 10);
		SetWindowText(hButton[i], buf);
	}
	_itow_s(0, buf, 10);
	SetWindowText(hButton[15], buf);
	for (int i = 0; i < 16; i++)
	{
		if (i == 14 || i == 11)
		{
			EnableWindow(hButton[i], TRUE);
		}
		else
		{
			EnableWindow(hButton[i], FALSE);
		}
	}
	return TRUE;
}

void Pyatnashki::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
	{
	case IDC_BUTTON1:
		pressedButton = 1;
		break;
	case IDC_BUTTON2:
		pressedButton = 2;
		break;
	case IDC_BUTTON3:
		pressedButton = 3;
		break;
	case IDC_BUTTON4:
		pressedButton = 4;
		break;
	case IDC_BUTTON5:
		pressedButton = 5;
		break;
	case IDC_BUTTON6:
		pressedButton = 6;
		break;
	case IDC_BUTTON7:
		pressedButton = 7;
		break;
	case IDC_BUTTON8:
		pressedButton = 8;
		break;
	case IDC_BUTTON9:
		pressedButton = 9;
		break;
	case IDC_BUTTON10:
		pressedButton = 10;
		break;
	case IDC_BUTTON11:
		pressedButton = 11;
		break;
	case IDC_BUTTON12:
		pressedButton = 12;
		break;
	case IDC_BUTTON13:
		pressedButton = 13;
		break;
	case IDC_BUTTON14:
		pressedButton = 14;
		break;
	case IDC_BUTTON15:
		pressedButton = 15;
		break;
	case IDC_BUTTON16:
		pressedButton = 16;
		break;
	}
	for (int i = 0; i < 16; i++)
	{
		if (arr[i] == 0)
		{
			swap(arr[i], arr[pressedButton - 1]);
			_itow_s(arr[i], buf, 10);
			SetWindowText(hButton[i], buf);
			_itow_s(arr[pressedButton - 1], buf, 10);
			SetWindowText(hButton[pressedButton - 1], buf);
			break;
		}
		_itow_s(arr[i], buf, 10);
		SetWindowText(hButton[i], buf);
	}
	for (int i = 0; i < 16; i++)
	{
		EnableWindow(hButton[i], FALSE);
	}
	if (pressedButton == 1 || pressedButton == 5 || pressedButton == 9 || pressedButton == 13)
	{
		EnableWindow(hButton[pressedButton - 2], FALSE);
		EnableWindow(hButton[pressedButton + 3], TRUE);
	}
	else
	{
		EnableWindow(hButton[pressedButton - 2], TRUE);
		EnableWindow(hButton[pressedButton + 3], TRUE);
	}
	if (pressedButton == 4 || pressedButton == 8 || pressedButton == 12 || pressedButton == 16)
	{
		EnableWindow(hButton[pressedButton], FALSE);
	}
	else
	{
		EnableWindow(hButton[pressedButton], TRUE);
	}
	EnableWindow(hButton[pressedButton - 5], TRUE);
	for (int i = 0; i < 15; i++)
	{
		if (arr[i] == i + 1)
		{
			if (i == 14)
			{
				MessageBox(hwnd, L"WIN", L"WIN", MB_OK);
				EndDialog(hwnd, 0);
			}
			continue;
		}
		else
		{
			break;
		}
	}
}

BOOL CALLBACK Pyatnashki::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}