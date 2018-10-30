#ifndef TEXT_HPP
#define TEXT_HPP

#include <list>
#include <memory>
#include <vector>
#include "lib.hpp"

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
