#include "AxLabel.h"

namespace Ax {

AxLabel::AxLabel()
	: _text("Title")
	, _color(0x000f)
{}

AxLabel::AxLabel(const string& text)
	: _text(text)
	, _color(0x000f)
{}

AxLabel::AxLabel(const string& text, WORD color)
	: _text(text)
	, _color(color)
{}

AxLabel::~AxLabel()
{
	_text.clear();
}

void AxLabel::SetText(const string& text)
{
	if (_text != text)
	{
		const string prevText = _text;
		_text = text;
		OnTextChanged(prevText);
	}
}

void AxLabel::SetColor(WORD color)
{
	if (_color != color)
	{
		const WORD prevColor = _color;
		_color = color;
		OnColorChanged(prevColor);
	}
}

} // End Ax.