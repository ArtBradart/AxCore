#include "Log.h"

Log* Log::_instance = 0;

Log::Log()
	: _hConsole(GetStdHandle(STD_OUTPUT_HANDLE))
	, _stdColor(0x000F)
{}

Log* Log::Instance()
{
	if (!_instance) { _instance = new Log(); }
	return _instance;
}

const COORD Log::GetPosition() const
{
	if (!IsValid()) return COORD();

	_CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(_hConsole, &csbInfo);
	return csbInfo.dwCursorPosition;
}

void Log::SetPosition(const COORD & pos)
{
	if (!IsValid()) return;

	SetConsoleCursorPosition(_hConsole, pos);
}

const COORD Log::Size() const
{
	if (!IsValid()) return COORD();

	_CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	GetConsoleScreenBufferInfo(_hConsole, &csbInfo);
	return COORD{ csbInfo.srWindow.Right, csbInfo.srWindow.Bottom };
}

void Log::SetCursorVisible(bool enable)
{
	if (!IsValid()) return;

	_CONSOLE_CURSOR_INFO ci;
	GetConsoleCursorInfo(_hConsole, &ci);
	if (BOOL(enable) == ci.bVisible) return;
	ci.bVisible = enable;
	SetConsoleCursorInfo(_hConsole, &ci);
}

void Log::Output(const string & text, WORD color)
{
	bool bDefColor = color == _stdColor;
	WORD defColor = _stdColor;
	if (!bDefColor) SetColor(color);
	cout << text;
	if (!bDefColor) SetColor(defColor);
}

void Log::SetColor(WORD color)
{
	if (color == _stdColor) return;
	_stdColor = color;
	SetConsoleTextAttribute(_hConsole, _stdColor);
}

void Log::SetColorBackground(WORD color)
{
	_stdColor = _stdColor & 0x00f0;
}

void Log::SetColorForeground(WORD color)
{
	_stdColor = _stdColor & 0x000f;
}

