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
    std::shared_ptr<lyachko::Shape> rectangle1(new lyachko::Rectangle({{1,1},1,1}));
    std::shared_ptr<lyachko::Shape> circle2(new lyachko::Circle({9,9},2));
    std::shared_ptr<lyachko::Shape> rectangle3(new lyachko::Rectangle({{1,1},2,2}));
    std::shared_ptr<lyachko::Shape> circle4(new lyachko::Circle({-9,-9},2));
    std::shared_ptr<lyachko::Shape> circle5(new lyachko::Circle({1,1},2));

    lyachko::CompositeShape compositeshape;
    std::shared_ptr<lyachko::Matrix> matrix;
    std::shared_ptr<lyachko::Matrix> matrix2;
    lyachko::CompositeShape compositeshape1(circle2);
    std::shared_ptr<lyachko::Shape> compositeshape2(new lyachko::CompositeShape(compositeshape1));

    compositeshape.add(rectangle1);
    compositeshape.add(compositeshape2);
    compositeshape.add(rectangle3);
    compositeshape.add(circle4);


    matrix = compositeshape.getMatrix();
    matrix2 = matrix;
    matrix2->info();

    std::cout << " Adding element to the 3rd layer " << std::endl;

    matrix2->addElement(circle5);
    matrix2->info();

  } catch ( std::invalid_argument & smth ) 
  {
    std::cerr  <<  smth.what()  <<  std::endl;
    return 1; 
  }
  return 0;
}
