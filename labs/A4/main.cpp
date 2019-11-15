#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"

int main()
{

  try
  {
    std::shared_ptr<lyachko::Shape> rectangle1(new lyachko::Rectangle( { { 1, 1 }, 6, 6 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2(new lyachko::Rectangle( { { 1, 1 }, 2, 2 } ) );
    std::shared_ptr<lyachko::Shape> rectangle3(new lyachko::Rectangle( { { 1, 1 }, 1, 1 } ) );
    std::shared_ptr<lyachko::Shape> rectangle4(new lyachko::Rectangle( { { 1 , 1 }, 6, 6 }));
    std::shared_ptr<lyachko::Shape> rectangle5(new lyachko::Rectangle( { { 10 , 10 }, 1, 1 }));
    lyachko::Matrix matrix;
    lyachko::CompositeShape compositeshape;
    compositeshape.add(rectangle1);
    compositeshape.add(rectangle2);
    compositeshape.add(rectangle3);
    matrix = compositeshape.getMatrix();
    matrix.info();

    std::cout << " Should get 3 YES if added correctly: " << std::endl;

    if (matrix[0][0] == rectangle1)
    {
      std::cout<<" Rectangle 1 is added to the matrix correctly "<<std::endl;
    }

    if (matrix[1][0] == rectangle2)
    {
      std::cout<<" Rectangle 2 is added to the matrix correctly "<<std::endl;
    }

    if (matrix[2][0] == rectangle3)
    {
      std::cout<<" Rectangle 3 is added to the matrix correctly "<<std::endl;
    }

    matrix.addElement(rectangle4);
    lyachko::Matrix matrix2;
    matrix2 = matrix;
    matrix2.addElement(rectangle5);

    matrix2.info();

    std::cout << " Should get 5 YES if copied and added correctly: " << std::endl;

    if (matrix2[0][0] == rectangle1)
    {
      std::cout<<" Rectangle 1 is added to the matrix correctly "<<std::endl;
    }

    if (matrix2[1][0] == rectangle2)
    {
      std::cout<<" Rectangle 2 is added to the matrix correctly "<<std::endl;
    }

    if (matrix2[2][0] == rectangle3)
    {
      std::cout<<" Rectangle 3 is added to the matrix correctly "<<std::endl;
    }

    if (matrix2[3][0] == rectangle4)
    {
      std::cout<<" Rectangle 4 is added to the matrix correctly "<<std::endl;
    }

    if (matrix2[0][1] == rectangle5)
    {
      std::cout<<" Rectangle 5 is added to the matrix correctly "<<std::endl;
    }

    //copy constructor worked fine.


  } catch ( std::invalid_argument & smth ) 
  {
    std::cerr  <<  smth.what()  <<  std::endl;
    return 1; 
  }
  return 0;
}
