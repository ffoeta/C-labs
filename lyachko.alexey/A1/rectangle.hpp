#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const rectangle_t & set_coord_size);
  virtual ~Rectangle() = default; 
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t & new_coord) override;
  virtual void move(double dx, double dy) override;
private:
  rectangle_t m_coord_size;
};

#endif
