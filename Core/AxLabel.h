#pragma once

#include <string>
#include "AxNode.h"

namespace Ax {

using namespace std;

class AxLabel : public AxNode
{
	typedef AxNode Super;
public:
	AxLabel();
	AxLabel(const string& text);
	AxLabel(const string& text, WORD color);
	~AxLabel();

public:
	inline const string Text() const { return _text; }
	void SetText(const string& text);
	inline const WORD Color() const { return _color; }
	void SetColor(WORD color);

protected:
	virtual void OnTextChanged(const string& prevText) {};
	virtual void OnColorChanged(const WORD& prevColor) {};

protected:
	string _text;
	WORD _color;
};

}