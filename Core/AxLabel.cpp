#include "AxLabel.h"

#include "AxLog.h"

namespace Ax {

AxLabel::AxLabel()
	: _text("Title")
	, _color(0x000f)
	, _prevText()
	, _prevColor()
{}

AxLabel::~AxLabel()
{
	_text.clear();
}

void AxLabel::Redraw()
{
	auto log = AxLog::Instance();
	AxCoord tempPosition = log->GetPosition();

	log->SetPosition(_prevLocation.ToStdCoord());
	log->Clear(_prevText);

	log->SetPosition(GetGlobalLocation().ToStdCoord());
	log->Output(_text, _color);

	log->SetPosition(tempPosition.ToStdCoord());

	_prevText = _text;
	_prevColor = _color;
	Super::Redraw();
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

AxRect AxLabel::GetRect() const
{
	AxCoord coord = GetGlobalLocation();
	return { coord, coord + AxCoord((int)_text.size(), 1) };
}

void AxLabel::OnTextChanged()
{
	if (IsInited()) Redraw();
}

void AxLabel::OnColorChanged()
{
	if (IsInited()) Redraw();
}

} // End Ax.