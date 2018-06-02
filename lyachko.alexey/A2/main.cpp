#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printCircleInfo( lyachko::Shape * const pShape )
{
    std::cout << " _____________________________________________ " << std::endl;
    std::cout << " Coordinates: " << pShape->getFrameRect().pos.x << " " << pShape->getFrameRect().pos.y << std::endl;
    std::cout << " Frame Size " << pShape->getFrameRect().width << " x " << pShape->getFrameRect().height << std::endl;
    std::cout << " Area " << pShape->getArea() << std::endl;
    std::cout << " Rectangle rescaled Area " << pShape->getArea() << std::endl;
    std::cout << " _____________________________________________ " << std::endl;
}

int main()
{ 

  try
  {

    lyachko::Circle circle1( { -5, 5 }, 5 );
    lyachko::Rectangle rectangle1( { { 5, 5 }, 10, 10 } );

    lyachko::Shape * pShape;
    pShape = &circle1;

    std::cout << " Circle: " << std::endl;
    printCircleInfo( pShape );

    pShape->move( -5.0, -5.0 );
    std::cout << " Coordinates shift by -5 -5 " << std::endl;
    printCircleInfo( pShape );

    pShape->move( 6.0, 6.0 );
    std::cout << " Coordinates moved to ( 6 6 ) " << std::endl;
    printCircleInfo( pShape );
    
    pShape = &rectangle1;
    std::cout << " Rectangle: " << std::endl;
    printCircleInfo( pShape );

    pShape->move( -5.0, -5.0 );
    std::cout << " Coordinates shift by -5 -5 " << std::endl;
    printCircleInfo( pShape );

    pShape->move( 6.0, 6.0 );
    std::cout << " Coordinates moved to ( 6 6 ) " << std::endl;
    printCircleInfo( pShape );


  } catch ( std::invalid_argument & smth )
  {
    std::cerr << smth.what() << std::endl;
    return 1;
  }

  return 0;
}
