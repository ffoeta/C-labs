#ifndef TEXT_HPP
#define TEXT_HPP

#include <list>
#include <memory>
#include <vector>
#include "expression.hpp"
#include <iostream>

const int MAX_LENGTH = 20;
const int MAX_DASH = 3;

class Text
{
public:
  Text(std::istream &is, std::ostream &os, unsigned long line_width);
  void outprint();

private:
  std::istream &input_;
  std::ostream &output_;
  std::vector<expression> vec_;
  unsigned long line_width_;
  expression getExpression(expression_type &type);
};

#endif
