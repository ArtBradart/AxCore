#pragma once
#include <math.h>

namespace FMath {

template<typename T>
T Clamp(T value, T min, T max)
{
	return std::min(std::max(value, min), max);
}

} // end FMath