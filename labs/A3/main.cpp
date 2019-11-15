#include <iostream>
#include <memory>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

void printCompositeInfo( const lyachko::CompositeShape & compositeshape )
{
  std::cout << " _______________________ " << std::endl;
  std::cout << " CompositeShape's x " << compositeshape.getFrameRect().pos.x << std::endl;
  std::cout << " CompositeShape's y " << compositeshape.getFrameRect().pos.y << std::endl;
  std::cout << " CompositeShape's width " << compositeshape.getFrameRect().width << std::endl;
  std::cout << " CompositeShape's height " << compositeshape.getFrameRect().height << std::endl;
  std::cout << " _______________________ " << std::endl;
}

int main()
{

  try
  {
    std::cout << " Creating compositeshape based on rectangle1 and rectangle2 " << std::endl;
    std::shared_ptr<lyachko::Shape> rectangle1( new lyachko::Rectangle( { { 1, 1 }, 2, 2 } ) );
    std::shared_ptr<lyachko::Shape> rectangle2( new lyachko::Rectangle( { { 3, 3 }, 2, 2 } ) );

    lyachko::CompositeShape compositeshape( rectangle1 );

    printCompositeInfo( compositeshape );

    compositeshape.add( rectangle2 );

    std::cout << " Adding Rectagnle2 to compositeshape " << std::endl;

    printCompositeInfo( compositeshape );

    compositeshape.move( { 10, 10 } );

    std::cout << " Moving to 10; 10 " << std::endl;

    printCompositeInfo( compositeshape );

    compositeshape.move( -1, 1 );

    std::cout << " Shifting by -1, 1 " << std::endl;
    std::cout << " Only x and y must change " << std::endl;

    printCompositeInfo( compositeshape );

    compositeshape.remove(1);

    std::cout << " Removing first element " << std::endl;

    printCompositeInfo( compositeshape );
  
  } catch ( std::invalid_argument & smth ) 
  {
    std::cerr  <<  smth.what()  <<  std::endl;
    return 1; 
  }
  return 0;
}
