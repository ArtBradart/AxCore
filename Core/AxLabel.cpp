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

void AxLabel::Begin()
{
	Super::Begin();
}

void AxLabel::Update()
{
	Super::Update();
}

void AxLabel::End()
{
	Super::End();
}

void AxLabel::SetText(const string& text)
{
	if (_text != text)
	{
		_text = text;
		OnTextChanged();
	}
}

void AxLabel::SetColor(WORD color)
{
	if (_color != color)
	{
		_color = color;
		OnColorChanged();
	}
}

} // End Ax.