#pragma once

#include <string>
#include "AxItem.h"

namespace Ax {

using namespace std;

class AxLabel : public AxItem
{
	typedef AxItem Super;
public:
	AxLabel();
	AxLabel(const string& text);
	AxLabel(const string& text, WORD color);
	~AxLabel();

public:
	// AxObject overrides.
	virtual void Begin() override;
	virtual void Update() override;
	virtual void End() override;

public:
	inline const string Text() const { return _text; }
	void SetText(const string& text);
	inline const WORD Color() const { return _color; }
	void SetColor(WORD color);

protected:
	virtual void OnTextChanged() {};
	virtual void OnColorChanged() {};
protected:
	string _text;
	WORD _color;
};

}