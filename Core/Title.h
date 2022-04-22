#pragma once

#include "Common.h"

class Title
{
public:
	Title();
	Title(const string& text);
	Title(const string& text, WORD color);
	~Title();

	inline const string Text() const { return _text; }
	inline const WORD Color() const { return _color; }
	void SetText(const string& text);
	void SetColor(WORD color);

protected:
	string _text;
	WORD _color;
};