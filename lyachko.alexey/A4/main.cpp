#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"

int main()
{

  try
  {
    std::shared_ptr<lyachko::Shape> rectangle1(new lyachko::Rectangle({{1,1},2,2}));
    std::shared_ptr<lyachko::Shape> rectangle2(new lyachko::Rectangle({{2,2},2,2}));
    std::shared_ptr<lyachko::Shape> rectangle3(new lyachko::Rectangle({{9,9},2,2}));
    std::shared_ptr<lyachko::Shape> rectangle4(new lyachko::Rectangle({{1,1},2,2}));

    lyachko::CompositeShape compositeshape;
    std::shared_ptr<lyachko::Matrix> matrix;

    compositeshape.add(rectangle1);
    compositeshape.add(rectangle2); 
    compositeshape.add(rectangle3); 
    compositeshape.add(rectangle4); 

    std::cout<<compositeshape.getFrameRect().width<<std::endl;
    std::cout<<compositeshape.getFrameRect().height<<std::endl;

    matrix = compositeshape.getMatrix(); //matrix is ok
    matrix->info();

    compositeshape.rotate(45);

    matrix = compositeshape.getMatrix(); //matrix is ok
    matrix->info();

    std::cout<<compositeshape.getFrameRect().width<<std::endl;
    std::cout<<compositeshape.getFrameRect().height<<std::endl; //rotarion is ok
    compositeshape.rotate(-45);
    std::cout<<compositeshape.getFrameRect().width<<std::endl; //rotation is ok
    std::cout<<compositeshape.getFrameRect().height<<std::endl;

  } catch ( std::invalid_argument & smth ) 
  {
    std::cerr << smth.what() << std::endl;
    return 1; 
  }
  return 0;
}
