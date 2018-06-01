#include "matrix.hpp"
#include <memory>
#include <iostream>
#include <cmath>

namespace lyachko
{
  Matrix::Matrix() :
   layers_(new std::shared_ptr<Shape>[0]), lsize_(0), nlayers_(0)
  {
  }

  Matrix::Matrix( const Matrix & matrix ) :
   lsize_(matrix.lsize_), nlayers_(matrix.nlayers_)
  {
    std::unique_ptr <std::shared_ptr<Shape>[]> temp__(new std::shared_ptr<Shape>[lsize_ * nlayers_]);
    for ( size_t i = 0; i < lsize_ * nlayers_; i++ )
    {
      temp__[i] = matrix.layers_[i];
    }
    this->layers_.swap(temp__);
  }

  Matrix::Matrix( Matrix && matrix ) :
   layers_( std::move( matrix.layers_ ) ), lsize_(matrix.lsize_), nlayers_(matrix.nlayers_)
  {
    matrix.lsize_ = 0;
    matrix.nlayers_ = 0;
  }

  Matrix & Matrix::operator=( const Matrix & matrix )
  {
    if ( this == &matrix )
    {
      return * this;
    }
    std::unique_ptr <std::shared_ptr<Shape>[]> temp__(new std::shared_ptr<Shape>[lsize_ * nlayers_]);
    for ( size_t i = 0; i < lsize_ * nlayers_; i++ )
    {
      temp__[i] = matrix.layers_[i];
    }
    this->layers_.swap(temp__);

    return * this;
  }

  Matrix & Matrix::operator=( Matrix && matrix )
  {
    if ( this == &matrix )
    {
      return * this;
    }

    layers_ = std::move( matrix.layers_ );
    lsize_ = matrix.lsize_;
    nlayers_ = matrix.nlayers_;
    matrix.nlayers_ = 0;
    matrix.lsize_ = 0;

    return * this;
  }

  Matrix::Matrix( const std::unique_ptr <std::shared_ptr<Shape>[]> & rawlist, size_t size ) :
   layers_(new std::shared_ptr<Shape>[0]), lsize_(0), nlayers_(0)
  {
    if ( (rawlist == nullptr) || ( size == 0 ) )
    {
      throw std::invalid_argument( "List of new shapes mustn't be empty" );
    }

    size_t lsize__ = 0;
    size_t nlayers__ = 0;
    size_t layers__[size];
    size_t temp__[size];

    for ( size_t i = 0; i < size; i++ )
    {
      layers__[i] = 1;
    }

    for ( size_t i = 1; i < size; i++ )
    {
      for ( size_t j = 0; j < i; j++ )
      {
        if ( rawlist[i]->getFrameRect().cross(rawlist[j]->getFrameRect()) )
        {
            if (layers__[i] <= layers__[j])
            {
              layers__[i] = layers__[j]+1; 
            } 
        }
      }
    }

    for ( size_t i = 0; i < size; i++ )
    {
      nlayers__ = std::fmax(nlayers__,layers__[i]);
    }

    for ( size_t i = 0; i < size; i++ )
    {
      temp__[i] = 0;
    }

    for ( size_t i = 0; i < size; i++ )
    {
      for ( size_t j = 0; j < size; j++ )
      {
        if ( (i+1) == layers__[j] )
        {
          temp__[i]++;
        }
      }
    }

    for ( size_t i = 0; i < size; i++ )
    {
      lsize__ = std::fmax(lsize__,temp__[i]);
    }

    lsize_ = lsize__;
    nlayers_ = nlayers__;

    std::unique_ptr <std::shared_ptr<Shape>[]> temp___(new std::shared_ptr<Shape>[lsize_ * nlayers_]);
    layers_.swap(temp___);


    for ( size_t i = 0; i < lsize_*nlayers_; i++ )
    {
      layers_[i] = nullptr;
    }

    layers_[0] = rawlist[0];

    size_t layersfilled_[nlayers_+1];

    for ( size_t i = 0; i <= nlayers_; i++ )
    {
      layersfilled_[i] = 1;
    }

    for ( size_t i = 1; i < size; i++ )
    {
      if (layers_[layers__[i] * lsize_ - lsize_] == nullptr)
      {
        layers_[layers__[i] * lsize_ - lsize_] = rawlist[i];
      } else
      {
        layers_[( layers__[i] - 1 ) * lsize_ + layersfilled_[layers__[i]]] = rawlist[i];
        layersfilled_[layers__[i]]++;
      }
    }

  }
  
  void Matrix::info() const noexcept
  {

    std::cout << std::endl;
    std::cout << "Layers: " << nlayers_ << std::endl;
    std::cout << "Max size: " << lsize_ << std::endl;

    for ( size_t i = 0; i < lsize_*nlayers_; i++ )
    {
      if ((layers_[i] == nullptr))
      {
        std::cout << "* ";
      }else
      {
        std::cout << "x ";
      }
      if ( ((i+1) % lsize_) == 0 )
      {
        std::cout << std::endl;
      }
    }
    for ( size_t i = 0; i < lsize_*2; i++ )
    {
      std::cout << '-';
    }
    std::cout << std::endl;
  }

  std::shared_ptr<lyachko::Shape> Matrix::getElement( const size_t index1, const size_t index2 ) const
  {
    if ( ( index1  > nlayers_ ) || ( index2 > lsize_ ) )
    {
      throw std::invalid_argument("index if out of range");
    }

    return layers_[lsize_*index1 - (lsize_ - index2) - 1];
  }

  void Matrix::addElement( const std::shared_ptr<Shape> & shape )
  {
    size_t counter_ = 0;
    size_t counter__ = 0;
    for (size_t i = 0; i < lsize_ * nlayers_; i ++ )
    {
      if ( layers_[i] != nullptr ) 
      {
        counter_ ++;
      }
    }

    std::unique_ptr <std::shared_ptr<Shape>[]> temp_(new std::shared_ptr<Shape>[counter_ + 1]);

    for (size_t i = 0; i < lsize_ * nlayers_; i ++ )
    {
      if ( layers_[i] != nullptr ) 
      {
        temp_[counter__] = layers_[i];
        counter__++;
      }
    }
    temp_[counter_] = shape;
    Matrix matrix_(temp_,counter_ + 1);
    this->layers_.swap(matrix_.layers_);
    this->lsize_ = matrix_.lsize_;
    this->nlayers_ = matrix_.nlayers_;
  }

}
