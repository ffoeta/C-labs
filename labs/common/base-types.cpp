#include <base-types.hpp>
#include <cmath>

namespace lyachko
{
  bool rectangle_t::cross( const rectangle_t & rectangle )
  {
    bool result = false;
    bool closex__ = false;
    bool closey__ = false;

    if ( std::abs( this->pos.x - rectangle.pos.x ) <= ( this->width/2 + rectangle.width/2 ) )
    {
      closex__ = true;
    }

    if ( std::abs( this->pos.y - rectangle.pos.y ) <= ( this->height/2 + rectangle.height/2 ) )
    {
      closey__ = true;
    }
    
    if ( ( closey__ ) && ( closex__ ) ) 
    {
      result = true;
    }

    return result;
  }
}
