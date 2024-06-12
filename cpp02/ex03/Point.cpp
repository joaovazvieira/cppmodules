#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point& point) : _x(point._x), _y(point._y) {}

Point::~Point() {}

Point& Point::operator=(const Point& point)
{
	(void) point;
	return *this;
}

float Point::getX() const
{
	return _x.toFloat();
}

float Point::getY() const
{
	return _y.toFloat();
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "Point(" << point.getX() << ", " << point.getY() << ")";
	return out;
}
