#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "shape.hpp"
#include <memory>

namespace lyachko
{
  class Matrix
  {
  public:

    Matrix();
    Matrix( const std::unique_ptr <std::shared_ptr<Shape>[]> & rawlist, size_t size );
    Matrix( const Matrix & matrix );
    Matrix( Matrix && matrix );
    Matrix & operator=( const Matrix & matrix );
    Matrix & operator=( Matrix && matrix );
    void info() const noexcept;
    size_t infolayers() const noexcept;
    size_t infomaxsize() const noexcept;

  private:
    
    std::unique_ptr< std::shared_ptr<Shape>[] > layers_;
    size_t lsize_;
    size_t nlayers_;

  };
}

#endif
