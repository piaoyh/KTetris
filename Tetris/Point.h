#pragma once
class Point
{
	short	x;
	short	y;

public:
	Point();
	Point(short x, short y);
	void set_xy(short x, short y);

	inline void set_x(short x)	{ this->x = x; }
	inline void set_y(short y)	{ this->y = y; }
	inline short get_x()		{ return x; }
	inline short get_y()		{ return y; }
	inline void inc_x()	{ x++; }
	inline void inc_y() { y++; }
	inline void dec_x() { x--; }
	inline void dec_y() { y--; }
};

