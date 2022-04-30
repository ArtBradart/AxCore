#pragma once

#include "AxCoord.h"

namespace Ax {

class AxRect
{
public:
	AxRect(const AxCoord& a = AxCoord(), const AxCoord& b = AxCoord());
	AxRect(int a, int b, int c, int d);
	AxRect(const AxRect& other);

	static AxRect CorrectRect(const AxRect& rect);
	static AxRect Intersect(const AxRect& A, const AxRect& B);
	AxRect Intersect(const AxRect& other) const;
	bool IsEmpty() const;
	AxCoord Size() const;

public:
	bool operator==(const AxRect& other) const;
	bool operator!=(const AxRect& other) const;

public:
	AxCoord pMin;
	AxCoord pMax;
};

} // End Ax.