#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

//Abstract class Shape, used to make others
class Shape
{

//Public methods, fucntions and variables
public:

  //Absolute virtual constructor, set to default
  virtual ~Shape() = default;

  //Absolute virtual function returning area
  virtual double getArea() const = 0;

  //Absolute virtual fucntion returning rectangle, sorrounding the object
  virtual rectangle_t getFrameRect() const = 0;

  //Absolute virtual method moving object to the new coordinates
  virtual void move(const point_t & new_center_coord) = 0;

  //Absolute virtual method, shifting coordinates
  virtual void move(double dx, double dy) = 0;

};

#endif 
