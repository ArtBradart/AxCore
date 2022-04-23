#pragma once

#include "Common.h"

namespace Ax {

class AxLabel
{
public:
	AxLabel();
	AxLabel(const string& text);
	AxLabel(const string& text, WORD color);
	~AxLabel();

	inline const string Text() const { return _text; }
	inline const WORD Color() const { return _color; }
	void SetText(const string& text);
	void SetColor(WORD color);

protected:
	string _text;
	WORD _color;
};

}