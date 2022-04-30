#pragma once

#include <Windows.h>

namespace Ax {

class AxCoord
{
public:
	AxCoord(int x = 0, int y = 0);
	AxCoord(const COORD& coord);
	AxCoord(const AxCoord& other);

	COORD ToStdCoord() const;

public:
	bool operator==(const AxCoord& other) const;
	bool operator!=(const AxCoord& other) const;
	AxCoord operator+(const AxCoord& other) const;
	AxCoord operator-(const AxCoord& other) const;
	AxCoord operator*(const AxCoord& other) const;
	AxCoord operator/(const AxCoord& other) const;
	AxCoord operator+(int other) const;
	AxCoord operator-(int other) const;
	AxCoord operator*(int other) const;
	AxCoord operator/(int other) const;
	AxCoord operator+=(const AxCoord& other);
	AxCoord operator-=(const AxCoord& other);
	AxCoord operator*=(const AxCoord& other);
	AxCoord operator/=(const AxCoord& other);
	AxCoord operator+=(int other);
	AxCoord operator-=(int other);
	AxCoord operator*=(int other);
	AxCoord operator/=(int other);

public:
	int x, y;
};

} // End Ax.