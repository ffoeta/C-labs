#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"

int main()
{

  try
  {
    std::cout << " Creating 4 figures to be added to composite shape and one to test matrix class " << std::endl;
    std::shared_ptr<lyachko::Shape> rectangle1(new lyachko::Rectangle( { { 1, 1 }, 6, 6 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2(new lyachko::Rectangle( { { 1, 1 }, 2, 2 } ) );
    std::shared_ptr<lyachko::Shape> rectangle3(new lyachko::Rectangle( { { 1, 1 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle4(new lyachko::Rectangle( { { 1 , 1 }, 6, 6 }));

    
    lyachko::Matrix matrix;
    lyachko::CompositeShape compositeshape;
    compositeshape.add(rectangle1);
    compositeshape.add(rectangle2);
    compositeshape.add(rectangle3);
    compositeshape.add(rectangle4);
    matrix = compositeshape.getMatrix();
    matrix.info();

    if (matrix[0][0] == rectangle1)
    {
      std::cout<<"YES"<<std::endl;
    }

    if (matrix[0][1] == rectangle2)
    {
      std::cout<<"YES"<<std::endl;
    }

    if (matrix[0][2] == rectangle3)
    {
      std::cout<<"YES"<<std::endl;
    }

    if (matrix[0][3] == rectangle4)
    {
      std::cout<<"YES"<<std::endl;
    }

    lyachko::Matrix matrix2;
    matrix2 = matrix;

    matrix2.info();

    if (matrix2[0][0] == rectangle1)
    {
      std::cout<<"YES"<<std::endl;
    }

    if (matrix2[0][1] == rectangle2)
    {
      std::cout<<"YES"<<std::endl;
    }

    if (matrix2[0][2] == rectangle3)
    {
      std::cout<<"YES"<<std::endl;
    }

    if (matrix2[0][3] == rectangle4)
    {
      std::cout<<"YES"<<std::endl;
    }

    //copy constructor worked fine.


  } catch ( std::invalid_argument & smth ) 
  {
    std::cerr  <<  smth.what()  <<  std::endl;
    return 1; 
  }
  return 0;
}
