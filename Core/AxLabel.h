#pragma once

#include <string>
#include "AxRect.h"
#include "AxNode.h"

namespace Ax {

using namespace std;

class AxLabel : public AxNode
{
	typedef AxNode Super;
public:
	AxLabel();
	~AxLabel();

public:
	virtual void Redraw() override;
	
	inline const string Text() const { return _text; }
	void SetText(const string& text);
	inline const WORD Color() const { return _color; }
	void SetColor(WORD color);

	AxRect GetRect() const;

protected:
	virtual void OnTextChanged();
	virtual void OnColorChanged();

protected:
	string _text;
	WORD _color;

	string _prevText;
	WORD _prevColor;
};

}