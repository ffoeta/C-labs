#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>

namespace lyachko
{

  Rectangle::Rectangle(const rectangle_t & new_center) : 
   rectangle_(new_center), angle_( 0 )
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
    double x[4];
    double y[4];
    double x_new[4];
    double y_new[4];
    double x_min, y_min, x_max, y_max,x0,y0;

    x0 = rectangle_.pos.x;
    y0 = rectangle_.pos.y;

    x[0] = rectangle_.pos.x - rectangle_.width/2;
    y[0] = rectangle_.pos.y + rectangle_.height/2;
    x[1] = rectangle_.pos.x + rectangle_.width/2;
    y[1] = rectangle_.pos.y + rectangle_.height/2;
    x[2] = rectangle_.pos.x - rectangle_.width/2;
    y[2] = rectangle_.pos.y - rectangle_.height/2;
    x[3] = rectangle_.pos.x + rectangle_.width/2;
    y[3] = rectangle_.pos.y - rectangle_.height/2;

    x_new[0] = x0 + ((x[0] - x0) * cos(angle_*M_PI/180) - (y[0] - y0) * sin(angle_*M_PI/180));
    y_new[0] = y0 + ((x[0] - x0) * sin(angle_*M_PI/180) + (y[0] - y0) * cos(angle_*M_PI/180));

    x_max = x_new[0];
    x_min = x_new[0];
    y_max = y_new[0];
    y_min = y_new[0];

    for ( int i = 1; i < 4; i++ )
    {
      x_new[i] = x0 + ((x[i] - x0) * cos(angle_*M_PI/180) - (y[i] - y0) * sin(angle_*M_PI/180));
      y_new[i] = y0 + ((x[i] - x0) * sin(angle_*M_PI/180) + (y[i] - y0) * cos(angle_*M_PI/180));

      x_max = std::fmax(x_max,x_new[i]);
      x_min = std::fmin(x_min,x_new[i]);
      y_max = std::fmax(y_max,y_new[i]);
      y_min = std::fmin(y_min,y_new[i]);
    }

    return { { x_min + ( x_max - x_min )/2 , y_min + ( y_max - y_min )/2 } , x_max - x_min, y_max - y_min };
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

  void Rectangle::scale(double scale_coef)
  {
    if (scale_coef < 0.0)
    {
      throw std::invalid_argument("Scale coef must be greater than or even 0");
    }
    rectangle_.height *= scale_coef;
    rectangle_.width *= scale_coef;
  }

  void Rectangle::rotate(double angle)
  {
    angle_ += angle;
  }

}
