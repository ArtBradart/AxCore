#include "AxRect.h"

namespace Ax {

AxRect::AxRect(const AxCoord& a, const AxCoord& b)
	: pMin(min(a.x, b.x), min(a.y, b.y))
	, pMax(max(a.x, b.x), max(a.y, b.y))
{}

AxRect::AxRect(int x1, int y1, int x2, int y2)
	: pMin(min(x1, x2), min(y1, y2))
	, pMax(max(x1, x2), max(y1, y2))
{}

AxRect::AxRect(const AxRect& other)
	: pMin(other.pMin)
	, pMax(other.pMax)
{}

AxRect AxRect::Intersect(const AxRect& other) const
{
	return AxRect::Intersect(*this, other);
}

AxRect AxRect::CorrectRect(const AxRect& rect)
{
	return { rect.pMin, rect.pMax };
}

AxRect AxRect::Intersect(const AxRect& A, const AxRect& B)
{
	AxRect a = CorrectRect(A);
	AxRect b = CorrectRect(B);
	return {
		max(a.pMin.x, b.pMin.x),
		max(a.pMin.y, b.pMin.y),
		min(a.pMax.y, b.pMax.y),
		min(a.pMax.y, b.pMax.y)
	};
}

bool AxRect::IsEmpty() const
{
	AxCoord size = Size();
	return size.x == 0 || size.y == 0;
}

AxCoord AxRect::Size() const
{
	return pMax - pMin;
}

bool AxRect::operator==(const AxRect& other) const
{
	return pMin == other.pMin && pMax == other.pMax;
}

bool AxRect::operator!=(const AxRect& other) const
{
	return !operator==(other);
}

} // End Ax.