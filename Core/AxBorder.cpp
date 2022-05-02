#include "AxBorder.h"

#include "AxLog.h"

namespace Ax {

void AxBorder::Redraw()
{
	auto log = AxLog::Instance();
	AxCoord tempPosition = log->GetPosition();

	// Clear border.
	if (_prevSize.x != 0 && _prevSize.y != 0)
	{
		string line;
		for (int i = 0; i < _prevSize.x; i++) 
			line += " ";

		log->SetPosition(_prevLocation.ToStdCoord());
		log->Clear(line);
		log->SetPosition((_prevLocation + AxCoord(0, _prevSize.y - 1)).ToStdCoord());
		log->Clear(line);

		for (int i = 1; i < _prevSize.y - 1; i++)
		{
			log->SetPosition((_prevLocation + AxCoord(0, i)).ToStdCoord());
			log->Clear(" ");
			log->SetPosition((_prevLocation + AxCoord(_prevSize.x - 1, i)).ToStdCoord());
			log->Clear(" ");
		}
	}

	if (_size.x != 0 && _size.y != 0)
	{
		string line;
		for (int i = 0; i < _size.x; i++)
			line += "=";

		log->SetPosition(_location.ToStdCoord());
		log->Output(line, _color);
		log->SetPosition((_location + AxCoord(0, _size.y - 1)).ToStdCoord());
		log->Output(line, _color);

		for (int i = 1; i < _size.y - 1; i++)
		{
			log->SetPosition((_location + AxCoord(0, i)).ToStdCoord());
			log->Output("|", _color);
			log->SetPosition((_location + AxCoord(_size.x - 1, i)).ToStdCoord());
			log->Output("|", _color);
		}
	}

	log->SetPosition(tempPosition.ToStdCoord());

	_prevSize = _size;
	_prevColor = _color;

	Super::Redraw();
}

void AxBorder::SetColor(WORD color)
{
	if (_color != color)
	{
		_color = color;
		OnColorChanged();
	}
}

void AxBorder::SetSize(const AxCoord& size)
{
	if (_size != size)
	{
		_size = size;
		OnSizeChanged();
	}
}

void AxBorder::OnSizeChanged()
{
	if (IsInited()) Redraw();
}

void AxBorder::OnColorChanged()
{
	if (IsInited()) Redraw();
}

} // End Ax.