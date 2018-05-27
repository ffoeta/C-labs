#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include "shape.hpp"
#include <memory>
#include "matrix.hpp"

namespace lyachko
{

  class CompositeShape : public Shape
  {

  public:

    CompositeShape();
    CompositeShape( const std::shared_ptr<Shape> &shape );
    CompositeShape( const CompositeShape & new_cmp );
    CompositeShape( CompositeShape && new_cmp );

    CompositeShape & operator=( const CompositeShape & new_cmp );
    CompositeShape & operator=( CompositeShape && new_cmp );

    virtual double getArea() const noexcept override;
    virtual rectangle_t getFrameRect() const noexcept override;
    virtual void move( const point_t & new_center ) noexcept override;
    virtual void move( double dx, double dy ) noexcept override;
    virtual void scale(double scale_coef ) override;
    virtual void rotate(double angle ) override;
    std::shared_ptr<Matrix> getMatrix() const;
    std::shared_ptr<Shape> operator[]( const size_t index ) const;

    void remove( size_t index );
    void add( const std::shared_ptr<Shape> & shape );
    void add( const CompositeShape & shape );

  private:

    std::unique_ptr <std::shared_ptr<Shape>[]> shapelist_;
    size_t size_;

  };

}

#endif 
