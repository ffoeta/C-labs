#include "composite-shape.hpp"
#include <stdexcept>
#include <cmath>
namespace lyachko
{

  CompositeShape::CompositeShape() : 
   shapelist_( new std::shared_ptr<Shape>[0]), size_(0)
  {
  }

  CompositeShape::CompositeShape( const std::shared_ptr<Shape> &shape ) : 
   size_( 0 )
  {
    if ( shape == nullptr )
    {
      throw std::invalid_argument( "Trying to create CompositeShape through nullptr" );
    }
    shapelist_.reset( new std::shared_ptr<Shape>[1]);
    shapelist_[0] = shape;
    size_ = 1;
  }

  CompositeShape::CompositeShape( const CompositeShape & new_cmp ) :
   size_( new_cmp.size_ )
  {
    std::unique_ptr <std::shared_ptr<Shape>[]> temp__(new std::shared_ptr<Shape>[size_]);
    for ( size_t i = 0; i < size_; i++ )
    {
      temp__[i] = new_cmp.shapelist_[i];
    }
    shapelist_.swap(temp__);
  }

  CompositeShape::CompositeShape( CompositeShape && new_cmp ) :
   shapelist_( std::move( new_cmp.shapelist_ ) ),
  size_( new_cmp.size_ )
  {
    new_cmp.size_ = 0;
  }


  CompositeShape & CompositeShape::operator=(const CompositeShape & new_cmp)
  {
    if( this == &new_cmp )
    {
      return * this;
    }
    size_ = new_cmp.size_;
    std::unique_ptr <std::shared_ptr<Shape>[]> temp__(new std::shared_ptr<Shape>[size_]);
    for ( size_t i = 0; i < size_; i++ )
    {
      temp__[i] = new_cmp.shapelist_[i];
    }
    shapelist_.swap(temp__);
    return * this;
  }

  CompositeShape & CompositeShape::operator=( CompositeShape && new_cmp )
  {
    shapelist_ = std::move( new_cmp.shapelist_ );
    size_ = new_cmp.size_;
    new_cmp.size_ = 0;
    return *this;
  }


  void CompositeShape::add( const std::shared_ptr<Shape> & shape )
  {
    if ( shape == nullptr )
    {
      throw std::invalid_argument( "Trying to add nullptr to CompositeShape" );
    }
    
    std::unique_ptr <std::shared_ptr<Shape>[]> temp__(new std::shared_ptr<Shape>[size_ + 1]);
  
    for (size_t i = 0; i < size_; i++)
    {
      temp__[i] = shapelist_[i];
    }
    
    temp__[size_] = shape;
    size_++;
    shapelist_.swap(temp__);
  }

  double CompositeShape::getArea() const noexcept
  {
    double area = 0.0;
    for ( size_t i = 0; i < size_; i++ )
    {
      area += shapelist_[i]->getArea();
    }
    return area;
  }

  rectangle_t CompositeShape::getFrameRect() const noexcept
  { 
    double xleft = shapelist_[0]->getFrameRect().pos.x - shapelist_[0]->getFrameRect().width/2;
    double xright = shapelist_[0]->getFrameRect().pos.x + shapelist_[0]->getFrameRect().width/2;
    double ytop = shapelist_[0]->getFrameRect().pos.x + shapelist_[0]->getFrameRect().height/2;
    double ybottom = shapelist_[0]->getFrameRect().pos.x - shapelist_[0]->getFrameRect().height/2;

    for ( size_t i = 0; i < size_; i++ )
    {
      xright = std::fmax( xright, shapelist_[i]->getFrameRect().pos.x + shapelist_[i]->getFrameRect().width/2 );
      xleft = std::fmin( xleft, shapelist_[i]->getFrameRect().pos.x - shapelist_[i]->getFrameRect().width/2 );
      ytop = std::fmax( ytop, shapelist_[i]->getFrameRect().pos.y + shapelist_[i]->getFrameRect().height/2 );
      ybottom = std::fmin( ybottom, shapelist_[i]->getFrameRect().pos.y - shapelist_[i]->getFrameRect().height/2 );
    }

    return { { xleft + ( xright - xleft )/2 , ybottom + ( ytop - ybottom )/2 }, ( xright - xleft ), ( ytop - ybottom ) };
  }

