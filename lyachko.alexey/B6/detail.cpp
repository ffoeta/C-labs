#include "detail.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iterator>

std::istream &operator>>(std::istream &istream, Point &point)
{
  istream.ignore(std::numeric_limits<std::streamsize>::max(), '(');
  istream >> point.x;
  istream.ignore(std::numeric_limits<std::streamsize>::max(), ';');
  istream >> point.y;
  istream.ignore(std::numeric_limits<std::streamsize>::max(), ')');
  return istream;
}

std::istream &operator>>(std::istream &istream, Shape &shape)
{
  shape.clear();

  std::string line;
  while (std::getline(istream, line)){
    if (std::find_if(line.begin(), line.end(), [] (const char &c){return !std::isspace(c);}) != line.end())
      break;
  }
  if (!istream)
    return istream;
  std::stringstream input(line);
  size_t n;
  input >> n;
  std::copy_n(std::istream_iterator<Point>{input}, n, std::back_inserter(shape));
  if (input.fail() || std::find_if(std::istream_iterator<char>{input}, std::istream_iterator<char>{},
      [] (const char &c){return !std::isspace(c);}) != std::istream_iterator<char>{})
        istream.setstate(std::ios_base::failbit);
  return istream;
}

std::ostream &operator<<(std::ostream &ostream, const Point &point)
{
  return ostream << "(" << point.x << ";" << point.y << ")";
}

std::ostream &operator<<(std::ostream &ostream, const Shape &shape)
{
  ostream << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(ostream, " "));
  ostream << std::endl;
  return ostream;
}

bool isSquare(const Shape& shape)
{
  if (shape.size() != 4)
    return false;  
  if ((shape[1].x != shape[0].x && std::abs(shape[1].x - shape[0].x) != std::abs(shape[2].y - shape[1].y))
      || (shape[1].x == shape[0].x && std::abs(shape[2].x - shape[1].x) != std::abs(shape[1].y - shape[0].y)))
    return false;
  return true;
}

bool triangle(const Shape &shape, size_t n)
{
  size_t distSum = 0, hyp = 0;
  for (size_t i = 0; i < shape.size(); ++i) {
    if (i == n)
      continue;
    size_t sqDist = static_cast<size_t>(pow((shape[n].x - shape[i].x),2) + pow((shape[n].y - shape[i].y),2));
    distSum += sqDist;
    hyp = std::max(hyp, sqDist);
  }
  if (distSum - hyp == hyp)
    return true;
  return false;
}

bool isRectangle(const Shape &shape)
{
  if (shape.size() != 4)
    return false;
  for (size_t i = 0; i < shape.size(); i++) {
    if (!triangle(shape, i))
      return false;
  }
  return true;
}
