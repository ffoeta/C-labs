#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

//Type to determine what point is 
struct point_t
{
  //Coordinates of the poing
  double x, y;
};

//Type to determine what rectangle is 
struct rectangle_t
{
  //Coordinates of center of the rectangle (point)
  point_t pos;

  //Rectangle's width and height
  double width, height;
};

#endif 
