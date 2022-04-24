#pragma once

#include "FMath.h"
#include "AxObject.h"

namespace Ax {

class AxItem : public AxObject
{
public:
	void SetPosition(const COORD& position);
	COORD GetPosition() const;

protected:
	virtual void OnPositionChanged();

private:
	COORD _position = {};

};

} // End Ax.