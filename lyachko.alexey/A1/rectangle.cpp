#include "rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(const rectangle_t & set_center_coord_and_size) : m_center_coord_and_size(set_center_coord_and_size)
{
  if (m_center_coord_and_size.width <= 0.0) 
  {
    std::cerr << "Width must be greater than 0" << std::endl;
    m_center_coord_and_size.width = 0.0;
  };
  if (m_center_coord_and_size.height <= 0.0)
  {
    std::cerr << "Height must be greater than 0" << std::endl;
    m_center_coord_and_size.height = 0.0;
  }
}

double Rectangle::getArea() const
{
  return m_center_coord_and_size.width * m_center_coord_and_size.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return m_center_coord_and_size;
}

void Rectangle::move(double dx, double dy)
{
  m_center_coord_and_size.pos.x += dx;
  m_center_coord_and_size.pos.y += dy;
}

void Rectangle::move(const point_t & new_cord)
{
  m_center_coord_and_size.pos = new_cord;
}
