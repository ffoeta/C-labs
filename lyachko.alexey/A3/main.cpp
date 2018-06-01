#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include <memory>

int main()
{

  try
  {
    std::cout << " Creating compositeshape based on rectangle1 " << std::endl;
    auto rectangle1 = std::shared_ptr<lyachko::Shape>(new lyachko::Rectangle({{1,1},2,2}));
    auto rectangle2 = std::shared_ptr<lyachko::Shape>(new lyachko::Rectangle({{3,3},2,2}));

    lyachko::CompositeShape compositeshape( rectangle1 );

    std::cout << " CompositeShape's x " << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << " CompositeShape's y " << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << " CompositeShape's width " << compositeshape.getFrameRect().width << std::endl;
    std::cout << " CompositeShape's height " << compositeshape.getFrameRect().height << std::endl;

    compositeshape.add( rectangle2 );

    std::cout << " Adding Rectagnle2 to compositeshape " << std::endl;

    std::cout << " CompositeShape's x "  << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << " CompositeShape's y " << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << " CompositeShape's width " << compositeshape.getFrameRect().width << std::endl;
    std::cout << " CompositeShape's height " << compositeshape.getFrameRect().height << std::endl;

    compositeshape.move( { 10, 10 } );

    std::cout << " Moving to 10; 10 " << std::endl;

    std::cout << " CompositeShape's x " << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << " CompositeShape's y " << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << " CompositeShape's width " << compositeshape.getFrameRect().width << std::endl;
    std::cout << " CompositeShape's height " << compositeshape.getFrameRect().height << std::endl;

    compositeshape.move( -1, 1 );

    std::cout << " Shifting by -1, 1 " << std::endl;

    std::cout << " CompositeShape's x " << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << " CompositeShape's y " << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << " CompositeShape's width " << compositeshape.getFrameRect().width << std::endl;
    std::cout << " CompositeShape's height " << compositeshape.getFrameRect().height << std::endl;

    compositeshape.remove(1);

    std::cout << " Removing first element " << std::endl;

    std::cout << " CompositeShape's x " << compositeshape.getFrameRect().pos.x << std::endl;
    std::cout << " CompositeShape's y " << compositeshape.getFrameRect().pos.y << std::endl;
    std::cout << " CompositeShape's width " << compositeshape.getFrameRect().width << std::endl;
    std::cout << " CompositeShape's height " << compositeshape.getFrameRect().height << std::endl;
  
  } catch ( std::invalid_argument & smth ) 
  {
    std::cerr  <<  smth.what()  <<  std::endl;
    return 1; 
  }
  return 0;
}
