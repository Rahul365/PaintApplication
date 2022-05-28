#pragma once

template<typename T>
struct Point
{
	T x;
	T y;
	Point(T x = 0, T y = 0) { this->x = x; this->y = y; }
};

