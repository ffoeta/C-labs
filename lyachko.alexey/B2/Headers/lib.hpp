#ifndef LIB_HPP
#define LIB_HPP

#include <string>
#include <list>
#include <iostream>

enum expression_type
{
  WORD,
  NUMBER,
  SIGN,
  DASH,
};

struct expression
{
  std::string expression;
  expression_type type;
};

#endif
