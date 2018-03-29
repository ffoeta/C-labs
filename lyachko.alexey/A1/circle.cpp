#include "circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(const point_t & set_center_coord, double set_r): m_center_coord(set_center_coord), m_r(set_r)
{
	if (m_r <= 0) 
	{
		std::cout << "Radius must not be lower than 0"<<std::endl;
		exit(1);
	}
}

double Circle::getArea() const
{   
  return double(M_PI * m_r * m_r);
}

rectangle_t Circle::getFrameRect() const
{
  return {m_center_coord, m_r * 2, m_r * 2};
}

void Circle::move(double dx, double dy)
{
  m_center_coord.x += dx;
  m_center_coord.y += dy;
}

void Circle::move(const point_t & new_center_coord)
{
  m_center_coord = new_center_coord;
}