  void CompositeShape::move( const lyachko::point_t & new_center ) noexcept
  {
    int dx = new_center.x - getFrameRect().pos.x;
    int dy = new_center.y - getFrameRect().pos.y;

    for ( size_t i = 0; i < size_; i++ )
    {
      shapelist_[i]->move( dx, dy );
    }
  }

  void CompositeShape::move( double dx, double dy ) noexcept
  {
    for ( size_t i = 0; i < size_; i++ )
    {
      shapelist_[i]->move( dx, dy );
    }
  }

  void CompositeShape::scale( double scale_coef ) 
  {
    if ( scale_coef < 0.0 )
    {
      throw std::invalid_argument( "scale_coeff mustn't be lower than 0" );
    }

    double x0 = getFrameRect().pos.x;
    double y0 = getFrameRect().pos.y;

    for ( size_t i = 0; i < size_; i++ )
    {
      double new_x = 0.0;
      double new_y = 0.0;

      if ( shapelist_[i]->getFrameRect().pos.x > x0 )
      {
        new_x = x0 + abs( ( shapelist_[i]->getFrameRect().pos.x -  x0 ) * scale_coef );
      }else if ( shapelist_[i]->getFrameRect().pos.x < x0 )
      {
        new_x = x0 - abs( ( shapelist_[i]->getFrameRect().pos.x -  x0 ) * scale_coef );
      }

      if ( shapelist_[i]->getFrameRect().pos.y > y0 )
      {
        new_y = y0 + abs( ( shapelist_[i]->getFrameRect().pos.y -  y0 ) * scale_coef );
      }else if ( shapelist_[i]->getFrameRect().pos.y < y0 )
      {
        new_y = y0 - abs( ( shapelist_[i]->getFrameRect().pos.y -  y0 ) * scale_coef );
      }

      if ( (x0 != shapelist_[i]->getFrameRect().pos.x) && (y0 != shapelist_[i]->getFrameRect().pos.y) )
      {
        shapelist_[i]->move( { new_x, new_y } );
      }
      shapelist_[i]->scale( scale_coef ); 
    }
  }

  void CompositeShape::remove( size_t index )
  {
    if ( ( index > size_ ) || ( index <= 0 ) )
    {
      throw std::invalid_argument( "No such index" );
    }
    if ( size_ == 0 )
    {
      throw std::invalid_argument( "No elements to delete" );
    }
    std::unique_ptr <std::shared_ptr<Shape>[]> temp__(new std::shared_ptr<Shape>[size_ - 1]);
    for ( size_t i = 0; i < index-1; i++ )
    {
      temp__[i] = shapelist_[i];
    }
    for ( size_t i = index; i<size_; i++ )
    {
      temp__[i - 1] = shapelist_[i];
    }
    shapelist_.swap( temp__ );
    size_--;
  }

  void CompositeShape::rotate( double angle )
  {
    double x_new;
    double y_new;
    double temp_x, temp_y;
    double x0 = getFrameRect().pos.x;
    double y0 = getFrameRect().pos.y;

    for ( size_t i = 0; i < size_; i++ )
    {
      temp_x = shapelist_[i]->getFrameRect().pos.x;
      temp_y = shapelist_[i]->getFrameRect().pos.y;
      x_new = x0 + ( ( temp_x - x0 ) * cos( angle*M_PI/180 ) - ( temp_y - y0 ) * sin( angle*M_PI/180 ) );
      y_new = y0 + ( ( temp_x - x0 ) * sin( angle*M_PI/180 ) + ( temp_y - y0 ) * cos( angle*M_PI/180 ) );
      shapelist_[i]->move( { x_new, y_new } );
      shapelist_[i]->rotate( angle );
    }
  }
  std::shared_ptr<Matrix> CompositeShape::getMatrix()
  {
    std::unique_ptr <std::shared_ptr<Shape>[]> temp__( new std::shared_ptr<Shape>[size_ + 1] );
    for ( size_t i = 0; i < size_; i++ )
    {
      temp__[i] = shapelist_[i];
    }
    std::shared_ptr<Matrix> tempm__( new Matrix(temp__,size_) );
    
    return tempm__;
  }
}
