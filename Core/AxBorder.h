#pragma once
#include "AxNode.h"

namespace Ax {

class AxBorder : public AxNode
{
	typedef AxNode Super;
public:
	virtual void Redraw() override;

	inline const WORD Color() const { return _color; }
	void SetColor(WORD color);

	inline const AxCoord Size() const { return _size; }
	void SetSize(const AxCoord& size);

protected:
	virtual void OnSizeChanged();
	virtual void OnColorChanged();

protected:
	AxCoord _size;
	AxCoord _prevSize;

	WORD _color;
	WORD _prevColor;
};

} // End Ax.