#include "AxCoord.h"

AxCoord::AxCoord(int x, int y)
	: x(x), y(y)
{}

AxCoord::AxCoord(const COORD& coord)
	: x(coord.X), y(coord.Y)
{}

AxCoord::AxCoord(const AxCoord& other)
	: x(other.x), y(other.y)
{}

COORD AxCoord::ToStdCoord() const
{
	return { (SHORT)x, (SHORT)y };
}


bool AxCoord::operator==(const AxCoord& other) const
{
	return x == other.x && y == other.y;
}

bool AxCoord::operator!=(const AxCoord& other) const
{
	return x != other.x || y != other.y;
}

AxCoord AxCoord::operator+(const AxCoord& other) const
{
	return {
		x + other.x, 
		y + other.y 
	};
}

AxCoord AxCoord::operator-(const AxCoord& other) const
{
	return {
		x - other.x,
		y - other.y
	};
}

AxCoord AxCoord::operator*(const AxCoord& other) const
{
	return {
		x * other.x,
		y * other.y
	};
}

AxCoord AxCoord::operator/(const AxCoord& other) const
{
	return {
		x / other.x,
		y / other.y
	};
}

AxCoord AxCoord::operator+(int other) const
{
	return {
		x + other,
		y + other
	};
}

AxCoord AxCoord::operator-(int other) const
{
	return {
		x - other,
		y - other
	};
}

AxCoord AxCoord::operator*(int other) const
{
	return {
		x * other,
		y * other
	};
}

AxCoord AxCoord::operator/(int other) const
{
	return {
		x / other,
		y / other
	};
}

AxCoord AxCoord::operator+=(const AxCoord& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

AxCoord AxCoord::operator-=(const AxCoord& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

AxCoord AxCoord::operator*=(const AxCoord& other)
{
	x *= other.x;
	y *= other.y;
	return *this;
}

AxCoord AxCoord::operator/=(const AxCoord& other)
{
	x /= other.x;
	y /= other.y;
	return *this;
}

AxCoord AxCoord::operator+=(int other)
{
	x += other;
	y += other;
	return *this;
}

AxCoord AxCoord::operator-=(int other)
{
	x -= other;
	y -= other;
	return *this;
}

AxCoord AxCoord::operator*=(int other)
{
	x *= other;
	y *= other;
	return *this;
}

AxCoord AxCoord::operator/=(int other)
{
	x /= other;
	y /= other;
	return *this;
}
