#pragma once

#include "Common.h"

static HANDLE _hConsole;
static WORD _stdColor = 0x000F;

class Log
{
private:
	Log();

public:
	static Log* Instance();
	const COORD GetPosition() const;
	void SetPosition(const COORD& pos);
	const COORD Size() const;
	void SetCursorVisible(bool enable = true);
	void Output(const string& text, WORD color = _stdColor);

	void SetColor(WORD color = 0x000F);
	void SetColorBackground(WORD color = 0x0000);
	void SetColorForeground(WORD color = 0x000F);

private:
	static Log* _instance;

};