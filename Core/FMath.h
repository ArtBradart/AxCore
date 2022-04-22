#pragma once
#include <math.h>

namespace FMath {

template<typename T>
T Min(T v1, T v2)
{
	return v1 < v2 ? v1 : v2;
}

template<typename T>
T Max(T v1, T v2)
{
	return v1 > v2 ? v1 : v2;
}

template<typename T>
T Clamp(T value, T min, T max)
{
	return Min(Max(value, min), max);
}

} // end FMath