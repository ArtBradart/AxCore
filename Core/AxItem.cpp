#include "AxItem.h"

namespace Ax {

void AxItem::SetPosition(const COORD& position)
{
	if (!Equals(_position, position)) {
		_position = position;
		OnPositionChanged();
	}
}

COORD AxItem::GetPosition() const
{
	return _position;
}

void AxItem::OnPositionChanged()
{}

} // End Ax.