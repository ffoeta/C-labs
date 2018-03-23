#include "rectangle.hpp"

Rectangle::Rectangle(const rectangle_t & set_coord_size) : m_coord_size(set_coord_size)
{}

double Rectangle::getArea() const
{
  return m_coord_size.width * m_coord_size.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_coord_size;
}

void Rectangle::move(double dx, double dy)
{
  m_coord_size.pos.x += dx;
  m_coord_size.pos.y += dy;
}

void Rectangle::move(const point_t & new_cord)
{
  m_coord_size.pos = new_cord;
}
