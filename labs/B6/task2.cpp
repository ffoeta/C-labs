#include "task2.hpp"

void task2(std::istream &in, std::ostream &out)
{
  std::vector<Shape> shapes{std::istream_iterator<Shape>{in}, std::istream_iterator<Shape>{}};
  
  if (!in.eof())
    throw std::istream::failure{"Input Failed."};

  size_t vertices = std::accumulate(shapes.begin(), shapes.end(), 0,[] (size_t sum, const Shape &sh){return sum + sh.size();});
  out << "Vertices: " << vertices << std::endl;

  size_t triangles = std::count_if(shapes.begin(), shapes.end(),[] (const Shape &sh){return sh.size() == 3;});
  out << "Triangles: " << triangles << std::endl;

  size_t squares = std::count_if(shapes.begin(), shapes.end(), isSquare);
  out << "Squares: " << squares << std::endl;

  size_t rectangles = std::count_if(shapes.begin(), shapes.end(), isRectangle);
  out << "Rectangles: " << rectangles << std::endl;

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),[] (const Shape &sh){return sh.size() == 5;}), shapes.end());

  std::vector<Point> points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points),[] (const Shape &sh){return sh.front();});
  out << "Points:";

  std::copy(points.begin(), points.end(), std::ostream_iterator<Point>{out});

  auto triangleEnd = std::partition(shapes.begin(), shapes.end(),[] (const Shape &sh){return sh.size() == 3;});
  auto squareEnd = std::partition(triangleEnd, shapes.end(), isSquare);
  
  std::partition(squareEnd, shapes.end(), isRectangle);

  out << std::endl << "Shapes:" << std::endl;
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>{out});
}
