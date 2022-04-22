#pragma once

#include "Common.h"

static HANDLE _hConsole;
static WORD _stdColor;

static class Log
{
public:
	Log();

	static const COORD GetPosition();
	static void SetPosition(const COORD& pos);
	static const COORD Size();
	static void SetCursorVisible(bool enable = true);
	static void Output(const string& text, WORD color = _stdColor);

	static void SetColor(WORD color = 0x000F);
	static void SetColorBackground(WORD color = 0x0000);
	static void SetColorForeground(WORD color = 0x000F);

};