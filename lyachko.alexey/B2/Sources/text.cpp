#include "../Headers/text.hpp"

void printvec(std::vector<expression> &v, std::ostream &os)
{
  for (auto elem : v)
    os << elem.expression;
  os << std::endl;
}

int rework (std::vector<expression> &line, std::ostream &os)
{
  std::size_t width = 0;
  std::vector<expression>reworked;
  while (!line.empty())
  {
    reworked.insert(reworked.begin(),line.back());
    width += line.back().expression.length();
    line.pop_back();
    if (reworked.front().type == expression_type::WORD || reworked.front().type == expression_type::NUMBER)
      break;
  }
  printvec(line, os);
  line = reworked;
  return width;
}

expression Text::getExpression(expression_type &type)
{
  expression result = { "", type };
  char temp;

  if (type == expression_type::WORD)
  {
    do
    {
      temp = input_.get();
      if (temp == '-' && input_.peek() == '-') {
        input_.unget();
        break;
      }
      result.expression += temp;
    } while (std::isalpha(input_.peek()) || (input_.peek() == '-'));
  }else if (type == expression_type::NUMBER)
  {
    do
    {
      temp = input_.get();
      if (temp == '-' && input_.peek() == '-') {
        input_.unget();
        break;
      }
      result.expression += temp;
    } while (std::isdigit(input_.peek()) || (input_.peek() == '.'));
  }else if (type == expression_type::DASH)
  {
    do
    {
      temp = input_.get();
      result.expression += temp;
    } while (input_.peek() == '-');
  }
  return result;
}

Text::Text(std::istream &is, std::ostream &os, unsigned long line_width) :
  input_(is), output_(os), line_width_(line_width)
{

  while (input_)
  {
    char temp = input_.get();
    while (std::isspace(temp))
      temp = input_.get();
    if (isalpha(temp)) {
      input_.unget();
      expression_type temp_expression_type = expression_type::WORD;
      vec_.push_back(getExpression(temp_expression_type));
    }
    else if (temp == '-') {
      if (input_.peek() == '-') {
        input_.unget();
        expression_type temp_expression_type = expression_type::DASH;
        vec_.push_back(getExpression(temp_expression_type));
      }
      else {
        input_.unget();
        expression_type temp_expression_type = expression_type::NUMBER;
        vec_.push_back(getExpression(temp_expression_type));
      }
    }
    else if (temp == '+' || isdigit(temp)) {
      input_.unget();
      expression_type temp_expression_type = expression_type::NUMBER;
      vec_.push_back(getExpression(temp_expression_type));
    }
    else if (ispunct(temp)) {
      expression temp_expression{ "", expression_type::SIGN };
      temp_expression.expression += temp;
      vec_.push_back(temp_expression);
    }
  };

  if(!vec_.empty() && (vec_.front().type != expression_type::WORD) && (vec_.front().type != expression_type::NUMBER))
    throw std::invalid_argument("Error: \n Input failed at start.");

  for(auto it = vec_.begin(); it != vec_.end(); it++) {
    expression prev = vec_.front();
    switch(it->type) {
    case expression_type::WORD:
      if (it->expression.length() > 20)
        throw std::invalid_argument("Error: \n Input failed: word exeeds 20 symbols.");
      break;
    case expression_type::NUMBER:
      if (it->expression.length() > 20)
        throw std::invalid_argument("Error: \n Input failed: number exeeds 20 symbols.");
      break;
    case expression_type::DASH:
      if(it->expression.length() != 3)
        throw std::invalid_argument("Error: \n Input failed: dash length isnt 3");
      prev = *std::prev(it);
      if((prev.type == expression_type::DASH) || ((prev.type == expression_type::SIGN) && (prev.expression != ",")))
        throw std::invalid_argument("Error: \n Input failed. Sign followed a sign.");
      break;
    case expression_type::SIGN:
      prev = *std::prev(it);
      if((prev.type == expression_type::DASH) || (prev.type == expression_type::SIGN))
        throw std::invalid_argument("Error: \n Input failed. Dash followed a sign.");
      break;
    }
  }
}

void Text::outprint()
{

  std::size_t currentWidth = 0;
  std::vector<expression> line;
  for (auto it = vec_.begin(); it != vec_.end(); it++) {
    switch(it->type) {
    case expression_type::SIGN:
      if(currentWidth + 1 > line_width_)
        currentWidth = rework(line, output_);

      line.push_back(*it);
      currentWidth += it->expression.length();
      break;

    case expression_type::DASH:
      if(currentWidth + 4 > line_width_)
        currentWidth = rework(line, output_);

      line.back().expression += " ";
      line.push_back(*it);
      currentWidth += it->expression.length() + 1;
      break;

    case expression_type::WORD:
    case expression_type::NUMBER:
      if(currentWidth + it->expression.length() + 1 > line_width_) {
        printvec(line, output_);
        line.clear();
        currentWidth = 0;
      }
      else if(!line.empty()) {
        line.back().expression += " ";
        currentWidth++;
      }
      line.push_back(*it);
      currentWidth += it->expression.length();
      break;
    }

  }
  if(!line.empty())
    printvec(line, output_);
}
