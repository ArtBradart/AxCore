#include "AxLog.h"

#include <iostream>

namespace Ax {

AxLog* AxLog::_instance = 0;

AxLog::AxLog()
	: _hConsole(GetStdHandle(STD_OUTPUT_HANDLE))
	, _stdColor(0x000F)
{}

AxLog* AxLog::Instance()
{
	if (!_instance) { _instance = new AxLog(); }
	return _instance;
}

const COORD AxLog::GetPosition() const
{
	if (!IsValid()) return COORD();

	_CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(_hConsole, &csbInfo);
	return csbInfo.dwCursorPosition;
}

void AxLog::SetPosition(const COORD & pos)
{
	if (!IsValid()) return;

	SetConsoleCursorPosition(_hConsole, pos);
}

const COORD AxLog::Size() const
{
	if (!IsValid()) return COORD();

	_CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(_hConsole, &csbInfo);
	return COORD{ csbInfo.srWindow.Right, csbInfo.srWindow.Bottom };
}

void AxLog::SetCursorVisible(bool enable)
{
	if (!IsValid()) return;

	_CONSOLE_CURSOR_INFO ci;
	GetConsoleCursorInfo(_hConsole, &ci);
	if (BOOL(enable) == ci.bVisible) return;
	ci.bVisible = enable;
	SetConsoleCursorInfo(_hConsole, &ci);
}

void AxLog::Output(const string & text, WORD color)
{
	bool bDefColor = color == _stdColor;
	WORD defColor = _stdColor;
	if (!bDefColor) SetColor(color);
	cout << text;
	if (!bDefColor) SetColor(defColor);
}

void AxLog::Clear(const string& text)
{
	for (const char& c : text)
		cout << ' ';
}

void AxLog::SetColor(WORD color)
{
	if (color == _stdColor) return;
	_stdColor = color;
	SetConsoleTextAttribute(_hConsole, _stdColor);
}

void AxLog::SetColorBackground(WORD color)
{
	_stdColor = _stdColor & 0x00f0;
}

void AxLog::SetColorForeground(WORD color)
{
	_stdColor = _stdColor & 0x000f;
}

} // End Ax.