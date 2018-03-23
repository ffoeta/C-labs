#include "circle.hpp"
#include <math.h>

Circle::Circle(const point_t & set_coord, double set_r): m_coord(set_coord), m_r(set_r)
{}

double Circle::getArea() const
{   
  return double(M_PI * m_r * m_r);
}

rectangle_t Circle::getFrameRect() const
{
  return {m_coord, m_r * 2, m_r * 2};
}

void Circle::move(double m_x, double m_y)
{
  m_coord.x += m_x;
  m_coord.y += m_y;
}

void Circle::move(const point_t & new_coord)
{
  m_coord = new_coord;
}
