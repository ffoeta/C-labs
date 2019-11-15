#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>
#include "shape.hpp"

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
    std::shared_ptr<lyachko::Shape>  * operator [] ( const size_t index ) const;
    void info() const noexcept;
    void addElement( const std::shared_ptr<Shape> & shape );

  private:
    
    std::unique_ptr< std::shared_ptr<lyachko::Shape> [] > layers_;
    size_t lsize_;
    size_t nlayers_;

  };
}

#endif
