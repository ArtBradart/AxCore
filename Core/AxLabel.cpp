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

void AxLabel::SetText(const string & text)
{
	_text = text;
}

void AxLabel::SetColor(WORD color)
{
	_color = color;
}

} // End Ax.