#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t & set_coord, double set_r);
  virtual ~Circle() = default;
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect()  const override;
  virtual void move(const point_t & new_coord) override;
  virtual void move(double dx, double dy) override;
private:
    point_t m_coord;
    double m_r;
};

#endif
