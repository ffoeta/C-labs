#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "./Handler.hpp"

namespace InputHandler
{
  std::string readName(std::istream &input);
  std::string readNumber(std::istream &input);
  std::string readMarkName(std::istream &input);

  void addEntry(std::istream& input, Handler &manager);
  void remove(std::istream& input, Handler &manager);
  void show(std::istream& input, Handler &manager);
  void insert(std::istream& input, Handler &manager);
  void store(std::istream& input, Handler &manager);
  void move(std::istream& input, Handler &manager);
};

#endif // INPUT_HANDLER_HPP

