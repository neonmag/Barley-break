#pragma once
#include "header.h"

class Pyatnashki
{
public:
	Pyatnashki(void);
public:
	~Pyatnashki(void);
	void PrintProcessInfo(PROCESSENTRY32 processInfo, HWND hList);
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Pyatnashki* ptr;
	void Cls_OnClose(HWND hwnd);
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	HWND hButton[16];
};