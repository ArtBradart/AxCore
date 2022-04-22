#pragma once

#include "Common.h"

class Log
{
private:
	Log();

public:
	static Log* Instance();

	bool IsValid() const { return _hConsole != nullptr; }

	const COORD GetPosition() const;
	void SetPosition(const COORD& pos);
	const COORD Size() const;
	void SetCursorVisible(bool enable = true);
	void Output(const string& text, WORD color);

	void SetColor(WORD color = 0x000F);
	void SetColorBackground(WORD color = 0x0000);
	void SetColorForeground(WORD color = 0x000F);

	WORD GetStdColor() const { return _stdColor; }


private:
	static Log* _instance;

	HANDLE _hConsole;
	WORD _stdColor = 0x000F;

};