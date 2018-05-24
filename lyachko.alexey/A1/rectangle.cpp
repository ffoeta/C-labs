#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(const rectangle_t & new_center) : 
 rectangle_(new_center)
{
  if ((rectangle_.width <= 0.0) || (rectangle_.height <= 0.0))
  {
    throw std::invalid_argument("Height and Width must be greater than 0");
  }
}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void Rectangle::move(const point_t & new_cord)
{
  rectangle_.pos = new_cord;
}
