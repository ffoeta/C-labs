#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include <memory>

int main()
{

  try
  {

    auto rectangle1 = std::shared_ptr<lyachko::Shape>(new lyachko::Rectangle({{1,1},2,2}));
    auto rectangle2 = std::shared_ptr<lyachko::Shape>(new lyachko::Rectangle({{3,3},2,2}));

    lyachko::CompositeShape compositeshape( rectangle1 );

    compositeshape.add( rectangle2 );

    std::cout << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << compositeshape.getFrameRect().width << std::endl;
    std::cout << compositeshape.getFrameRect().height << std::endl;

    compositeshape.move( { 10, 10 } );

    std::cout << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << compositeshape.getFrameRect().width << std::endl;
    std::cout << compositeshape.getFrameRect().height << std::endl;

    compositeshape.move( -1, 1 );

    std::cout << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << compositeshape.getFrameRect().width << std::endl;
    std::cout << compositeshape.getFrameRect().height << std::endl;

  
  } catch ( std::invalid_argument & smth ) 
  {
    std::cerr  <<  smth.what()  <<  std::endl;
    return 1; 
  }
  return 0;
}
