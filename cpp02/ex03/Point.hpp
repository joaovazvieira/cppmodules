#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>


class Fixed;
class Point
{
	private:
		Fixed	const _x;
		Fixed	const _y;
	
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point& point);
		~Point();
		
		Point& operator=(const Point& point);

		float getX(void) const;
		float getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream& operator<<(std::ostream& out, const Point& point);

#endif