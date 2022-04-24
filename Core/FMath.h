#pragma once

#include <math.h>
#include <Windows.h>

namespace Ax {
namespace FMath {

template<typename T>
T Clamp(T value, T min, T max)
{
	return std::min(std::max(value, min), max);
}

} // End FMath


// COORD.

bool Equals(const COORD& a, const COORD& b)
{
	return a.X == b.X && a.Y == b.Y;
}

/*
bool operator == (const COORD& a, const COORD& b)
{
	return a.X == b.X && a.Y == b.Y;
}

bool operator != (const COORD& a, const COORD& b)
{
	return !(a == b);
}
*/

} // End Ax.
