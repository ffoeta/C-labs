#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace lyachko
{

  class Shape
  {

  public:
    
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & new_center) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double scale_coef) = 0;

  };

}
#endif
