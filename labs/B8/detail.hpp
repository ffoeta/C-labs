#ifndef DETAIL_HPP
#define DETAIL_HPP

#include "part1.hpp"
#include "part2.hpp"
#include <iostream>
#include <memory>
#include <sstream>
#include "Shape.hpp"

class Line : public std::string
{
public:
  bool containNonSpaces();
  friend std::istream &operator>>(std::istream &input, Line &line);
};

std::unique_ptr<Shape> readShape(const Line &line);

#endif
