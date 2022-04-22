#include "Title.h"

Title::Title()
	: _text("Title")
	, _color(0x000f)
{}

Title::Title(const string& text)
	: _text(text)
	, _color(0x000f)
{}

Title::Title(const string& text, WORD color)
	: _text(text)
	, _color(color)
{}

Title::~Title()
{
	_text.clear();
}

void Title::SetText(const string & text)
{
	_text = text;
}

void Title::SetColor(WORD color)
{
	_color = color;
}
