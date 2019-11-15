#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>

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
