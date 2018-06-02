#include <math.h>
#include <stdexcept>
#include "circle.hpp"


Circle::Circle( const point_t & new_center, double new_r ): 
 center_( new_center ), 
 r_( new_r )
{ 
  if ( r_ < 0.0 ) 
  {
    throw std::invalid_argument( "Circle::Atempt to initialize Circle with R < 0. Abort." );
  }
}

double Circle::getArea() const
{
  return double( M_PI * r_ * r_ );
}

rectangle_t Circle::getFrameRect() const
{
  return { center_, r_ * 2, r_ * 2 };
}

void Circle::move( double dx, double dy )
{
  center_.x += dx;
  center_.y += dy;
}

void Circle::move( const point_t & new_center )
{
  center_ = new_center;
}
