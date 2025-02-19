#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(short x, short y)
{
	set_xy(x, y);
}

void Point::set_xy(short x, short y)
{
	this->x = x;
	this->y = y;
}

